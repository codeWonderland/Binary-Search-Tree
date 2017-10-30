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
}


template <class T>
void BST<T>::displayInOrder(Node<T> *node)
{
}


template <class T>
void BST<T>::displayPreOrder(Node<T> *node)
{
}


template <class T>
void BST<T>::displayPostOrder(Node<T> *node)
{
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
		Node<T> *newNode = new Node<T>(data);
		node = newNode;
	}
	else
	{
		if(data < node->mData)
		{
			insert(node->mLeft, data);
		}
		else
		{
			insert(node->mRight, data);
		}
	}
}


template <class T>
bool BST<T>::isEmpty()
{
   return (mRootNode == NULL);
}


template <class T>
bool BST<T>::isExists(T searchKey)
{
	Node<T> *tmp;
	bool found = false;

	tmp = mRootNode;

	if (mRootNode->mData == searchKey)
		return true;

	while (!found)
	{
		if (tmp->mData == searchKey)
			found = true;

		else if (tmp != NULL)
		{
			if (tmp->mData < searchKey)
				tmp = tmp->mRight;

			else
				tmp = tmp->mLeft;
		}
		else
		{
			delete tmp;
			return false;
		}
	}

	delete tmp;
	return found;
}


template <class T>
void BST<T>::makeDeletion(Node<T> *&node)
{
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
	//remove(mRootNode, searchKey);
}


template <class T>
void BST<T>::showInOrder()
{
	displayInOrder(mRootNode);
}


template <class T>
void BST<T>::showPreOrder()
{
	displayPreOrder(mRootNode); 
}


template <class T>
void BST<T>::showPostOrder()
{
	displayPostOrder(mRootNode);
}



#endif