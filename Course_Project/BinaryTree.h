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
		/// Создает дерево АВЛ из данных вектора db, результат - успех
		/// </summary>
		static bool toAVL(const std::vector<DatabaseEntry>& db, Node*& root);

		/// <summary>
		/// Добавляет в дерево АВЛ новую ноду
		/// </summary>
		static Node* insertToAVL(const DatabaseEntry& key, Node* root);

		/// <summary>
		/// производит балансировку дерева АВЛ
		/// </summary>
		static Node* balanceTree(Node* root);

		/// <summary>
		/// Осуществляет левый поворот дерева АВЛ
		/// </summary>
		static Node* rotateLeft(Node* root);

		/// <summary>
		/// Осуществляет правый поворот дерева АВЛ
		/// </summary>
		static Node* rotateRight(Node* root);

		/// <summary>
		/// Производит перерасчет высоты
		/// </summary>
		static void fixNodeHeight(Node* root);

		/// <summary>
		/// Возвращает высоту ноды
		/// </summary>
		static int getHeight(const Node* const root);

		/// <summary>
		/// Возвращает разницу высот дерева АВЛ
		/// </summary>
		static int getBalanceFactor(Node* root);

		/// <summary>
		/// Вычисляет и возвращает высоту дерева АВЛ
		/// </summary>
		static int  heightTree(const Node* const root);

		/// <summary>
		/// Вычисляет и возвращает размер дерева АВЛ
		/// </summary>
		static int sizeTree(const Node* const root);

		/// <summary>
		/// Ищет в дереве root уникальные издательства, найденые, записывает в вектор vdb
		/// </summary>
		static void uniqueReadTree(const Node* const root, std::vector<DatabaseEntry>& vdb);

		/// <summary>
		/// Ищет в дереве root данные содержащие поля publishing_house и lastname
		/// найденный, записывает в вектор vdb
		/// </summary>
		static void findTree(const Node* const root
			, const std::string& publishing_house
			, const std::string& lastname
			, std::vector<DatabaseEntry>& vdb);

		/// <summary>
		/// Удаляет ноду
		/// </summary>
		static void deleteTree(Node* root);

	public:

		/// <summary>
		/// Создает дерево из данных вектора
		/// </summary>
		BinaryTree(const std::vector<DatabaseEntry>& db);

		/// <summary>
		/// вызывает функцию удаления дерева
		/// </summary>
		void deleteTree();

		/// <summary>
		/// возвращает уникальные издания записанные в вектор
		/// </summary>
		std::vector<DatabaseEntry> printUnique() const;

		/// <summary>
		/// ищет в базе данных поля с данными publishing_house и lastname, и возвращает вектор
		/// </summary>
		std::vector<DatabaseEntry> find(const std::string& publishing_house, const std::string& lastname) const;
		
		/// <summary>
		/// возвращает размер дерева
		/// </summary>
		int getSize() const;

	};
}