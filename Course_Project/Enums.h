#pragma once

namespace KHAS {

    // ��� ������
    enum class TypeTree {
        AVL, DBD
    };

    // ������������ ������� � ���������
    enum class InputCommand {
        NoCommand
        , Exit
        , ErrorCommands
        , Print
    };

    // ��� ��������� � ��� ������
    enum class RotationTree {
        Left
        , Right
        , LeftRight
        , RightLeft
    };

    enum class InsertTypeInBTree {
        Begin
        , Next
    };

}