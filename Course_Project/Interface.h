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
        /// тип данных в буфере
        /// </summary>
        using value_type = std::string;

    private:

        /// <summary>
        /// алиас на проверку типа
        /// </summary>
        template <typename T>
        using TISValue_type_t = std::enable_if_t<std::is_same_v<std::decay_t<T>, value_type>>;

        /// <summary>
        /// проверка аргументов шаблона на соотвествие с типом данных в буфере
        /// </summary>
        template <typename ...Args>
        static constexpr bool TISValue_type_v = (std::is_same_v<std::decay_t<Args>, value_type> && ...);

        /// <summary>
        /// буфер для меню и заголовка 
        /// </summary>
        static inline std::queue<value_type> buffer_{};

        /// <summary>
        /// буфер для данных результатов функций
        /// </summary>
        static inline std::queue<value_type> bufferStatusBar_{};

        /// <summary>
        /// ширина строк на стандартный вывод
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
        /// прорерка длины полученной строки на разрешенный диапазон 
        /// </summary>
        template <typename First, typename ...Rest>
        static bool isValidity(const First& str, const Rest& ... rest);

        /// <summary>
        /// вспомогательна функция
        /// </summary>
        static bool isValidity() { return false;  }

        /// <summary>
        /// форматирует строку str
        /// </summary>
        template <typename SizeStr, typename Str, typename = TISValue_type_t<Str>>
        static value_type textAlign(SizeStr size, Str&& str);

    protected:

        /// <summary>
        /// добавляет в буфер
        /// </summary>
        template <typename ...Args>
        static void pushToBuffer(Args&&... args);

        /// <summary>
        /// добавляет в буфер в статус бар
        /// </summary>
        template <typename ...Args>
        static void push(Args&&... args);

        /// <summary>
        /// возвращает разделитель, состоящий из символа del
        /// </summary>
        template <typename Delim, typename = std::enable_if_t<std::is_same_v<Delim, value_type::value_type>>>
        static value_type delimiter(Delim del);

        /// <summary>
        /// форматирует аргументы в элемент, пригодный для буфера
        /// </summary>
        template <typename...Args>
        static value_type bufferItem(Args&& ...args);

        /// <summary>
        /// добавляет вводную информацию в буфер
        /// </summary>
        static void showHeader();

        /// <summary>
        /// считывает команду от пользователя
        /// </summary>
        void readCommand();

        /// <summary>
        /// выполняет функции, в зависимости от команды
        /// </summary>
        virtual void functionLaunch() = 0;

        /// <summary>
        /// добавляет меню для пользователя, в буфер
        /// </summary>
        virtual void showMenu() = 0;

        /// <summary>
        /// сбрасывает буфер на стандартный вывод
        /// </summary>
        static void show();

        /// <summary>
        /// 
        /// </summary>
        static size_t getFieldWidht();

        /// <summary>
        /// сбрасывает буфер для статус бара на стандартный вывод
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
        /// главная функция обработчик команд и вывода информации на стандартный вывод
        /// </summary>
        void view();


    };

}

#include "Interface.hpp"