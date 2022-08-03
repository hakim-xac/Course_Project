#include "TaskExecution.h"
#include <Windows.h>
#include <array>
#include <limits>

namespace KHAS {

    bool TaskExecution::checkIsTree()
    {
        return (avlTree_ != nullptr);
    }

    void TaskExecution::functionLaunch()
    {
        printViewCourceTask();
        findPublishingHouse();
    }

    std::pair<DatabaseEntry, bool> TaskExecution::fromFileToDatabaseEntry(std::ifstream& in)
    {
        DatabaseEntry db{};
        in >> db;
        if (in.fail()) {
            return { db, false };
        }

        return { changingFieldEncoding(std::move(db)), true };
    }

    DatabaseEntry TaskExecution::changingFieldEncoding(DatabaseEntry&& db)
    {
        DatabaseEntry db2{};
        OemToCharBuffA(db.author, db2.author, sizeof db2.author);
        OemToCharBuffA(db.header, db2.header, sizeof db2.header);
        OemToCharBuffA(db.publishing_house, db2.publishing_house, sizeof db2.publishing_house);
        db2.year = db.year;
        db2.pages_count = db.pages_count;
        return db2;
    }

    bool TaskExecution::readFromConsole(std::string&& header, std::string& field)
    {
        // добавляет отформатированные строки в буфер
        pushToBuffer(delimiter('='));
        pushToBuffer(bufferItem(header));
        pushToBuffer(delimiter('-'));
        // сбрасывает на вывод в консоль
        show();

        std::cout << std::string(getFieldWidht(), '_')
            << std::string(getFieldWidht() - 4, '\b');
        char tmp[17]{}, tmp2[17]{};

        std::cin.getline(tmp, sizeof tmp, '\n');

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            field.clear();
            return false;
        }
        OemToCharBuffA(tmp, tmp2, sizeof tmp2);
        field = tmp2;
        return true;
    }

    void TaskExecution::findPublishingHouse()
    {
        if (publishing_house_name_.empty() || lastname_author_.empty()) return;

        using namespace std::literals;

        std::vector<DatabaseEntry> arr{ avlTree_->find(publishing_house_name_, lastname_author_) };

        if (!arr.size()) {
            push(delimiter('-'));
            push(bufferItem("С текущими данными, нет результатов!"s));
            push(delimiter('-'));
            return;
        }

        push(delimiter('='));
        for (auto&& elem: arr) {
            push(bufferItem("Автор:"s, std::string(elem.author)));
            push(bufferItem("Заглавие:"s, std::string(elem.header)));
            push(bufferItem("Издательство:"s, std::string(elem.publishing_house)));
            push(bufferItem("Год издания:"s, std::to_string(elem.year)));
            push(bufferItem("Кол-во страниц:"s, std::to_string(elem.pages_count)));
            push(delimiter('-'));
        }
        push(delimiter('='));


    }

    TaskExecution
        ::TaskExecution()
        : Interface()
        , vec_db_()
        , avlTree_(create("BASE1.DAT")) 
        , publishing_house_name_()
        , lastname_author_() {
    
    }

    TaskExecution::~TaskExecution()
    {
        // очищает деревья и обнуляет указатели
        avlTree_->deleteTree();
        delete avlTree_;
        avlTree_ = nullptr;
    }

    void TaskExecution::quit() const
    {
        system("cls");
        exit(0);
    }

    void TaskExecution::printView()
    {
        print(avlTree_);
    }

    void TaskExecution::printViewCourceTask()
    {
        using namespace std::literals;

        std::vector<DatabaseEntry> arr{ avlTree_->printUnique() };

        push(delimiter('='));
        push(bufferItem("Данные о количестве и названиях всех издательств"s));
        push(delimiter('='));

        push(bufferItem("Количество уникальных издательств:"s, std::to_string(arr.size())));
        push(delimiter('='));

        if (arr.size() == 0) {
            push(bufferItem("Список издательств пуст!"s));
            return;
        }
        push(bufferItem("Список уникальных издательств"s));
        push(delimiter('-'));
        

        for (auto&& elem: arr) {
            push(bufferItem(std::string(elem.publishing_house)));
        }
    }

    void TaskExecution::showMenu()
    {
        publishing_house_name_.clear();
        lastname_author_.clear();
        if (!readFromConsole("Введите название издательства", publishing_house_name_)
            || !readFromConsole("Введите фамилию автора", lastname_author_)) {

            using namespace std::literals;

            push(bufferItem("Ошибка ввода данных!"s));
        }        
    }

}