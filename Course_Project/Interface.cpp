#include "Interface.h"
#include <string>

namespace KHAS {

    void Interface::showHeader()
    {
        // ��������� ����������������� ������ � �����
        using namespace std::literals;
        pushToBuffer(delimiter('='));
        pushToBuffer(bufferItem("��������� � ��������� ��������� ������ (����� 2)"s));
        pushToBuffer(delimiter('-'));
        pushToBuffer(bufferItem("�������� ������:"s));
        pushToBuffer(delimiter('-'));
        pushToBuffer(bufferItem("�������:"s, "1"s));
        pushToBuffer(delimiter('-'));
        pushToBuffer(bufferItem("����� ���� ������:"s, "A = 1"s));
        pushToBuffer(delimiter('-'));
        pushToBuffer(bufferItem("����� �������:"s, "B = 1.2"s));
        pushToBuffer(delimiter('-'));
        pushToBuffer(bufferItem("��� ������ ������:"s, "D = 1"s));
        pushToBuffer(delimiter('-'));
        pushToBuffer(bufferItem("�������� �������:"s, "������� �.�."s));
        pushToBuffer(delimiter('='));

        // ���������� ����� �� ����� � �������
        show();
    }

    void Interface::readCommand()
    {
        //std::cout << std::string(fieldWidth_, '_')
        //    << std::string(fieldWidth_, '\b')
        //    << "������� �������:";

        //// �������� ���� ������, ��������� �������
        //int cmd{ std::cin.get() };
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //// ���������� �������
        //switch (cmd)
        //{
        //case 49: activeCommand_ = InputCommand::Print;      break; // 1 
        //case 57: activeCommand_ = InputCommand::Exit;       break; // 9

        //default: activeCommand_ = InputCommand::ErrorCommands;            
        //}
        
    }

    Interface::~Interface()
    {
        // ��� ����������� �������, ���������� �� ����� �� ��� ���� � ���� � ������
        show();
    }

    void Interface::show()
    {
        // ���������� ����� �� ����������� �����
        while (!buffer_.empty()) {

            std::cout << buffer_.front() << "\n";
            buffer_.pop();
        }
        std::flush(std::cout);
    }

    size_t Interface::getFieldWidht()
    {
        return fieldWidth_;
    }



    void Interface::showStatusBar()
    {
        // ���������� ����� �� ����������� �����

        if (!bufferStatusBar_.empty()) {

            while (!bufferStatusBar_.empty()) {
                std::cout << bufferStatusBar_.front() << "\n";
                bufferStatusBar_.pop();
            }
            std::flush(std::cout);
        }
    }



    void Interface::view()
    {
        // ��������� ���� � ��������� ������� ���������� �� ������������
        while (true) {

            // ������� �����
            system("cls");

            // ������� ���������
            showHeader();

            // ��������� ������� ��������� �� ���������� �������
            functionLaunch();

            // ������� ��������� �������
            showStatusBar();

            // ������� ���� ������������
            showMenu();

            // �������� ������� �� ������������
            //readCommand();
        }
    }

}
