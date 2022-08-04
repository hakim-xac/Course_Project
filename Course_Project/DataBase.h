#pragma once
#include <string>
#include <iostream>
#include <utility>

namespace KHAS {

	struct DatabaseEntry {

	public:
		/// <summary>
		/// ���� "�����"
		/// </summary>
		char author[13]{};

		/// <summary>
		/// ���� "��������"
		/// </summary>
		char header[33]{};

		/// <summary>
		/// ���� "������������"
		/// </summary>
		char publishing_house[17]{};

		/// <summary>
		/// ���� "��� ������������"
		/// </summary>
		short year{};

		/// <summary>
		/// ���� "���������� �������"
		/// </summary>
		short pages_count{};

		/// <summary>
		/// ��������� ��������� � ������
		/// </summary>
		std::string to_string() const;

		/// <summary>
		/// �������� ������ �����
		/// </summary>
		friend std::istream& operator >> (std::istream& in, DatabaseEntry& db);
	};

	/// <summary>
	/// �������� ==, ����������� ���� "publishing_house"
	/// </summary>
	bool operator == (const DatabaseEntry& lhs, const DatabaseEntry& rhs);

	/// <summary>
	/// �������� <, ����������� ���� "author"
	/// </summary>
	bool operator < (const DatabaseEntry& lhs, const DatabaseEntry& rhs);
}