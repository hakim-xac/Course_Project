#pragma once

#include "Enums.h"
#include <sstream>
#include <vector>
#include "DataBase.h"
#include "Node.h"

namespace KHAS {
	class BinaryTree {

		Node* root_;


	private:
		bool toAVL(const std::vector<DatabaseEntry>& db);
		Node* insertToAVL(const DatabaseEntry& key, Node* root);
		Node* balanceTree(Node* root);
		Node* rotateLeft(Node* root);
		Node* rotateRight(Node* root);
		void fixNodeHeight(Node* root);
		int getHeight(const Node* const root) const;
		int getBalanceFactor(Node* root);
		std::stringstream readTree(const Node* const root) const;
		void uniqueReadTree(const Node* const root, std::vector<DatabaseEntry>& vdb) const;
		void deleteTree(Node* root);
		int  heightTree(const Node* const root) const;
		int sizeTree(const Node* const root) const;

	public:
		BinaryTree(const std::vector<DatabaseEntry>& db);
		void deleteTree();
		std::stringstream print() const;
		std::vector<DatabaseEntry> printUnique() const;
		int  getHeightTree() const;
		int getSize() const;

	};
}