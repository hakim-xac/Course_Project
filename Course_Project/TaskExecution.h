#pragma once
#include <fstream>
#include <vector>
#include <string>
#include "Interface.h"
#include "BinaryTree.h"
#include "DataBase.h"

namespace KHAS {

    class TaskExecution : public Interface {

        template <typename BTree>
        using isBinaryTree_t = std::enable_if_t<std::is_same_v<BTree, BinaryTree>>;

        /// <summary>
        /// массив с данными
        /// </summary>
        std::vector<DatabaseEntry> vec_db_;

        /// <summary>
        /// указатель на АВЛ дерево
        /// </summary>
        BinaryTree* avlTree_;

        /// <summary>
        /// поле данных для введеного значения "Издательство"
        /// </summary>
        std::string publishing_house_name_;

        /// <summary>
        /// поле данных для введеного значения "Автор"
        /// </summary>
        std::string lastname_author_;

    private:

        /// <summary>
        /// создает дерево из файла базы данных с адресом filename
        /// </summary>
        template <typename FileNameType>
        BinaryTree* create(FileNameType&& filename);

        /// <summary>
        /// вызывает функции по условию проекта
        /// </summary>
        void functionLaunch() override;

        /// <summary>
        /// вывод в буфер, ответ на задачу курсового проекта
        /// </summary>
        void printViewCourceTask();

        /// <summary>
        /// Преобразует данные из потока в структуру DatabaseEntry, bool - успех 
        /// </summary>
        std::pair<DatabaseEntry, bool> fromFileToDatabaseEntry(std::ifstream& in);

        /// <summary>
        /// Конвертирует поля структуры DatabaseEntry из кодировки oem866 в ANSI
        /// </summary>
        DatabaseEntry changingFieldEncoding(DatabaseEntry&& db);

        /// <summary>
        /// запрашивает у пользователя ввод данных
        /// header - текст запроса
        /// field - сохраняет в виде строки
        /// Внимание! Происходит преобразование из oem866 в ANSI
        /// </summary>
        bool readFromConsole(std::string&& header, std::string& field);

        /// <summary>
        /// выводит информацию о данных после поиска по заданым данным
        /// </summary>
        void showFindPublishingHouse();
    public:
        TaskExecution();
        ~TaskExecution();

        /// <summary>
        /// вывод доп. информации пользователю
        /// </summary>
        void showMenu() override;

    };
}

#include "TaskExecution.hpp"