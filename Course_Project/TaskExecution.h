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