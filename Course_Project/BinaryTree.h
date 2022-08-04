#pragma once

#include <sstream>
#include <vector>
#include "DataBase.h"
#include "Node.h"

namespace KHAS {
	class BinaryTree {

		Node* root_;


	private:

		/// <summary>
		/// ������� ������ ��� �� ������ ������� db, ��������� - �����
		/// </summary>
		static bool toAVL(const std::vector<DatabaseEntry>& db, Node*& root);

		/// <summary>
		/// ��������� � ������ ��� ����� ����
		/// </summary>
		static Node* insertToAVL(const DatabaseEntry& key, Node* root);

		/// <summary>
		/// ���������� ������������ ������ ���
		/// </summary>
		static Node* balanceTree(Node* root);

		/// <summary>
		/// ������������ ����� ������� ������ ���
		/// </summary>
		static Node* rotateLeft(Node* root);

		/// <summary>
		/// ������������ ������ ������� ������ ���
		/// </summary>
		static Node* rotateRight(Node* root);

		/// <summary>
		/// ���������� ���������� ������
		/// </summary>
		static void fixNodeHeight(Node* root);

		/// <summary>
		/// ���������� ������ ����
		/// </summary>
		static int getHeight(const Node* const root);

		/// <summary>
		/// ���������� ������� ����� ������ ���
		/// </summary>
		static int getBalanceFactor(Node* root);

		/// <summary>
		/// ��������� � ���������� ������ ������ ���
		/// </summary>
		static int  heightTree(const Node* const root);

		/// <summary>
		/// ��������� � ���������� ������ ������ ���
		/// </summary>
		static int sizeTree(const Node* const root);

		/// <summary>
		/// ���� � ������ root ���������� ������������, ��������, ���������� � ������ vdb
		/// </summary>
		static void uniqueReadTree(const Node* const root, std::vector<DatabaseEntry>& vdb);

		/// <summary>
		/// ���� � ������ root ������ ���������� ���� publishing_house � lastname
		/// ���������, ���������� � ������ vdb
		/// </summary>
		static void findTree(const Node* const root
			, const std::string& publishing_house
			, const std::string& lastname
			, std::vector<DatabaseEntry>& vdb);

		/// <summary>
		/// ������� ����
		/// </summary>
		static void deleteTree(Node* root);

	public:

		/// <summary>
		/// ������� ������ �� ������ �������
		/// </summary>
		BinaryTree(const std::vector<DatabaseEntry>& db);

		/// <summary>
		/// �������� ������� �������� ������
		/// </summary>
		void deleteTree();

		/// <summary>
		/// ���������� ���������� ������� ���������� � ������
		/// </summary>
		std::vector<DatabaseEntry> printUnique() const;

		/// <summary>
		/// ���� � ���� ������ ���� � ������� publishing_house � lastname, � ���������� ������
		/// </summary>
		std::vector<DatabaseEntry> find(const std::string& publishing_house, const std::string& lastname) const;
		
		/// <summary>
		/// ���������� ������ ������
		/// </summary>
		int getSize() const;

	};
}