#include <iostream>
#include "bst.h"

int main()
{
	BST<int> myTree;

	myTree.insert(5);
	myTree.insert(3);
	myTree.insert(8);
	myTree.insert(1);
	myTree.insert(4);

	std::cout << myTree.isExists(8) << std::endl;
	std::cout << myTree.isExists(10) << std::endl;
	std::cout << myTree.isEmpty() << std::endl;
	
	return 0;
}