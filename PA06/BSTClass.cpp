#include "BSTClass.h"
#include "NameType.h"
#include <iostream>
using namespace std;


/**
 * @brief Default constructor for the node
 *
 * @details Constructs a node with data, left, and a right ptr
 *          
 * @param in: nodeData, leftPtr, right ptr
 *
 * @note takes the values from the parameters and sets them to the node values
 */
template <typename DataType>
BSTNode<DataType>::BSTNode(const DataType &nodeData, BSTNode *leftPtr, BSTNode *rightPtr)
{
	left = leftPtr;
	right = rightPtr;
	dataItem = nodeData;
}


/**
 * @brief Default constructor for the tree
 *
 * @details Constructs empty tree
 *          
 * @param None
 *
 * @note None
 */
template <typename DataType>
BSTClass<DataType>::BSTClass()
{
	rootNode = NULL;
}

/**
 * @brief Copy contstructor for the tree
 *
 * @details Creates a copy of a tree that is given in the parameter
 *          
 * @param in: a BSTClass waiting to be copied
 *
 * @note uses the overloaded assignment operator to create a tree with copied values
 */
template <typename DataType>
BSTClass<DataType>::BSTClass( const BSTClass<DataType> &copied )
{
	rootNode = NULL;
	*this = copied;
}

/**
 * @brief Deconstructor for the BSTClass
 *
 * @details deletes the tree
 *          
 * @param None
 *
 * @note None
 */
template <typename DataType>
BSTClass<DataType>::~BSTClass()
{
	clearTree();
}

/**
 * @brief Overloaded assignment operator
 *
 * @details copies a tree to another created tree
 *          
 * @param in: another tree
 *
 * @note Uses copyTree to allocate new nodes to another created tree to copy the param
 */
template <typename DataType>
const BSTClass<DataType> &BSTClass<DataType>::operator = (const BSTClass<DataType> &rhData)
{
	if(rootNode != NULL)
	{
		clearTree();
	}
	copyTree(rhData);
	return *this;
}

/**
 * @brief Copies a tree
 *
 * @details Makes one tree to another
 *          
 * @param in: another tree
 *
 * @note uses a helper to accomplish the task
 */
template <typename DataType>
void BSTClass<DataType>::copyTree(const BSTClass<DataType> &copied)
{
	copyHelper(copied.rootNode);
}

/**
 * @brief Helps the copy function
 *
 * @details deallocates and allocates nodes from one tree to another
 *          
 * @param in: a node from a tree to start on
 *
 * @note keeps inserting data to one tree from another 
 */
template <typename DataType>
void BSTClass<DataType>::copyHelper(BSTNode<DataType> *copied) //add to private
{
	if(copied != NULL)
	{
		insert(copied->dataItem);
		copyHelper(copied->left);
		copyHelper(copied->right);
	}
}

/**
 * @brief Clears a tree
 *
 * @details destroys a tree
 *          
 * @param None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::clearTree()
{
	clearHelper(rootNode);
}

/**
 * @brief Helps clear function
 *
 * @details deallocates a whole tree
 *          
 * @param in: a node to start on
 *
 * @note traverses until it finds a leaf, deletes the leaf, then destroys the parent
 */
template<typename DataType>
void BSTClass<DataType>::clearHelper(BSTNode<DataType>* &rootPtr) //add to private
{
	if(rootPtr != NULL)
	{
		clearHelper(rootPtr->left);
		clearHelper(rootPtr->right);

		delete rootPtr;
		rootPtr = NULL;
	}
}

/**
 * @brief Insertion operator
 *
 * @details Inserts new data into the tree
 *          
 * @param in: newData
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::insert(const DataType &newData)
{
	
	if(rootNode == NULL)
	{
		rootNode = new BSTNode<DataType>(newData, NULL, NULL);
	}
	else
	{
		insertHelper(rootNode, newData);
	}

}

/**
 * @brief Helps the insert function
 *
 * @details recursion for the insert
 *          
 * @param in: a node to start, and the data given
 *
 * @note checks the data against a parent, if larger moves right, else moves left, keeps moving until it finds a null pointer
 */
template <typename DataType>
void BSTClass<DataType>::insertHelper(BSTNode<DataType> *rootPtr, const DataType& newData ) //add to private
{
	if(newData.compareTo(rootPtr->dataItem) < 0)
	{
		if(rootPtr->left == NULL)
		{
			rootPtr->left = new BSTNode<DataType>(newData, NULL, NULL);
			return;
		}
		else
		{
			insertHelper(rootPtr->left, newData);
		}
	}
	else
	{
		if(rootPtr->right == NULL)
		{
			rootPtr->right = new BSTNode<DataType>(newData, NULL, NULL);
			return;
		}
		else
		{
			insertHelper(rootPtr->right, newData);
		}
	}
}

template <typename DataType>
bool BSTClass<DataType>::findItem(const DataType &searchDataItem) const
{
	return false;
}


template <typename DataType>
bool BSTClass<DataType>::removeItem(const DataType &dataItem)
{
	return false;
}

/**
 * @brief Empty tree
 *
 * @details checks if the tree is empty
 *          
 * @param None
 *
 * @note checks if the root node is NULL
 */
template <typename DataType>
bool BSTClass<DataType>::isEmpty() const
{
	return rootNode == NULL;
}

/**
 * @brief prints the order of the tree
 *
 * @details Uses a recursive helper
 *          
 * @param None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::preOrderTraversal() const
{
	preHelp(rootNode);
}

/**
 * @brief Prints the tree 
 *
 * @details Print me, then left, then right
 *          
 * @param in: a root to start on
 *
 * @note recursively calls until it hits the left and right most nodes
 */
template <typename DataType>
void BSTClass<DataType>::preHelp(BSTNode<DataType> *root) const //add to private
{
	if(isEmpty())
	{
		cout << "Tree is empty" << endl;
	}
	else if(root)
	{
		cout << root->dataItem << endl;
		preHelp(root->left);
		preHelp(root->right); 
	}
}

/**
 * @brief Prints the tree 
 *
 * @details Print tree in certain order
 *          
 * @param None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::inOrderTraversal() const
{
	inOrderHelp(rootNode);
}

/**
 * @brief Prints the tree 
 *
 * @details Print left, then me, then right
 *          
 * @param in: a root to start on
 *
 * @note recursively calls until it hits the left and right most nodes
 */
template <typename DataType>
void BSTClass<DataType>::inOrderHelp(BSTNode<DataType> *root) const //add to private
{
	if(isEmpty())
	{
		cout << "Tree is empty" << endl;
	}
	else if(root != NULL)
	{
		inOrderHelp(root->left);
		cout << root->dataItem << endl;
		inOrderHelp(root->right);
	} 
}

/**
 * @brief Prints the tree 
 *
 * @details Prints tree in certain order
 *          
 * @param None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::postOrderTraversal() const
{
	postHelp(rootNode);
}

/**
 * @brief Prints the tree 
 *
 * @details Print left, then right, then me
 *         
 * @param in: a root to start on
 *
 * @note recursively calls until it hits the left and right most nodes
 */
template <typename DataType>
void BSTClass<DataType>::postHelp(BSTNode<DataType> *root) const //add to private
{
	if(isEmpty())
	{
		cout << "Tree is empty" << endl;
	}
	else if(root != NULL)
	{
		postHelp(root->left);
		postHelp(root->right);
		cout << root->dataItem << endl;
	}
	
}
/**
 * @brief Height of the tree 
 *
 * @details returns the height of the tree
 *          
 * @param None
 *
 * @note None
 */
template <typename DataType>
int BSTClass<DataType>::getHeight() const
{
	return heightHelp(rootNode);
}

/**
 * @brief Helps the height 
 *
 * @details Finds the height of a tree
 *          
 * @param in: a root to start on
 *
 * @note recursively calls until it hits the left and right, then compares the 2 values
 */
template <typename DataType>
int BSTClass<DataType>::heightHelp(BSTNode<DataType> *root) const //add to private
{
	if(root == NULL)
	{
		return 0;
	}
	int l = heightHelp(root->left);
	int r = heightHelp(root->right);
	if(l > r || l == r)
	{
		return (l + 1);
	}
	else
	{
		return (r + 1);
	}
}

/**
 * @brief Prints the tree 
 *
 * @details Prints the tree in order
 *          
 * @param None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::showStructure() const
{
	if(isEmpty())
	{
		cout << "Tree is empty" << endl;
		return;
	}
	cout << endl;
	showHelp(rootNode, getHeight());

}

/**
 * @brief Prints the tree 
 *
 * @details Prints the tree to show the children of it
 *          
 * @param in: a root to start on
 *
 * @note recursively calls until it hits the left and right most nodes to print
 */
template <typename DataType>
void BSTClass<DataType>::showHelp(BSTNode<DataType> *root, int tabs) const
{	
	int tabHelpLeft;
	if(root != NULL)
	{
		showHelp(root->left, tabs-1);
		for(tabHelpLeft = 0; tabHelpLeft < tabs; tabHelpLeft++)
		{
			cout << TAB;
		}
		cout << root->dataItem << endl << endl;
		showHelp(root->right, tabs-1);
	}
}
