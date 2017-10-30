#ifndef _BST_H
#define _BST_H

#include <iostream>

using namespace std;

template <class T>
class BST
{
	private:
      template <class T>
      struct Node
      {
         T       mData;
         Node<T> *mLeft, *mRight;

         /*      Pre:  None
          *     Post:  This object is initialized using default values
          *  Purpose:  To intialize date object
          *************************************************************************/
         Node()
         {
            mData = T();
            mLeft = NULL;
            mRight = NULL;
         }

         /*      Pre:  None
          *     Post:  This object is initialized using specified data
          *  Purpose:  To intialize date object
          *************************************************************************/
         Node(T data)
         {
            mData = data;
            mLeft = NULL;
            mRight = NULL;
         }

         /*      Pre:  None
          *     Post:  This object is initialized using specified data with the 
          *            specified children attached
          *  Purpose:  To intialize date object
          *************************************************************************/
         Node(T data, Node<T> *left, Node<T> *right)
         {
            mData = data;
            mLeft = left;
            mRight = right;
         }
      };

		Node<T> *mRootNode;

		BST(T data, Node<T> *left = NULL, Node<T> *right = NULL);

		void destroySubtree(Node<T> *node);
		void displayInOrder(Node<T> *node);
		void displayPreOrder(Node<T> *node);
		void displayPostOrder(Node<T> *node);
      	void displayTree(Node<T> *node, int tab);
		void insert(Node<T> *&node, const T &data);
		void insertTree(Node<T> *node);
		bool isExists(Node<T> *&node, const T &searchKey);
		void makeDeletion(Node<T> *&node);
		void remove(Node<T> *&node, const T &searchKey);

	public:
		BST();
		~BST();

		void insert(T data);
      	bool isEmpty();
		bool isExists(T searchKey);
		void remove(T searchKey);
		void showInOrder();
		void showPreOrder();
		void showPostOrder();
		void showTree();
};


template <class T>
BST<T>::BST()
{
	mRootNode = NULL;
}


template <class T>
BST<T>::BST(T data, Node<T> *left = NULL, Node<T> *right = NULL)
{
   Node<T> *newNode;

   newNode = new Node(data, left, right);
   if (newNode != NULL)
	   mRootNode = newNode;
}


template <class T>
BST<T>::~BST()
{
	destroySubtree(mRootNode);
}


template <class T>
void BST<T>::destroySubtree(Node<T> *node)
{
	if (node != NULL)
	{
		if (node->mLeft != NULL)
			destroySubtree(node->mLeft);

		if (node->mRight != NULL)
			destroySubtree(node->mRight);

		delete node;
	}
}


template <class T>
void BST<T>::displayInOrder(Node<T> *node)
{
	if (node != NULL)
	{
		if (node->mLeft != NULL)
			displayInOrder(node->mLeft);

		std::cout << node->mData;

		if (node->mRight != NULL)
			displayInOrder(node->mRight);
	}
}


template <class T>
void BST<T>::displayPreOrder(Node<T> *node)
{
	if (node != NULL)
	{
		std::cout << node->mData;

		if (node->mLeft != NULL)
			displayPreOrder(node->mLeft);

		if (node->mRight != NULL)
			displayPreOrder(node->mRight);
	}
}


template <class T>
void BST<T>::displayPostOrder(Node<T> *node)
{
	if (node != NULL)
	{
		if (node->mLeft != NULL)
			displayPostOrder(node->mLeft);

		if (node->mRight != NULL)
			displayPostOrder(node->mRight);

		std::cout << node->mData;
	}
}

template <class T>
void BST<T>::displayTree(Node<T> *node, int tab)
{
	if (node != NULL)
	{
		tab++;
		int i;
		for (i = 0; i < tab; i++)
			std::cout << "\t";

		std::cout << node->mData << std::endl;

		if (node->mLeft != NULL)
			displayTree(node->mLeft, tab);

		if (node->mRight != NULL)
			displayTree(node->mRight, tab);
	}
}

template <class T>
void BST<T>::showTree()
{
	displayTree(mRootNode, 0);
}


template <class T>
void BST<T>::insert(T data)
{
	// we will call the following function if we are
	// using recursive method, otherwise all functionality
	// should be self sustain here
	//insert(mRootNode, data);
	insert(mRootNode, data);
}


template <class T>
void BST<T>::insert(Node<T> *&node, const T &data)
{
	if (node == NULL)
	{
		node = new Node<T>(data);
		return;
	}
	else if (node->mData == data)
		return;
	else if(data < node->mData)
		insert(node->mLeft, data);
	else
		insert(node->mRight, data);
}


template <class T>
bool BST<T>::isEmpty()
{
   return (mRootNode == NULL);
}


template <class T>
bool BST<T>::isExists(T searchKey)
{
	return isExists(mRootNode, searchKey);
}

template <class T>
bool BST<T>::isExists(Node<T> *&node, const T &searchKey)
{
	if (node == NULL)
		return false;
	else if (node->mData > searchKey)
		isExists(node->mLeft, searchKey);
	else if (node->mData < searchKey)
		isExists(node->mRight, searchKey);
	else
		return true;
}


template <class T>
void BST<T>::makeDeletion(Node<T> *&node)
{
	Node<T> *insertNodes, *tmpTree = node;

	//We may need to change this to node->mRight = node->mRight;
	node = node->mRight;

	tmpTree->mRight = NULL;

	insertNodes = tmpTree->mLeft;
	tmpTree->mLeft = NULL;

	delete tmpTree;

	insertTree(insertNodes);
}

template <class T>
void BST<T>::insertTree(Node<T> *node)
{
	if (node != NULL) 
	{
		if (node->mLeft != NULL)
			insertTree(node->mLeft);
		
		insert(node->mData);
	
		if (node->mRight != NULL)
			insertTree(node->mRight);

		delete node;
	}
}

template <class T>
void BST<T>::remove(Node<T> *&node, const T &searchKey)
{
	if (node == NULL)
		return;
	else if (node->mData > searchKey)
		remove(node->mLeft, searchKey);
	else if (node->mData < searchKey)
		remove(node->mRight, searchKey);
	else
		// We have found the node to delete.
		makeDeletion(node);
}


template <class T>
void BST<T>::remove(T searchKey)
{
	// we will call the following function if we are
	// using recursive method, otherwise all functionality
	// should be self sustain here
	remove(mRootNode, searchKey);
}


template <class T>
void BST<T>::showInOrder()
{
	displayInOrder(mRootNode);
	std::cout << std::endl;
}


template <class T>
void BST<T>::showPreOrder()
{
	displayPreOrder(mRootNode);
	std::cout << std::endl;
}


template <class T>
void BST<T>::showPostOrder()
{
	displayPostOrder(mRootNode);
	std::cout << std::endl;
}



#endif