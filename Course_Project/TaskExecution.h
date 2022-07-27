#pragma once
#include "Interface.h"
#include "BinaryTree.h"
#include "Enums.h"

namespace KHAS {

    class TaskExecution : public Interface {

        template <typename BTree>
        using isBinaryTree_t = std::enable_if_t<std::is_same_v<BTree, BinaryTree>>;

        BinaryTree* avlTree100_;
        BinaryTree* avlTree200_;
        BinaryTree* avlTree300_;
        BinaryTree* avlTree400_;
        BinaryTree* avlTree500_;

        BinaryTree* dbdTree100_;
        BinaryTree* dbdTree200_;
        BinaryTree* dbdTree300_;
        BinaryTree* dbdTree400_;
        BinaryTree* dbdTree500_;


    private:

        /// <summary>
        /// создает дерево с количеством элементов count_tree
        /// </summary>
        static std::pair<BinaryTree*, BinaryTree*> create(int count_tree);

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
        /// выбирает дерево по индексу
        /// </summary>
        BinaryTree* selectTree(int index) const;

        /// <summary>
        /// меню выбора дерева
        /// </summary>
        BinaryTree* selectTreeView();

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



    public:
        TaskExecution();
        ~TaskExecution();
        void showMenu() const override;

    };



    template<typename BTree, typename T2>
    inline void TaskExecution::print(const BTree* const tree)
    {
        using namespace std::literals;

        push(delimiter('-'));
        push(bufferItem("Данные о дереве"s));
        push(delimiter('-'));

        showReadTree(tree);
        showSizeTree(tree);
        showHashTree(tree);
        showHeightTree(tree);
        showMiddleHeightTree(tree);
        showStatusBar();

    }

    template<typename BTree, typename T2>
    inline void TaskExecution::showReadTree(const BTree* const tree)
    {
        using namespace std::literals;

        std::stringstream ss{ tree->print() };

        push(delimiter('='));
        push(bufferItem("Вывод дерева"s));
        push(delimiter('='));

        std::string first{}, second{}, third{}, fourth{}, fiveth{};
        do {

            ss >> first >> second >> third >> fourth >> fiveth;
            if (ss.good()) {
                push(bufferItem(
                    first
                    , second
                    , third
                    , fourth
                    , fiveth));
            }
        } while (ss.good());
    }

    template <typename BTree, typename T2>
    void TaskExecution
        ::showHashTree(const BTree* const tree) {

        using namespace std::literals;

        push(delimiter('='));
        push(bufferItem("Хеш сумма дерева:"s
            , std::to_string(tree->hash())));
        push(delimiter('='));
    }

    template <typename BTree, typename T2>
    void TaskExecution
        ::showHeightTree(const BTree* const tree) {

        using namespace std::literals;

        push(delimiter('='));
        push(bufferItem("Высота дерева:"s
            , std::to_string(tree->getHeightTree())));
        push(delimiter('='));
    }

    template <typename BTree, typename T2>
    void TaskExecution
        ::showSizeTree(const BTree* const tree) {

        using namespace std::literals;

        push(delimiter('='));
        push(bufferItem("Размер дерева:"s
            , std::to_string(tree->getSize())));
        push(delimiter('='));
    }

    template <typename BTree, typename T2>
    void TaskExecution
        ::showMiddleHeightTree(const BTree* const tree) {

        using namespace std::literals;

        push(delimiter('='));
        push(bufferItem("Средняя высота дерева:"s
            , std::to_string(tree->getMiddleHeight())));
        push(delimiter('='));
    }





}