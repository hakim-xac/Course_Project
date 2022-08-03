#include "DataBase.h"
#include <Windows.h>

namespace KHAS {


    std::istream& operator>>(std::istream& in, DatabaseEntry& db)
    {
        in.read(reinterpret_cast<char*>(&db.author), sizeof(db.author) - 1);
        in.read(reinterpret_cast<char*>(&db.header), sizeof(db.header) - 1);
        in.read(reinterpret_cast<char*>(&db.publishing_house), sizeof(db.publishing_house) - 1);
        in.read(reinterpret_cast<char*>(&db.year), 2);
        in.read(reinterpret_cast<char*>(&db.pages_count), 2);
        return in;
    }

    bool operator<(const DatabaseEntry& lhs, const DatabaseEntry& rhs)
    {
        return strcmp(lhs.publishing_house, rhs.publishing_house) < 0;
    }

    bool operator>(const DatabaseEntry& lhs, const DatabaseEntry& rhs)
    {
        return strcmp(lhs.publishing_house, rhs.publishing_house) > 0;
    }

    std::string DatabaseEntry::to_string() const
    {
        return std::string(author)          +   "   |   "
            + std::string(header)           +   "   |   "
            + std::string(publishing_house) +   "   |   "
            + std::to_string(year)          +   "   |   "
            + std::to_string(pages_count);
    }

    bool operator==(const DatabaseEntry& lhs, const DatabaseEntry& rhs )
    {
        return strcmp(lhs.publishing_house, rhs.publishing_house) == 0;
    }


}