// Program Information ////////////////////////////////////////////////////////
/**
 * @file HeapClass.cpp
 *
 * @brief Implementation file for HeapClass
 * 
 * @details Implements all member actions for the HeapClass
 *
 * @author Philip Smith
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
* @brief Implementation of HeapClass addItem function
*
* @details Checks to see if rootNode is not null before calling addItemHelper
*
* @param KeyType and DataType
*
* @note Creates a root node if it does not find one.
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
* @brief Implementation of HeapClass addItemHelper function
*
* @details Finds the last element in the tree and creates a new node with the 
*	data given to it. Then calls the sortUp function to sort the new node according to
*	min heap laws.
*
* @param KeyType and DataType
*
* @note The size of the tree is first sent into a binary equivelent to the integer value.
*	It then takes that binary equivelent and uses it to go down the tree when the value
*	at a given index is 1 then the node goes right, if 0 then the node goes left (skips
*	first index since it is the binary equivelent to the height of the tree). Once the
*	node is inserted then it calls the sortUp function to sort the new value up the tree.
*/
template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::adder(HeapNode<KeyType, DataType> *node, const KeyType &newKey,const DataType &newData)
{
	int index, amount = size+1, digits = 0;
	while(amount != 0)
	{
	   amount = amount / 2;
	   digits++;
	}
	int *binary = new int[digits];
	amount = size+1;
	for(index = digits - 1; index >= 0; index--)
	{
		binary[index] = amount % 2;
		amount /= 2;
	}
	for(index = 1; index < digits; index++)
	{
		if(binary[index] == 0)
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
		else if(binary[index] == 1)
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
* @brief Implementation of HeapClass swap function
*
* @details Takes in two nodes and swaps their keyItems and dataItems
*
* @param HeapNode child, HeapNode parent
*
* @note NONE
*/
template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::swap(HeapNode<KeyType, DataType> *childNode, HeapNode<KeyType, DataType> *node)
{
	HeapNode<KeyType, DataType>* temp = new HeapNode<KeyType, DataType>(childNode->keyItem, childNode->dataItem,NULL, NULL, NULL);
	childNode->dataItem = node->dataItem;
	childNode->keyItem = node->keyItem;
	node->dataItem = temp->dataItem;
	node->keyItem = temp->keyItem;
}

/**
* @brief Implementation of HeapClass removeItem function
*
* @details Checks to see if rootNode is not null then sets
*	dataItem and keyItem paramaters to the rootNode values
*	before calling removeItemHelper
*
* @param KeyType and DataType
*
* @note Returns false if there is no rootNode
*/
template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::removeItem(DataType &returnedDataItem, KeyType &returnedKeyItem)
{
	if(!isEmpty())
	{
		returnedDataItem = rootNode->dataItem;
		returnedKeyItem = rootNode->keyItem;
		return removeItemHelper(rootNode);
	}
	return false;
}

/**
* @brief Implementation of HeapClass removeItemHelper function
*
* @details Takes in the root node and finds the last element in the binary tree
*	based on the size of the tree. Once the last element is found, the root node
*	is swapped with the element then the last element is deleted. After swapping
*	values, the rootNode is then thrown into the sortDown function to meet the min
*	heap properties.
*
* @param HeapNode
*
* @note Returns true if successfully deleting node
*/
template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::removeItemHelper(HeapNode<KeyType, DataType>* &node)
{
	int index, amount = size, digits = 0;
	HeapNode<KeyType, DataType> *root = node;
	while(amount != 0)
	{
	   amount /= 2;
	   digits++;
	}
	int *binary= new int[digits];
	amount = size;
	for(index = digits - 1; index >= 0; index--)
	{
		binary[index] = amount % 2;
		amount /= 2;
	}
	for(index = 1; index < digits; index++)
	{
		if(binary[index] == 0)
		{
			node = node->left;
		}
		else if(binary[index] == 1)
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

/**
* @brief Implementation of HeapClass sortUp function
*
* @details Used for the insertItemHelper function, is used to sort the node being
*	inserted up the tree to meet the min heap properties.
*
* @param HeapNode
*
* @note NONE
*/
template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::sortUp(HeapNode<KeyType, DataType>* node)
{
	HeapNode<KeyType, DataType>* temp = node;
	node = node->parent;
	if(node != NULL)
	{
		if(temp->keyItem < node->keyItem)
		{
			swap(temp, node);
		}
		sortUp(node);
	}
}

/**
* @brief Implementation of HeapClass sortUp function
*
* @details Used for the removeItemHelper function, is used to sort the node being
*	deleted down the tree to meet the min heap properties.
*
* @param HeapNode
*
* @note Checks to see if there is a left, right, or both children within the node.
*	If there is then it compares to see which child is smaller then compares the smallest
*	node to their parent to see if the min heap properties are met. If they aren't then
*	the nodes are swapped and the function is recursively called again.
*/
template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::sortDown(HeapNode<KeyType, DataType>* node)
{
	if(node->left != NULL && node->right != NULL)
	{
		if(node->left->keyItem < node->right->keyItem)
		{
			if(node->keyItem > node->left->keyItem)
			{
				swap(node->left, node);
				sortDown(node->left);
			}
		}
		else 
		{
			if(node->keyItem > node->right->keyItem)
			{
				swap(node->right, node);
				sortDown(node->right);
			}
		}
	}
	else if(node->left != NULL)
	{
		if(node->keyItem > node->left->keyItem)
		{
			swap(node->left, node);
			sortDown(node->left);
		}
	}
	else if(node->right != NULL)
	{
		if(node->keyItem > node->right->keyItem)
		{
			swap(node->right, node);
			sortDown(node->right);
		}
	}
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
