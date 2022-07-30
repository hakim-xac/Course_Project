#include "TaskExecution.h"
#include <Windows.h>

namespace KHAS {

    bool TaskExecution::checkIsTree()
    {
        return (avlTree_ != nullptr);
    }

    void TaskExecution::functionLaunch()
    {

    }

    std::pair<DatabaseEntry, bool> TaskExecution::fromFileToDatabaseEntry(FILE* fn)
    {

        DatabaseEntry db{};
        if (!readFromStream(fn, db.author, sizeof(db.author) - 1)
            || !readFromStream(fn, db.header, sizeof(db.header) - 1)
            || !readFromStream(fn, db.publishing_house, sizeof(db.publishing_house) - 1)
            || !readFromStream(fn, db.year, sizeof(db.year))
            || !readFromStream(fn, db.pages_count, sizeof(db.pages_count))
            ) {
            return {db, false };
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

    TaskExecution
        ::TaskExecution()
        : Interface()
        , vec_db_()
        , avlTree_(create("BASE1.DAT")) { }

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
        BinaryTree* bt{ avlTree_ };
        print(bt);
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