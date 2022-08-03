#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <queue>
#include <string>
#include <type_traits>
#include <cassert>

namespace KHAS {
    class Interface {
    public:


        /// <summary>
        /// ��� ������ � ������
        /// </summary>
        using value_type = std::string;

    private:

        /// <summary>
        /// ����� �� �������� ����
        /// </summary>
        template <typename T>
        using TISValue_type_t = std::enable_if_t<std::is_same_v<std::decay_t<T>, value_type>>;

        /// <summary>
        /// �������� ���������� ������� �� ����������� � ����� ������ � ������
        /// </summary>
        template <typename ...Args>
        static constexpr bool TISValue_type_v = (std::is_same_v<std::decay_t<Args>, value_type> && ...);

        /// <summary>
        /// ����� ��� ���� � ��������� 
        /// </summary>
        static inline std::queue<value_type> buffer_{};

        /// <summary>
        /// ����� ��� ������ ����������� �������
        /// </summary>
        static inline std::queue<value_type> bufferStatusBar_{};

        /// <summary>
        /// ������ ����� �� ����������� �����
        /// </summary>
        static inline size_t fieldWidth_{ 100 };

    private:

        /// <summary>
        /// 
        /// </summary>
        template <typename OutType
            , typename = TISValue_type_t<OutType>>
        static OutType addLineTranslation(OutType&& str);

        /// <summary>
        /// �������� ����� ���������� ������ �� ����������� �������� 
        /// </summary>
        template <typename First, typename ...Rest>
        static bool isValidity(const First& str, const Rest& ... rest);

        /// <summary>
        /// �������������� �������
        /// </summary>
        static bool isValidity() { return false;  }

        /// <summary>
        /// ����������� ������ str
        /// </summary>
        template <typename SizeStr, typename Str, typename = TISValue_type_t<Str>>
        static value_type textAlign(SizeStr size, Str&& str);

    protected:

        /// <summary>
        /// ��������� � �����
        /// </summary>
        template <typename ...Args>
        static void pushToBuffer(Args&&... args);

        /// <summary>
        /// ��������� � ����� � ������ ���
        /// </summary>
        template <typename ...Args>
        static void push(Args&&... args);

        /// <summary>
        /// ���������� �����������, ��������� �� ������� del
        /// </summary>
        template <typename Delim, typename = std::enable_if_t<std::is_same_v<Delim, value_type::value_type>>>
        static value_type delimiter(Delim del);

        /// <summary>
        /// ����������� ��������� � �������, ��������� ��� ������
        /// </summary>
        template <typename...Args>
        static value_type bufferItem(Args&& ...args);

        /// <summary>
        /// ��������� ������� ���������� � �����
        /// </summary>
        static void showHeader();

        /// <summary>
        /// ��������� ������� �� ������������
        /// </summary>
        void readCommand();

        /// <summary>
        /// ��������� �������, � ����������� �� �������
        /// </summary>
        virtual void functionLaunch() = 0;

        /// <summary>
        /// ��������� ���� ��� ������������, � �����
        /// </summary>
        virtual void showMenu() = 0;

        /// <summary>
        /// ���������� ����� �� ����������� �����
        /// </summary>
        static void show();

        /// <summary>
        /// 
        /// </summary>
        static size_t getFieldWidht();

        /// <summary>
        /// ���������� ����� ��� ������ ���� �� ����������� �����
        /// </summary>
        static void showStatusBar();

    public:

        /// <summary>
        /// 
        /// </summary>
        explicit Interface() = default;

        ///
        ///
        /// 
        virtual ~Interface();

        /// <summary>
        /// ������� ������� ���������� ������ � ������ ���������� �� ����������� �����
        /// </summary>
        void view();


    };

}

#include "Interface.hpp"