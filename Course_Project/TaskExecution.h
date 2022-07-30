#pragma once
#include <fstream>
#include <vector>
#include "Interface.h"
#include "BinaryTree.h"
#include "Enums.h"
#include "DataBase.h"

namespace KHAS {

    class TaskExecution : public Interface {

        template <typename BTree>
        using isBinaryTree_t = std::enable_if_t<std::is_same_v<BTree, BinaryTree>>;

        std::vector<DatabaseEntry> vec_db_;
        BinaryTree* avlTree_;


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
        static void print(const BTree* const tree);

        /// <summary>
        /// считывает дерево и добовляет данные в буфер
        /// </summary>
        template <typename BTree, typename = isBinaryTree_t<BTree>>
        static void showReadTree(const BTree* const tree);

        /// <summary>
        /// считает хеш-сумму и выводит в буфер
        /// </summary>
        template <typename BTree, typename = isBinaryTree_t<BTree>>
        static void showHashTree(const BTree* const tree);

        /// <summary>
        /// считает высоту дерева и выводит в буфер
        /// </summary>
        template <typename BTree, typename = isBinaryTree_t<BTree>>
        static void showHeightTree(const BTree* const tree);

        /// <summary>
        /// считает размер дерева
        /// </summary>
        template <typename BTree, typename = isBinaryTree_t<BTree>>
        static void showSizeTree(const BTree* const tree);

        /// <summary>
        /// выводит среднюю высоту дерева
        /// </summary>
        template <typename BTree, typename = isBinaryTree_t<BTree>>
        static void showMiddleHeightTree(const BTree* const tree);

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
        /// 
        /// </summary>
        template <typename T>
        bool readFromStream(FILE* fn, T&& t, std::size_t size);

        /// <summary>
        /// 
        /// </summary>
        std::pair<DatabaseEntry, bool> fromFileToDatabaseEntry(FILE* fn);

        /// <summary>
        /// 
        /// </summary>
        DatabaseEntry changingFieldEncoding(DatabaseEntry&& db);
    public:
        TaskExecution();
        ~TaskExecution();
        void showMenu() const override;

    };
}

#include "TaskExecution.hpp"