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
        /// ������� ������ � ����������� ��������� count_tree
        /// </summary>
        template <typename FileNameType>
        BinaryTree* create(FileNameType&& filename);

        /// <summary>
        /// ��������� �� ���������� ��������� �������
        /// </summary>
        bool checkIsTree();

        /// <summary>
        /// �������, ����������� �� ������� ������, ��������� � �����
        /// </summary>
        template <typename BTree, typename = isBinaryTree_t<BTree>>
        void print(const BTree* const tree);

        /// <summary>
        /// ��������� ������ � ��������� ������ � �����
        /// </summary>
        template <typename BTree, typename = isBinaryTree_t<BTree>>
        void showReadTree(const BTree* const tree);

        /// <summary>
        /// ��������� �������, � ����������� �� �������
        /// </summary>
        void functionLaunch() override;

        /// <summary>
        /// ������� �� ���������
        /// </summary>
        void quit()         const;

        /// <summary>
        /// ��������� ������ � ������ � �����
        /// </summary>
        void printView();

        /// <summary>
        /// ����� � �����, ����� �� ������ ��������� �������
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
        static std::vector <DatabaseEntry> uniqueDatabaseEntry(const std::vector<DatabaseEntry>& vec);
    public:
        TaskExecution();
        ~TaskExecution();
        void showMenu() const override;

    };
}

#include "TaskExecution.hpp"