#pragma once
#include <string>
#include <iostream>
#include <utility>

namespace KHAS {

	struct DatabaseEntry {

	public:

		char author[13]{};
		char header[33]{};
		char publishing_house[17]{};
		short year{};
		short pages_count{};

		std::string to_string() const;
		friend std::istream& operator >> (std::istream& in, DatabaseEntry& db);
	};

	bool operator == (const DatabaseEntry& lhs, const DatabaseEntry& rhs);
	bool operator< (const DatabaseEntry& lhs, const DatabaseEntry& rhs);
	bool operator> (const DatabaseEntry& lhs, const DatabaseEntry& rhs);
}