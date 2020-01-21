		// Files libraries included
#include <cstdlib>
#include <cstddef>
#include <iostream>


		// Files included
#include "binaryTreeType.h"
#include "binarySearchTree.h"

using namespace std;

int main()
{

		// Create a tree

bSearchTreeType<int> Tree;

		// Operations from binarySearchTree.h
		
		// Insert
cout << "Inserting numbers and references!" << endl;
Tree.insert(2);
Tree.insert(1);
Tree.insert(5);
Tree.insert(11);
Tree.insert(289);
Tree.insert(440);
Tree.insert(47);
Tree.insert(350);
Tree.insert(286);
Tree.insert(351);
Tree.insert(360);
Tree.insert(454);
Tree.insert(460);
Tree.insert(9001);
Tree.insert(1337);
Tree.insert(42);
Tree.insert(1701);

		// Search
cout << "Looking for references!" << endl;
Tree.search(42);
Tree.search(1701);
Tree.search(2112);
Tree.search(6505);

		// Delete
cout << "Deleting non-references!" << endl;
Tree.deleteNode(2);
Tree.deleteNode(1);
Tree.deleteNode(5);
Tree.deleteNode(11);

		// Operations from binaryTreeType.h

		// Is Empty?
Tree.isEmpty();

		// Inorder Traversal
Tree.inorderTraversal();

		// Preorder Traversal
Tree.preorderTraversal();

		// Postorder Traversal
Tree.postorderTraversal();

		// Tree height
Tree.treeHeight();		

		// Tree node count
Tree.treeNodeCount();

		// Tree leaves count
Tree.treeLeavesCount();

		// Destroy tree
Tree.destroyTree();

		// Virtual functions used by other header file
		// Insert, already used, no need to double dip
		// Delete
		// Search

system("pause");
return 0;
}
