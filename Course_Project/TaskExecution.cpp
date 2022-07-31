#include "TaskExecution.h"
#include <Windows.h>
#include <algorithm>
#include <vector>
#include <array>
#include <cassert>

namespace KHAS {

    bool TaskExecution::checkIsTree()
    {
        return (avlTree_ != nullptr);
    }

    void TaskExecution::functionLaunch()
    {
        //printView();
        printViewCourceTask();
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

    std::vector<DatabaseEntry> TaskExecution::uniqueDatabaseEntry(const std::vector<DatabaseEntry>& vec)
    {
        assert(vec.size() != 0);
        std::vector<DatabaseEntry> arr;
        arr.reserve(vec.size());
        for (auto&& from : vec) {
            bool is_unique{ true };
            for (auto&& to : arr) {
                if (strcmp(from.publishing_house, to.publishing_house) == 0) {
                    is_unique = false;
                    break;
                }
            }
            if (is_unique) arr.emplace_back(from);
        }
        arr.shrink_to_fit();

        return arr;
    }

    TaskExecution
        ::TaskExecution()
        : Interface()
        , vec_db_()
        , avlTree_(create("BASE1.DAT")) { 
    
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

        std::vector<DatabaseEntry> arr{ uniqueDatabaseEntry(vec_db_) };
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
        

        const int deliter{ 3 };
        for (size_t i{}, ie{ arr.size() / deliter }; i < ie + 1; ++i) {

            std::array<std::string, deliter> tmp_arr{};

            for (int j{}, je{ deliter }; j < je; ++j) {

                auto index{ i * deliter + j };
                if(index < arr.size()) tmp_arr[j] = std::string(arr[index].publishing_house);

            }
            push(bufferItem(tmp_arr[0], tmp_arr[1], tmp_arr[2]));
        }
    }

    void TaskExecution::showMenu() const
    {
        using namespace std::literals;

        // добавляет отформатированные строки в буфер
        pushToBuffer(delimiter('='));
        pushToBuffer(bufferItem("Меню"s));
        pushToBuffer(delimiter('-'));
        pushToBuffer(bufferItem("Клавиша"s, "Команда"s));
        pushToBuffer(delimiter('-'));
        pushToBuffer(bufferItem("1"s, "Распечать данные о дереве"s));
        pushToBuffer(delimiter('-'));
        pushToBuffer(bufferItem("9"s, "Закрыть приложение"s));
        pushToBuffer(delimiter('='));

        // сбрасывает на вывод в консоль
        show();
    }

}