#include "BinaryTree.h"
#include <cassert>
namespace KHAS {

	bool BinaryTree::toAVL(const std::vector<DatabaseEntry>& db)
	{
		if (db.size() == 0) return false;

		for (auto&& elem: db) {
			root_ = insertToAVL(elem, root_);
		}
		return true;
	}

	Node* BinaryTree::insertToAVL(const DatabaseEntry& key, Node* root)
	{
		if (root == nullptr) {
			return new (std::nothrow) Node(key);
		}
		if (key < root->data)   root->left = insertToAVL(key, root->left);
		else                    root->right = insertToAVL(key, root->right);

		return balanceTree(root);
		return nullptr;
	}

	Node* BinaryTree::balanceTree(Node* root)
	{
		assert(root);
		fixNodeHeight(root);

		if (getBalanceFactor(root) == 2) {
			if (getBalanceFactor(root->right) < 0)
				root->right = rotateRight(root->right);
			return rotateLeft(root);
		}
		else if (getBalanceFactor(root) == -2) {
			if (getBalanceFactor(root->left) > 0)
				root->left = rotateLeft(root->left);
			return rotateRight(root);
		}
		return root;
	}

	Node* BinaryTree::rotateLeft(Node* root)
	{
		assert(root);
		Node* node{ root->right };
		assert(node);
		root->right = node->left;
		node->left = root;
		fixNodeHeight(root);
		fixNodeHeight(node);
		return node;
	}

	Node* BinaryTree::rotateRight(Node* root)
	{
		assert(root);
		Node* node{ root->left };
		assert(node);
		root->left = node->right;
		node->right = root;
		fixNodeHeight(root);
		fixNodeHeight(node);
		return node;
	}

	void BinaryTree::fixNodeHeight(Node* root)
	{
		assert(root);
		auto height_left{ getHeight(root->left) };
		auto height_right{ getHeight(root->right) };
		root->height = (height_left > height_right ? height_left : height_right) + 1;
	}

	int BinaryTree::getHeight(const Node* const root) const
	{
		if (!root) return 0;
		return root->height;
	}

	int BinaryTree::getBalanceFactor(Node* root)
	{
		assert(root);
		return getHeight(root->right) - getHeight(root->left);
	}

	std::stringstream BinaryTree::readTree(const Node* const root) const
	{
		if (!root) return std::stringstream{};
		std::stringstream ss;
		if (root->left) ss << readTree(root->left).str();
		ss << root->data.to_string() << "\n";
		if (root->right) ss << readTree(root->right).str();
		return ss;
	}

	BinaryTree::BinaryTree(const std::vector<DatabaseEntry>& db)
		: root_(nullptr)
	{
		if (!toAVL(db)) {
			std::cout << "ньхайю! мебнглнфмн янгдюрэ депебн! " << std::endl;
			system("pause");
			exit(1);
		}
	}

	void BinaryTree::deleteTree()
	{
		deleteTree(root_);
	}

	void BinaryTree::deleteTree(Node* root)
	{
		if (root) {
			deleteTree(root->left);
			deleteTree(root->right);
			delete root;
		}
	}

	std::stringstream BinaryTree::print() const
	{
		return readTree(root_);
	}
}
