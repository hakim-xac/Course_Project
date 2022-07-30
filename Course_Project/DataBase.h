#pragma once
#include <string>
#include <iostream>
#include <utility>

namespace KHAS {

	struct DatabaseEntry {

		char author[13]{};
		char header[33]{};
		char publishing_house[17]{};
		short year{};
		short pages_count{};
		friend std::ostream& operator << (std::ostream& out, const DatabaseEntry& db);

	};
	
}