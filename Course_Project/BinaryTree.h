#pragma once

#include "Enums.h"
#include <sstream>

namespace KHAS {
	class BinaryTree {

	public:
		BinaryTree(int n);
		BinaryTree(BinaryTree* bt);
		void deleteTree() { };
		std::stringstream print() const { return std::stringstream();  };
		int getSize() const { return 42;  }
		int hash() const { return 42;  };
		int  getHeightTree() const { return 42; };
		int  getMiddleHeight() const { return 42;  };
		TypeTree  getTypeTree() const { return TypeTree::AVL;  };
	};
}