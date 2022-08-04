#pragma once
#include "DataBase.h"
namespace KHAS {

    class Node {

    public:

        // указатель на левое дерево
        Node* left{ nullptr };

        // указатель на правое дерево
        Node* right{ nullptr };

        // данные
        DatabaseEntry data{};

        // уровень баланса
        int height{};

        // запрещает создание пустой ноды
        Node() = delete;

        // создаем ноду с данными
        Node(const DatabaseEntry& value, int height = 1)
            : left(nullptr)
            , right(nullptr)
            , data(value)
            , height(height) {}

    };

}