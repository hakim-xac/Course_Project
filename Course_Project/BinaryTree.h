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
		void deleteTree(Node* root);

	public:
		BinaryTree(const std::vector<DatabaseEntry>& db);
		void deleteTree();
		std::stringstream print() const;

		int getSize() const { return 42;  }
		int hash() const { return 42;  };
		int  getHeightTree() const { return 42; };
		int  getMiddleHeight() const { return 42;  };
		TypeTree  getTypeTree() const { return TypeTree::AVL;  };
	};
}