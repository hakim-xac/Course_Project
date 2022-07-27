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
        /// ������� ������ � ����������� ��������� count_tree
        /// </summary>
        static std::pair<BinaryTree*, BinaryTree*> create(int count_tree);

        /// <summary>
        /// ��������� �� ���������� ��������� �������
        /// </summary>
        bool checkIsTree();

        /// <summary>
        /// �������, ����������� �� ������� ������, ��������� � �����
        /// </summary>
        template <typename BTree, typename = isBinaryTree_t<BTree>>
        static void print(const BTree* const tree);

        /// <summary>
        /// ��������� ������ � ��������� ������ � �����
        /// </summary>
        template <typename BTree, typename = isBinaryTree_t<BTree>>
        static void showReadTree(const BTree* const tree);

        /// <summary>
        /// ������� ���-����� � ������� � �����
        /// </summary>
        template <typename BTree, typename = isBinaryTree_t<BTree>>
        static void showHashTree(const BTree* const tree);

        /// <summary>
        /// ������� ������ ������ � ������� � �����
        /// </summary>
        template <typename BTree, typename = isBinaryTree_t<BTree>>
        static void showHeightTree(const BTree* const tree);

        /// <summary>
        /// ������� ������ ������
        /// </summary>
        template <typename BTree, typename = isBinaryTree_t<BTree>>
        static void showSizeTree(const BTree* const tree);

        /// <summary>
        /// ������� ������� ������ ������
        /// </summary>
        template <typename BTree, typename = isBinaryTree_t<BTree>>
        static void showMiddleHeightTree(const BTree* const tree);

        /// <summary>
        /// �������� ������ �� �������
        /// </summary>
        BinaryTree* selectTree(int index) const;

        /// <summary>
        /// ���� ������ ������
        /// </summary>
        BinaryTree* selectTreeView();

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
        push(bufferItem("������ � ������"s));
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
        push(bufferItem("����� ������"s));
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
        push(bufferItem("��� ����� ������:"s
            , std::to_string(tree->hash())));
        push(delimiter('='));
    }

    template <typename BTree, typename T2>
    void TaskExecution
        ::showHeightTree(const BTree* const tree) {

        using namespace std::literals;

        push(delimiter('='));
        push(bufferItem("������ ������:"s
            , std::to_string(tree->getHeightTree())));
        push(delimiter('='));
    }

    template <typename BTree, typename T2>
    void TaskExecution
        ::showSizeTree(const BTree* const tree) {

        using namespace std::literals;

        push(delimiter('='));
        push(bufferItem("������ ������:"s
            , std::to_string(tree->getSize())));
        push(delimiter('='));
    }

    template <typename BTree, typename T2>
    void TaskExecution
        ::showMiddleHeightTree(const BTree* const tree) {

        using namespace std::literals;

        push(delimiter('='));
        push(bufferItem("������� ������ ������:"s
            , std::to_string(tree->getMiddleHeight())));
        push(delimiter('='));
    }





}