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
        /// ������ � �������
        /// </summary>
        std::vector<DatabaseEntry> vec_db_;

        /// <summary>
        /// ��������� �� ��� ������
        /// </summary>
        BinaryTree* avlTree_;

        /// <summary>
        /// ���� ������ ��� ��������� �������� "������������"
        /// </summary>
        std::string publishing_house_name_;

        /// <summary>
        /// ���� ������ ��� ��������� �������� "�����"
        /// </summary>
        std::string lastname_author_;

    private:

        /// <summary>
        /// ������� ������ �� ����� ���� ������ � ������� filename
        /// </summary>
        template <typename FileNameType>
        BinaryTree* create(FileNameType&& filename);

        /// <summary>
        /// �������� ������� �� ������� �������
        /// </summary>
        void functionLaunch() override;

        /// <summary>
        /// ����� � �����, ����� �� ������ ��������� �������
        /// </summary>
        void printViewCourceTask();

        /// <summary>
        /// ����������� ������ �� ������ � ��������� DatabaseEntry, bool - ����� 
        /// </summary>
        std::pair<DatabaseEntry, bool> fromFileToDatabaseEntry(std::ifstream& in);

        /// <summary>
        /// ������������ ���� ��������� DatabaseEntry �� ��������� oem866 � ANSI
        /// </summary>
        DatabaseEntry changingFieldEncoding(DatabaseEntry&& db);

        /// <summary>
        /// ����������� � ������������ ���� ������
        /// header - ����� �������
        /// field - ��������� � ���� ������
        /// ��������! ���������� �������������� �� oem866 � ANSI
        /// </summary>
        bool readFromConsole(std::string&& header, std::string& field);

        /// <summary>
        /// ������� ���������� � ������ ����� ������ �� ������� ������
        /// </summary>
        void showFindPublishingHouse();
    public:
        TaskExecution();
        ~TaskExecution();

        /// <summary>
        /// ����� ���. ���������� ������������
        /// </summary>
        void showMenu() override;

    };
}

#include "TaskExecution.hpp"