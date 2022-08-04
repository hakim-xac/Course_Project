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

        return new (std::nothrow) BinaryTree(vec_db_);
    }
}