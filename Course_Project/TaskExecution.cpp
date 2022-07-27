#include "TaskExecution.h"

namespace KHAS {
    std::pair<BinaryTree*, BinaryTree*> TaskExecution::create(int count_tree)
    {
        return { nullptr, nullptr };
        /*BinaryTree* avl_tree{ new (std::nothrow) BinaryTree(count_tree) };

        if (!avl_tree) return { nullptr, nullptr };

        BinaryTree* dbd_tree{ new (std::nothrow) BinaryTree(avl_tree) };

        if (!dbd_tree) {
            avl_tree->deleteTree();
            return { nullptr, nullptr };
        }

        return { avl_tree, dbd_tree };*/
    }

    bool TaskExecution::checkIsTree()
    {
        return (avlTree100_ != nullptr && avlTree200_ != nullptr
            && avlTree300_ != nullptr && avlTree400_ != nullptr
            && avlTree500_ != nullptr && dbdTree100_ != nullptr
            && dbdTree200_ != nullptr && dbdTree300_ != nullptr
            && dbdTree400_ != nullptr && dbdTree500_ != nullptr
            );
    }

    BinaryTree* TaskExecution::selectTree(int index) const
    {
        BinaryTree* bt{ nullptr };
        switch (index) {
        case 1:     bt = avlTree100_;  break;
        case 2:     bt = avlTree200_;  break;
        case 3:     bt = avlTree300_;  break;
        case 4:     bt = avlTree400_;  break;
        case 5:     bt = avlTree500_;  break;
        case 6:     bt = dbdTree100_;  break;
        case 7:     bt = dbdTree200_;  break;
        case 8:     bt = dbdTree300_;  break;
        case 9:     bt = dbdTree400_;  break;
        case 0:     bt = dbdTree500_;  break;
        default:    bt = nullptr;
        }
        return bt;
    }

    BinaryTree* TaskExecution::selectTreeView()
    {
        using namespace std::literals;
        int index{};
        bool start{};
        bool isSelectBase{};
        BinaryTree* bt{ nullptr };
        while (!isSelectBase || !start || std::cin.fail()) {
            std::cin.clear();
            if (start) {
                push(bufferItem("������ �����!"s));
                push(bufferItem("��������� ����!"s));
                std::cin.get();
            }
            push(delimiter('-'));
            push(bufferItem("������� ����� �� 0 �� 9, � ����� ������ ����� ������:"s));
            push(delimiter('-'));
            push(bufferItem("1 -"s, "��� ������ �������� � 100 ���������"s));
            push(bufferItem("2 -"s, "��� ������ �������� � 200 ���������"s));
            push(bufferItem("3 -"s, "��� ������ �������� � 300 ���������"s));
            push(bufferItem("4 -"s, "��� ������ �������� � 400 ���������"s));
            push(bufferItem("5 -"s, "��� ������ �������� � 500 ���������"s));
            push(delimiter('-'));
            push(bufferItem("6 -"s, "��� ������ �������� � 100 ���������"s));
            push(bufferItem("7 -"s, "��� ������ �������� � 200 ���������"s));
            push(bufferItem("8 -"s, "��� ������ �������� � 300 ���������"s));
            push(bufferItem("9 -"s, "��� ������ �������� � 400 ���������"s));
            push(bufferItem("0 -"s, "��� ������ �������� � 500 ���������"s));
            push(delimiter('-'));
            showStatusBar();
            std::cin >> index;
            start = true;
            if (bt = selectTree(index)) isSelectBase = true;
        }

        std::cin.get();
        return bt;
    }

    void TaskExecution::functionLaunch()
    {
        // ��������� ��������� ������� �� ����������
        if (!checkIsTree()) {
            system("cls");
            std::cout << "��������! �� ������� �������� ������ �� ���� ��� ������!";
            exit(1);
        }

        // ��������� ������������ ������������� �������
        switch (getActiveCommand()) {
        case InputCommand::Print:       printView();    break;
        case InputCommand::Exit:        quit();         break;
        default: break;
        }

        // ������� �������
        clearActiveCommand();
    }

    TaskExecution
        ::TaskExecution()
        : Interface()
        , avlTree100_(nullptr), avlTree200_(nullptr)
        , avlTree300_(nullptr), avlTree400_(nullptr)
        , avlTree500_(nullptr), dbdTree100_(nullptr)
        , dbdTree200_(nullptr), dbdTree300_(nullptr)
        , dbdTree400_(nullptr), dbdTree500_(nullptr) {

        // ������� ����������� �������
        std::tie(avlTree100_, dbdTree100_) = create(100);
        std::tie(avlTree200_, dbdTree200_) = create(200);
        std::tie(avlTree300_, dbdTree300_) = create(300);
        std::tie(avlTree400_, dbdTree400_) = create(400);
        std::tie(avlTree500_, dbdTree500_) = create(500);

    }

    TaskExecution::~TaskExecution()
    {
        // ������� ������� � �������� ���������
        avlTree100_->deleteTree();
        avlTree200_->deleteTree();
        avlTree300_->deleteTree();
        avlTree400_->deleteTree();
        avlTree500_->deleteTree();
        dbdTree100_->deleteTree();
        dbdTree200_->deleteTree();
        dbdTree300_->deleteTree();
        dbdTree400_->deleteTree();
        dbdTree500_->deleteTree();

        delete avlTree100_;     delete dbdTree100_;
        delete avlTree200_;     delete dbdTree200_;
        delete avlTree300_;     delete dbdTree300_;
        delete avlTree400_;     delete dbdTree400_;
        delete avlTree500_;     delete dbdTree500_;

        avlTree100_ = nullptr;  dbdTree100_ = nullptr;
        avlTree200_ = nullptr;  dbdTree200_ = nullptr;
        avlTree300_ = nullptr;  dbdTree300_ = nullptr;
        avlTree400_ = nullptr;  dbdTree400_ = nullptr;
        avlTree500_ = nullptr;  dbdTree500_ = nullptr;
    }

    void TaskExecution::quit() const
    {
        system("cls");
        exit(0);
    }

    void TaskExecution::printView()
    {
        BinaryTree* bt{ selectTreeView() };
        print(bt);
    }

    void TaskExecution::showMenu() const
    {
        using namespace std::literals;

        // ��������� ����������������� ������ � �����
        pushToBuffer(delimiter('='));
        pushToBuffer(bufferItem("����"s));
        pushToBuffer(delimiter('-'));
        pushToBuffer(bufferItem("�������"s, "�������"s));
        pushToBuffer(delimiter('-'));
        pushToBuffer(bufferItem("1"s, "��������� ������ � ������"s));
        pushToBuffer(delimiter('-'));
        pushToBuffer(bufferItem("9"s, "������� ����������"s));
        pushToBuffer(delimiter('='));

        // ���������� �� ����� � �������
        show();
    }

}