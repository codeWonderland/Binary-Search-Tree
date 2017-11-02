/* ***       Author:  Alice Easter
     *  Last Update:  November 2, 2017
     *        Class:  CSI-281
     *     Filename:  pa6.cpp
     *
     *  Description:
     *      Stub driver for testing
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my own work.
     ********************************************************************/

#include <iostream>
#include <iomanip>
#include "bst.h"

int main()
{
	BST<int> *myTree = new BST<int>();

	myTree->insert(5);
	myTree->insert(3);
	myTree->insert(8);
	myTree->insert(1);
	myTree->insert(4);

	std::cout << myTree->isExists(8) << std::endl;
	std::cout << myTree->isExists(10) << std::endl;
	std::cout << myTree->isEmpty() << std::endl;
	
	myTree->remove(3);

	myTree->showInOrder();

	delete myTree;

	system("pause");
	return 0;
}