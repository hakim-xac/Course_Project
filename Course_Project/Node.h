#pragma once
#include "DataBase.h"
namespace KHAS {

    class Node {

    public:

        // ��������� �� ����� ������
        Node* left{ nullptr };

        // ��������� �� ������ ������
        Node* right{ nullptr };

        // ������
        DatabaseEntry data{};

        // ������� �������
        int height{};

        // ��������� �������� ������ ����
        Node() = delete;

        // ������� ���� � �������
        Node(const DatabaseEntry& value, int height = 1)
            : left(nullptr)
            , right(nullptr)
            , data(value)
            , height(height) {}

    };

}