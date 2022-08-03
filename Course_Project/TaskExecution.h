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

        std::vector<DatabaseEntry> vec_db_;
        BinaryTree* avlTree_;
        std::string publishing_house_name_;
        std::string lastname_author_;

    private:

        /// <summary>
        /// создает дерево с количеством элементов count_tree
        /// </summary>
        template <typename FileNameType>
        BinaryTree* create(FileNameType&& filename);

        /// <summary>
        /// проверяет на валидность созданные деревья
        /// </summary>
        bool checkIsTree();

        /// <summary>
        /// выводит, необходимый по условию задачи, результат в буфер
        /// </summary>
        template <typename BTree, typename = isBinaryTree_t<BTree>>
        void print(const BTree* const tree);

        /// <summary>
        /// считывает дерево и добовляет данные в буфер
        /// </summary>
        template <typename BTree, typename = isBinaryTree_t<BTree>>
        void showReadTree(const BTree* const tree);

        /// <summary>
        /// выполняет функцию, в зависимости от команды
        /// </summary>
        void functionLaunch() override;

        /// <summary>
        /// выходит из программы
        /// </summary>
        void quit()         const;

        /// <summary>
        /// добавляет данные о дереве в буфер
        /// </summary>
        void printView();

        /// <summary>
        /// вывод в буфер, ответ на задачу курсового проекта
        /// </summary>
        void printViewCourceTask();

        /// <summary>
        /// 
        /// </summary>
        std::pair<DatabaseEntry, bool> fromFileToDatabaseEntry(std::ifstream& in);

        /// <summary>
        /// 
        /// </summary>
        DatabaseEntry changingFieldEncoding(DatabaseEntry&& db);

        /// <summary>
        /// 
        /// </summary>
        bool readFromConsole(std::string&& header, std::string& field);

        /// <summary>
        /// 
        /// </summary>
        void findPublishingHouse();
    public:
        TaskExecution();
        ~TaskExecution();
        void showMenu() override;

    };
}

#include "TaskExecution.hpp"