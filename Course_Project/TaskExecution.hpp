namespace KHAS {
#include <iostream>
#include <sstream>
#include "BinaryTree.h"

    template<typename FileNameType>
    inline BinaryTree* TaskExecution::create(FileNameType&& filename)
    {               
        
        std::ifstream base_file{ std::forward<FileNameType>(filename), std::ios::binary };
        if (!base_file.is_open()) {
            std::cout << "ÔÀÉË " << filename << " ÎÒÑÓÒÑÒÂÓÅÒ!!";
            exit(1);
            return nullptr;
        }

        vec_db_.reserve(4000);

        auto&& [db, is_db] { fromFileToDatabaseEntry(base_file) };
        while (is_db) {
            vec_db_.emplace_back(db);
            std::tie(db, is_db) = fromFileToDatabaseEntry(base_file);
        }

        /*for (auto&& elem: vec_db_) {
            std::cout << elem << "\n";
        }

        system("pause");*/

        return new (std::nothrow) BinaryTree(vec_db_);
    }

    template<typename BTree, typename T2>
    inline void TaskExecution::print(const BTree* const tree)
    {        
        showReadTree(tree);
        showStatusBar();

    }

    template<typename BTree, typename T2>
    inline void TaskExecution::showReadTree(const BTree* const tree)
    {
        using namespace std::literals;


        push(delimiter('='));
        push(bufferItem("Âûâîä äåðåâà"s));
        push(delimiter('='));

        //do {
        //    DatabaseEntry db_tmp{};
        //    ss >> db_tmp;
        //    auto s{ db_tmp.to_string() };

        //    if (ss.good()) {
        //        push(bufferItem(s));
        //        push(delimiter('-'));
        //    }
        //} while (ss.good());

        for (auto&& elem: vec_db_) {
            push(bufferItem(elem.to_string()));
            push(delimiter('-'));
        }
    }
}