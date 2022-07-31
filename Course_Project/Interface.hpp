
namespace KHAS{

    template <typename ...Args>
    void Interface
    ::pushToBuffer(Args&&... args) {

        constexpr bool isSame{ (std::is_same_v<Args
        , KHAS::Interface::value_type> && ...) };
        /// ¬ходные типы не соответствуют типу базы
        static_assert(isSame, "Input types do not match base type!");

        assert(isValidity(args...));

        (buffer_.push(std::forward<Args>(args)), ...);

    }

    template <typename ...Args>
    void Interface
    ::push(Args&&... args) {

        constexpr bool isSame{ (std::is_same_v<Args
        , KHAS::Interface::value_type> && ...) };
        /// ¬ходные типы не соответствуют типу базы
        static_assert(isSame, "Input types do not match base type!");

        assert(isValidity(args...));

        (bufferStatusBar_.push(std::forward<Args>(args)), ...);

    }

    template <typename ...Args>
    Interface::value_type Interface
    ::bufferItem(Args&&... args) {

        constexpr bool isSame{ TISValue_type_v<Args...> };
        /// ¬ходные типы не соответствуют типу базы
        static_assert(isSame, "Input types do not match base type!");

        std::stringstream ss;

        ss << "# ";
        auto size_field{ (fieldWidth_ - 4) / sizeof...(Args) };

        (ss << ... << textAlign(size_field, std::forward<Args>(args)));

        size_t rest_width{ fieldWidth_ - ss.str().size() };
        if (rest_width > 0) ss << std::setw(rest_width) << std::setfill(' ');
        ss << " #";

        assert(ss.str().size() <= fieldWidth_);

        return ss.str();
    }

    template<typename OutType, typename T2>
    inline OutType Interface
    ::addLineTranslation(OutType&& str)
    {
        /// ¬ходные типы не соответствуют типу базы
        static_assert(std::is_same_v<OutType, value_type>, "Input types do not match base type!");

        return std::forward<OutType>(str) + " ";
    }

    template<typename First, typename ...Rest>
    inline bool Interface::isValidity(const First& str, const Rest & ...rest)
    {
        if constexpr (sizeof...(Rest) == 0) return true;
        return (str.size() <= fieldWidth_) && isValidity(rest...);
    }


    template <typename SizeStr, typename Str, typename T3>
    Interface::value_type Interface
    ::textAlign(SizeStr size, Str&& str) {

        std::stringstream ss;

        auto&& str_ss{ std::forward<Str>(str) };

        size_t even{ str_ss.size() % 2 };

        assert(str_ss.size() <= size);

        ss << std::setw((size + str_ss.size()) / 2)
            << str_ss << std::setw((size - str_ss.size()) / 2) << "";

        return ss.str();
    }

    template <typename Delim, typename T2>
    static Interface::value_type Interface
    ::delimiter(Delim del) {
        Interface::value_type str(fieldWidth_, del);
        str.front() = '#';
        str.back() = '#';
        return str;
    }
}