namespace KHAS {
#include <iostream>
#include <sstream>

    template<typename FileNameType>
    inline BinaryTree* TaskExecution::create(FileNameType&& filename)
    {               
        
        FILE* fn{ nullptr };
        
        if (fopen_s(&fn, std::forward<FileNameType>(filename), "rb")) {
            std::cout << "ФАЙЛ " << filename << " ОТСУТСТВУЕТ!!";
            exit(1);
            return nullptr;
        }

        vec_db_.reserve(4000);
        auto&& [db, is_db] { fromFileToDatabaseEntry(fn) };
        while (is_db) {
            vec_db_.emplace_back(db);
            std::tie(db, is_db) = fromFileToDatabaseEntry(fn);
        }

        for (auto&& elem: vec_db_) {
            std::cout << elem;
        }

        system("pause");
        return nullptr;
    }

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

    template <typename T>
    bool TaskExecution
        ::readFromStream(FILE* fn, T&& t, std::size_t size) {
        if (!fn) return false;
        if (fread(reinterpret_cast<char*>(&std::forward<T>(t)), sizeof(char), size, fn) != size) {
            fclose(fn);
            return false;
        }
        return true;
    }
}