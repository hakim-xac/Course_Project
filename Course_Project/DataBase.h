#pragma once
#include <string>
#include <iostream>
#include <utility>

namespace KHAS {

	struct DatabaseEntry {

	public:
		/// <summary>
		/// поле "Автор"
		/// </summary>
		char author[13]{};

		/// <summary>
		/// поле "Заглавие"
		/// </summary>
		char header[33]{};

		/// <summary>
		/// поле "Издательство"
		/// </summary>
		char publishing_house[17]{};

		/// <summary>
		/// поле "Год издательства"
		/// </summary>
		short year{};

		/// <summary>
		/// поле "Количество страниц"
		/// </summary>
		short pages_count{};

		/// <summary>
		/// переводит структуру в строку
		/// </summary>
		std::string to_string() const;

		/// <summary>
		/// оператор потока ввода
		/// </summary>
		friend std::istream& operator >> (std::istream& in, DatabaseEntry& db);
	};

	/// <summary>
	/// оператор ==, сравинивает поля "publishing_house"
	/// </summary>
	bool operator == (const DatabaseEntry& lhs, const DatabaseEntry& rhs);

	/// <summary>
	/// оператор <, сравинивает поля "author"
	/// </summary>
	bool operator < (const DatabaseEntry& lhs, const DatabaseEntry& rhs);
}