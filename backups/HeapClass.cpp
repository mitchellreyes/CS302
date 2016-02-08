// Program Information ////////////////////////////////////////////////////////
/**
 * @file HeapClass.cpp
 *
 * @brief Implementation file for HeapClass
 * 
 * @details Implements all member actions for the HeapClass
 *
 * @author Michael Leverington
 *
 * @version 1.00 (30 October 2015)
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
HeapNode<KeyType, DataType>::HeapNode(
				const KeyType &nodeKey,   // in: key value
				const DataType &nodeData, // in: data value
				HeapNode *parentPtr,      // in: parent pointer
				HeapNode *leftPtr,         // in: left node pointer
				HeapNode *rightPtr         // in: right node pointer
			 )
		 : keyItem( nodeKey ), dataItem( nodeData ), parent( parentPtr ), 
			 left( leftPtr ), right( rightPtr )
	 {
		// data placed in initializers
	 }

template<typename KeyType, typename DataType>
HeapClass<KeyType, DataType>::HeapClass
			 (
				// no parameters
			 )
		 : rootNode( NULL )
	 {
		// data placed in initializers
	 }
					 
template<typename KeyType, typename DataType>
HeapClass<KeyType, DataType>::HeapClass
			 ( 
				const HeapClass<KeyType, DataType> &copied 
			 )
		 : rootNode( NULL )
	 {
		copyTree( copied );
	 }

template<typename KeyType, typename DataType>
HeapClass<KeyType, DataType>::~HeapClass
			 (
				// no parameters
			 )
	 {
		clearTree();
	 }

template<typename KeyType, typename DataType>
const HeapClass<KeyType, DataType>& HeapClass<KeyType, DataType>:: operator = 
																										( const HeapClass &rhTree )
	 {
		if( this != &rhTree ) 
			 {
				clearTree();
				copyTree( rhTree );
			 }

		return *this;
	 }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::copyTree
			 ( 
				const HeapClass<KeyType, DataType> &copiedTree 
			 )
	 {
		copyTreeHelper( rootNode, NULL, copiedTree.rootNode );
	 }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::clearTree
			 (       
				// no parameters
			 )
	 {
		clearTreeHelper( rootNode );

		rootNode = NULL;
	 }
/////////////////////////add this///////////////////////////////////////////////////////////////////////
template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::addItem(const KeyType &newKey,const DataType &newData)
{
	if(rootNode != NULL)
	{
		addItemHelper(rootNode, newKey, newData);
	}
	else
	{
		rootNode = new HeapNode<KeyType, DataType>(newKey, newData, NULL, NULL, NULL);
		size = 1;
	}
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::addItemHelper(HeapNode<KeyType, DataType> *node, const KeyType &newKey,const DataType &newData) 
{
	int index, amount = size+1, digits = 0;
	while(amount != 0) 
	{
	   amount = amount / 2;
	   digits++;
	}
	int binary[digits];
	amount = size+1;
	for(index = digits - 1; index >= 0; index--) 
	{
		binary[index] = amount % 2;
		amount = amount /2;
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
				HeapNode<KeyType, DataType>* temp = node->left;
				while(node != NULL)
				{
					if(temp->keyItem < node->keyItem)
					{
						swap(temp, node);
					}
					temp = temp->parent;
					node = node->parent;
				}
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
				HeapNode<KeyType, DataType>* temp = node->right;
				while(node != NULL)
				{
					if(temp->keyItem < node->keyItem)
					{
						swap(temp, node);
					}
					temp = temp->parent;
					node = node->parent;
				}
			}
		}
	}
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::swap(HeapNode<KeyType, DataType> *childNode, HeapNode<KeyType, DataType> *node)
{
	HeapNode<KeyType, DataType>* temp = new HeapNode<KeyType, DataType>(childNode->keyItem, childNode->dataItem,NULL, NULL, NULL);
	childNode->dataItem = node->dataItem;
	childNode->keyItem = node->keyItem;
	node->dataItem = temp->dataItem;
	node->keyItem = temp->keyItem;
}

template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::removeItem(DataType &returnedDataItem, KeyType &returnedKeyItem )
{
	if(isEmpty())
	{
		return false;
	}
	else
	{
		returnedDataItem = rootNode->dataItem;
		returnedKeyItem = rootNode->keyItem;
		replaceRoot(rootNode);
		sortAfterDelete(rootNode);
		return true;
	}
}


template <typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::replaceRoot(HeapNode<KeyType, DataType>* &root)
{
	if(root->left == NULL && root->right == NULL)
	{
		//rootNode = root;
		//delete *root;
		//root = NULL;
		return;
	}
	else if(getHeightHelper(root, 'L') <= getHeightHelper(root, 'R'))
	{
		replaceRoot(root->right);
	}
	else if(getHeightHelper(root, 'L') > getHeightHelper(root, 'R'))
	{
		replaceRoot(root->left);
	}
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::sortAfterDelete(HeapNode<KeyType, DataType>* &root)
{
	if(root->right == NULL && root->left == NULL)
	{
		return;
	}
	HeapNode<KeyType, DataType> *tmp;
	if(root->right != NULL && root->left != NULL)
	{
		
		if(root->left->dataItem.compareTo(root->right->dataItem) < 0) //if left is less than right
		{
			tmp = root;
			root = root->left;
			root->left = tmp;
			sortAfterDelete(root->left);	
		}
		else if(root->left->dataItem.compareTo(root->right->dataItem) > 0) //if left is greater than right
		{
			tmp = root;
			root = root->right;
			root->right = tmp;
			sortAfterDelete(root->right);	
		}	
	}

	//one child
	else if(root->right != NULL && root->left == NULL)
	{
		if(root->right->dataItem.compareTo(root->dataItem) < 0) //if the one child is less than the parent
		{
			tmp = root;
			root = root->right;
			root->right = tmp;
			sortAfterDelete(root->right);
		}
		else
		{
			return;
		}
	}
	else if(root->right == NULL && root->left != NULL)
	{
		if(root->left->dataItem.compareTo(root->dataItem) < 0) //if the one child is less than the parent
		{
			tmp = root;
			root = root->left;
			root->left = tmp;
			sortAfterDelete(root->left);
		}
		else
		{
			return;
		}	
	}
	

}

///////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::isEmpty
			 ( 
				// no parameters
			 ) const
	 {
		return ( rootNode == NULL );
	 }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::preOrderTraversal
			 (
				// no parameters
			 ) const
	 {
		if( rootNode != NULL )
			 {
				preOrderTraversalHelper( rootNode );
				cout << endl;
			 }

		else
			 {
				cout << "Tree is empty" << endl;
			 }
	 }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::inOrderTraversal
			 (
				// no parameters
			 ) const
	 {
		if( rootNode != NULL )
			 {
				inOrderTraversalHelper( rootNode );
				cout << endl;
			 }

		else
			 {
				cout << "Tree is empty" << endl;
			 }
	 }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::postOrderTraversal
			 (
				// no parameters
			 ) const
	 {
		if( rootNode != NULL )
			 {
				postOrderTraversalHelper( rootNode );
				cout << endl;
			 }

		else
			 {
				cout << "Tree is empty" << endl;
			 }
	 }

template<typename KeyType, typename DataType>
int HeapClass<KeyType, DataType>::getLeftHeight
			 (
				// no parameters
			 ) const
	 {
		return getHeightHelper( rootNode, 'L' );
	 }

template<typename KeyType, typename DataType>
int HeapClass<KeyType, DataType>::getRightHeight
			 (
				// no parameters
			 ) const
	 {
		return getHeightHelper( rootNode, 'R' );
	 }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::showStructure
			 ( 
				// no parameters
			 ) const
	 {
		int height = getLeftHeight();

		if( rootNode != NULL )
			 {
				showStructureHelper( rootNode, height, 0 );

				cout << endl << "Left Height: " << getLeftHeight() 
						 << ", Right Height: "  << getRightHeight() << endl;
			 }

		else
			 {
				cout << "Empty Tree" << endl;
			 }

		cout << endl;
	 }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::showStructureHelper
			 ( 
				HeapNode<KeyType, DataType> *workingPtr,
				int fullHeight,
				int presentHeight
			 ) const
	 {
		char patientName[ MAX_STR_LEN ], medicalCode[ MAX_STR_LEN ];
		char patientGender;

		if( workingPtr != NULL )
			 {
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
int HeapClass<KeyType, DataType>::getHeightHelper
			 (
				HeapNode<KeyType, DataType> *workingPtr,
				char leftRightIndicator
			 ) const
	 {
		if( workingPtr != NULL )
			 {
				if( leftRightIndicator == 'L' )
					 {
						return 1 + getHeightHelper( workingPtr->left, leftRightIndicator );
					 }

				return 1 + getHeightHelper( workingPtr->right, leftRightIndicator );
			 }

		return 0;
	 }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::copyTreeHelper
			 ( 
				HeapNode<KeyType, DataType> *&workingPtr,      // local working pointer
				HeapNode<KeyType, DataType> *parentPtr,      // local parent pointer
				const HeapNode<KeyType, DataType> *sourcePtr  // incoming source pointer
			 )
	 {
		if( sourcePtr != NULL )
			 {
				workingPtr = new HeapNode<KeyType, DataType>( sourcePtr->keyItem, 
																	sourcePtr->dataItem, parentPtr, NULL, NULL );
				copyTreeHelper( workingPtr->left, workingPtr, sourcePtr->left );
				copyTreeHelper( workingPtr->right, workingPtr, sourcePtr->right );
			 }
	 }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::clearTreeHelper
			 ( 
				HeapNode<KeyType, DataType> *workingPtr 
			 )
	 {
		if ( workingPtr != NULL )
			 {
				clearTreeHelper( workingPtr->left );
				clearTreeHelper( workingPtr->right );
				delete workingPtr;
			 }
	 }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::preOrderTraversalHelper
			 ( 
				HeapNode<KeyType, DataType> *workingPtr 
			 ) const
	 {
		char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
		int acctNum;

		if( workingPtr != NULL )
			 {
				workingPtr->dataItem.getAccount( acctName, acctNum, acctType );

				cout << acctName << endl;

				preOrderTraversalHelper( workingPtr->left );

				preOrderTraversalHelper( workingPtr->right );
			 }
	 }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::inOrderTraversalHelper
			 ( 
				HeapNode<KeyType, DataType> *workingPtr 
			 ) const
	 {
		char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
		int acctNum;

		if( workingPtr != NULL )
			 {
				inOrderTraversalHelper( workingPtr->left );
	 
				workingPtr->dataItem.getAccount( acctName, acctNum, acctType );
		
				cout << acctName << endl;

				inOrderTraversalHelper( workingPtr->right );
			 }
	 }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::postOrderTraversalHelper
			 ( 
				HeapNode<KeyType, DataType> *workingPtr 
			 ) const
	 {
		char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
		int acctNum;

		if( workingPtr != NULL )
			 {
				postOrderTraversalHelper( workingPtr->left );

				postOrderTraversalHelper( workingPtr->right );

				workingPtr->dataItem.getAccount( acctName, acctNum, acctType );

				cout << acctName << endl;
			 }
	 }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::showTabs 
			 ( 
				int numTabs 
			 ) const
	 {
		int counter;

		for( counter = 0; counter < numTabs; counter++ )
			 {
				cout << TAB;
			 }
	 }

#endif	// define HEAP_CLASS_CPP


