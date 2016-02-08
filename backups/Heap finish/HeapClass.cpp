// Program Information ////////////////////////////////////////////////////////
/**
 * @file HeapClass.cpp
 *
 * @brief Implementation file for HeapClass
 * 
 * @details Implements all member actions for the HeapClass
 *
 * @author Mitchell Reyes
 *
 * @version 1.00 (12 November 2015)
 *
 * @Note Requires HeapClass.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef HEAP_CLASS_CPP
#define HEAP_CLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "HeapClass.h"
#include <new>

using namespace std;

// Class Implementation  //////////////////////////////////////////////////////

template<typename KeyType, typename DataType>
HeapNode<KeyType, DataType>::HeapNode(const KeyType &nodeKey, const DataType &nodeData, HeapNode *parentPtr, HeapNode *leftPtr, HeapNode *rightPtr): keyItem( nodeKey ), dataItem( nodeData ), parent( parentPtr ), left( leftPtr ), right( rightPtr ) {
}

template<typename KeyType, typename DataType>
HeapClass<KeyType, DataType>::HeapClass(): rootNode( NULL ) {
}

template<typename KeyType, typename DataType>
HeapClass<KeyType, DataType>::HeapClass
(const HeapClass<KeyType, DataType> &copied): rootNode( NULL ){
	copyTree( copied );
}

template<typename KeyType, typename DataType>
HeapClass<KeyType, DataType>::~HeapClass() {
	clearTree();
}

template<typename KeyType, typename DataType>
const HeapClass<KeyType, DataType>& HeapClass<KeyType, DataType>:: operator = ( const HeapClass &rhTree ) {
	if( this != &rhTree ) {
		clearTree();
		copyTree( rhTree );
	}
	return *this;
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::copyTree(const HeapClass<KeyType, DataType> &copiedTree) {
	copyTreeHelper( rootNode, NULL, copiedTree.rootNode );
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::clearTree() {
	clearTreeHelper( rootNode );
	rootNode = NULL;
}

/**
* @brief Implementation of addItem function
*
* @details Calls the add help if the heap isn't empty
*
* @param newKey and newData
*
* @note Adds to the rightmost, bottom node
*/
template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::addItem(const KeyType &newKey,const DataType &newData)
{
	if(!isEmpty()) 
	{
		adder(rootNode, newKey, newData);
	}
	else 
	{
		rootNode = new HeapNode<KeyType, DataType>(newKey, newData, NULL, NULL, NULL);
		size = 1;
	}
}

/**
* @brief Implementation of HeapClass adder function
*
* @details Adds an element to an open spot on the bottom most part of the heap
*
* @param KeyType and DataType
*
* @note compares tree sizes and given back an int, once it hits a 1, then it will traverse right and insert at an open area
*/
template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::adder(HeapNode<KeyType, DataType> *node, const KeyType &newKey,const DataType &newData)
{
	int index; 
	int amount = size+1; 
	int digits = 0;
	while(amount != 0)
	{
	   amount = amount / 2;
	   digits++;
	}
	int *solver = new int[digits];
	amount = size+1;
	for(index = digits - 1; index >= 0; index--)
	{
		solver[index] = amount % 2;
		amount /= 2;
	}
	for(index = 1; index < digits; index++)
	{
		if(solver[index] == 0)
		{
			if(node->left != NULL)
			{
				node = node->left;
			}
			else
			{
				size++;
				node->left = new HeapNode<KeyType, DataType>(newKey, newData, node, NULL, NULL);
				sortUp(node->left);
			}
		}
		else if(solver[index] == 1)
		{
			if(node->right != NULL)
			{
				node = node->right;
			}
			else
			{
				size++;
				node->right = new HeapNode<KeyType, DataType>(newKey, newData, node, NULL, NULL);
				sortUp(node->right);
			}
		}
	}
}


/**
* @brief Implementation of sortUp function
*
* @details Used to sort the tree after something gets inserted
*
* @param HeapNode
*
* @note NONE
*/
template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::sortUp(HeapNode<KeyType, DataType>* root)
{
	HeapNode<KeyType, DataType>* temp = root;
	root = root->parent;
	if(root != NULL)
	{
		if(temp->keyItem < root->keyItem)
		{
			swap(temp, root);
		}
		sortUp(root);
	}
}


/**
* @brief Implementation sortUp function
*
* @details Used to sort the heap back to a priority when something is removed
*
* @param HeapNode
*
* @note compares the keytypes of the left and right node, takes the smallest one and compares it against the parent. If the parent is larger, then it swaps.
*/
template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::sortDown(HeapNode<KeyType, DataType>* root)
{
	if(root->left != NULL && root->right != NULL)
	{
		if(root->left->keyItem < root->right->keyItem)
		{
			if(root->keyItem > root->left->keyItem)
			{
				swap(root->left, root);
				sortDown(root->left);
			}
		}
		else 
		{
			if(root->keyItem > root->right->keyItem)
			{
				swap(root->right, root);
				sortDown(root->right);
			}
		}
	}
	else if(root->left != NULL)
	{
		if(root->keyItem > root->left->keyItem)
		{
			swap(root->left, root);
			sortDown(root->left);
		}
	}
	else if(root->right != NULL)
	{
		if(root->keyItem > root->right->keyItem)
		{
			swap(root->right, root);
			sortDown(root->right);
		}
	}
}


/**
* @brief Implementation of swap function
*
* @details swaps two nodes
*
* @param HeapNode child, HeapNode parent
*
* @note NONE
*/
template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::swap(HeapNode<KeyType, DataType> *childNode, HeapNode<KeyType, DataType> *parentNode)
{
	HeapNode<KeyType, DataType>* temp = new HeapNode<KeyType, DataType>(childNode->keyItem, childNode->dataItem,NULL, NULL, NULL);
	childNode->dataItem = parentNode->dataItem;
	childNode->keyItem = parentNode->keyItem;
	parentNode->dataItem = temp->dataItem;
	parentNode->keyItem = temp->keyItem;
}

/**
* @brief Implementation of removeItem function
*
* @details Finds the bottom most right node
*
* @param KeyType and DataType
*
* @note NONE
*/
template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::removeItem(DataType &returnedDataItem, KeyType &returnedKeyItem)
{
	if(!isEmpty())
	{
		returnedDataItem = rootNode->dataItem;
		returnedKeyItem = rootNode->keyItem;
		return removeHelp(rootNode);
	}
	return false;
}

/**
* @brief Implementation removeHelp function
*
* @details Finds the bottom most right node, removes it, then sorts the heap back
*
* @param HeapNode
*
* @note Returns true if successful of deleting a node
*/
template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::removeHelp(HeapNode<KeyType, DataType>* &node)
{
	int index, amount = size, digits = 0;
	HeapNode<KeyType, DataType> *root = node;
	while(amount != 0)
	{
	   amount /= 2;
	   digits++;
	}
	int *solver= new int[digits];
	amount = size;
	for(index = digits - 1; index >= 0; index--)
	{
		solver[index] = amount % 2;
		amount /= 2;
	}
	for(index = 1; index < digits; index++)
	{
		if(solver[index] == 0)
		{
			node = node->left;
		}
		else if(solver[index] == 1)
		{
			node = node->right;
		}
	}
	swap(node, root);
	node = node->parent;
	if(node->right != NULL)
	{
		delete node->right;
		node->right = NULL;
	}
	else
	{
		delete node->left;
		node->left = NULL;
	}
	node = root;
	size--;
	sortDown(node);
	return true;
}


template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::isEmpty() const {
	return ( rootNode == NULL );
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::preOrderTraversal() const {
	if( rootNode != NULL ) {
		preOrderTraversalHelper( rootNode );
		cout << endl;
	}
	else {
		cout << "Tree is empty" << endl;
	}
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::inOrderTraversal() const {
	if( rootNode != NULL ) {
		inOrderTraversalHelper( rootNode );
		cout << endl;
	}
	else {
		cout << "Tree is empty" << endl;
	}
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::postOrderTraversal() const {
	if( rootNode != NULL ) {
		postOrderTraversalHelper( rootNode );
		cout << endl;
	}
	else {
		cout << "Tree is empty" << endl;
	}
}

template<typename KeyType, typename DataType>
int HeapClass<KeyType, DataType>::getLeftHeight() const {
	return getHeightHelper( rootNode, 'L' );
}

template<typename KeyType, typename DataType>
int HeapClass<KeyType, DataType>::getRightHeight() const {
	return getHeightHelper( rootNode, 'R' );
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::showStructure() const {
	int height = getLeftHeight();
	if( rootNode != NULL ) {
		showStructureHelper( rootNode, height, 0 );
		cout << endl << "Left Height: " << getLeftHeight() 
		<< ", Right Height: "  << getRightHeight() << endl;
	}
	else {
		cout << "Empty Tree" << endl;
	}
	cout << endl;
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::showStructureHelper( HeapNode<KeyType, DataType> *workingPtr,int fullHeight,int presentHeight) const {
	char patientName[ MAX_STR_LEN ], medicalCode[ MAX_STR_LEN ];
	char patientGender;

	if( workingPtr != NULL ) {
		showStructureHelper( workingPtr->left, fullHeight, presentHeight + 1 );

		cout << endl;
		showTabs( fullHeight - presentHeight );

		workingPtr->dataItem.getAccount( patientName, medicalCode, patientGender );

		cout << patientName;

		cout << ", " << int( workingPtr->keyItem ) << endl;

		showStructureHelper( workingPtr->right, fullHeight, presentHeight + 1 );
	}
}

template<typename KeyType, typename DataType>
int HeapClass<KeyType, DataType>::getHeightHelper(HeapNode<KeyType, DataType> *workingPtr, char leftRightIndicator) const {
	if( workingPtr != NULL ) {
		if( leftRightIndicator == 'L' ) {
			return 1 + getHeightHelper( workingPtr->left, leftRightIndicator );
		}
		return 1 + getHeightHelper( workingPtr->right, leftRightIndicator );
	}
	return 0;
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::copyTreeHelper(HeapNode<KeyType, DataType> *&workingPtr, HeapNode<KeyType, DataType> *parentPtr, const HeapNode<KeyType, DataType> *sourcePtr) {
	if( sourcePtr != NULL ) {
		workingPtr = new HeapNode<KeyType, DataType>( sourcePtr->keyItem, sourcePtr->dataItem, parentPtr, NULL, NULL );
		copyTreeHelper( workingPtr->left, workingPtr, sourcePtr->left );
		copyTreeHelper( workingPtr->right, workingPtr, sourcePtr->right );
	}
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::clearTreeHelper(HeapNode<KeyType, DataType> *workingPtr) {
	if ( workingPtr != NULL ) {
		clearTreeHelper( workingPtr->left );
		clearTreeHelper( workingPtr->right );
		delete workingPtr;
	}
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::preOrderTraversalHelper(HeapNode<KeyType, DataType> *workingPtr) const {
	char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
	int acctNum;
	if( workingPtr != NULL ) {
		workingPtr->dataItem.getAccount( acctName, acctNum, acctType );

		cout << acctName << endl;

		preOrderTraversalHelper( workingPtr->left );

		preOrderTraversalHelper( workingPtr->right );
	}
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::inOrderTraversalHelper(HeapNode<KeyType, DataType> *workingPtr) const {
	char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
	int acctNum;

	if( workingPtr != NULL ) {
		inOrderTraversalHelper( workingPtr->left );

		workingPtr->dataItem.getAccount( acctName, acctNum, acctType );

		cout << acctName << endl;

		inOrderTraversalHelper( workingPtr->right );
	}
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::postOrderTraversalHelper(HeapNode<KeyType, DataType> *workingPtr) const {
	char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
	int acctNum;
	if(workingPtr != NULL) {
		postOrderTraversalHelper( workingPtr->left );

		postOrderTraversalHelper( workingPtr->right );

		workingPtr->dataItem.getAccount( acctName, acctNum, acctType );

		cout << acctName << endl;
	}
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::showTabs(int numTabs) const {
	int counter;
	for( counter = 0; counter < numTabs; counter++ ) {
		cout << TAB;
	}
}

#endif	// define HEAP_CLASS_CPP