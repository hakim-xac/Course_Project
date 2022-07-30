#include "DataBase.h"

namespace KHAS {

    std::ostream& KHAS::operator<<(std::ostream& out, const DatabaseEntry& db)
    {
        out << db.author << " "
            << db.header << " "
            << db.publishing_house << " "
            << db.year << " "
            << db.pages_count << "\n";
        return out;
    }

}