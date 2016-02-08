// Program Information ////////////////////////////////////////////////////////
/**
 * @file NameType.cpp
 *
 * @brief Implementation file for NameType class
 * 
 * @details Implements the constructor method of the NameType class
 *
 * @author Michael Leverington
 *
 * @version 1.00 (03 October 2015)
 *
 * @Note Requires NameType.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef BST_CLASS_CPP
#define BST_CLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "BSTClass.h"
#include <new>

using namespace std;

// Class Implementation  //////////////////////////////////////////////////////

template<typename DataType>
BSTNode<DataType>::BSTNode
       (
        const DataType &nodeData, // in: data value
        BSTNode *leftPtr,         // in: left node pointer
        BSTNode *rightPtr         // in: right node pointer
       )
     : dataItem( nodeData ), left( leftPtr ), right( rightPtr )
   {
    // data placed in initializers
   }

template<typename DataType>
BSTClass<DataType>::BSTClass
       (
        // no parameters
       )
     : rootNode( NULL )
   {
    // data placed in initializers
   }
           
template<typename DataType>
BSTClass<DataType>::BSTClass
       ( 
        const BSTClass<DataType> &copied 
       )
     : rootNode( NULL )
   {
    copyTree( copied );
   }

template<typename DataType>
BSTClass<DataType>::~BSTClass
       (
        // no parameters
       )
   {
    clearTree();
   }

template <typename DataType>
const BSTClass<DataType>& BSTClass<DataType>:: operator = 
                                                    ( const BSTClass &rhTree )
   {
    if( this != &rhTree ) 
       {
        clearTree();
        copyTree( rhTree );
       }

    return *this;
   }

template<typename DataType>
void BSTClass<DataType>::copyTree
       ( 
        const BSTClass<DataType> &copiedTree 
       )
   {
    copyTreeHelper( rootNode, copiedTree.rootNode );
   }

template<typename DataType>
void BSTClass<DataType>::clearTree
       (       
        // no parameters
       )
   {
    clearTreeHelper( rootNode );

    rootNode = NULL;
   }

template <typename DataType>
void BSTClass<DataType>::insert
       ( 
        const DataType &newData 
       )
   {
    insertHelper( rootNode, newData);
   }

////////////////////////////// to be implemented //////////////////////////////
template <typename DataType>
bool BSTClass<DataType>::findItem( DataType &dataItem ) const
{
  return findHelper(rootNode, dataItem);
}

template <typename DataType>
bool BSTClass<DataType>::findHelper(BSTNode<DataType> *ptr, DataType &dataItem) const
{
  if(ptr != NULL)
  {
    if(dataItem.compareTo(ptr->dataItem) == 0)
    {
      return true;
    }
    if(dataItem.compareTo(ptr->dataItem) < 0)
    {
      return findHelper(ptr->left, dataItem);
    }
    else
    {
      return findHelper(ptr->right, dataItem);
    }
  }
  return false;
}

////////////////////////////// to be implemented //////////////////////////////
template <typename DataType>
bool BSTClass<DataType>::removeItem( const DataType &dataItem )
{
  return removeHelp(rootNode, dataItem);
}

template <typename DataType>
bool BSTClass<DataType>::removeRoot(BSTNode<DataType>* &ptr)
{
  if(ptr == NULL)
  {
    return false;
  }
  BSTNode<DataType> *removal = ptr;
  if(ptr->right == NULL)
  {
    ptr = ptr->left;
  }
  else if(ptr->left == NULL)
  {
    ptr = ptr->right;
  }
  else
  {
    removal = ptr->left;
    BSTNode<DataType> *parent = ptr;
    while(removal->right !=NULL)
    {
      parent = removal;
      removal = removal->right;
    }
    ptr->dataItem = removal->dataItem;
    if(parent == ptr)
    {
      ptr->left = removal->left;
    }
    else
    {
      parent->right = removal->right;
    }
  }
  delete removal;
  return true;
}

template <typename DataType>
bool BSTClass<DataType>::removeHelp( BSTNode<DataType>* &ptr, const DataType &outVal)
{
  if(ptr == NULL || outVal.compareTo(ptr->dataItem) == 0)
  {
    return removeRoot(ptr);
  }
  else if(outVal.compareTo(ptr->dataItem) < 0)
  {
    return removeHelp(ptr->left, outVal);
  }
  else
  {
    return removeHelp(ptr->right, outVal);
  }
}

///////////////////////////////////////////////////////////////////////////////
template<typename DataType>
bool BSTClass<DataType>::isEmpty
       ( 
        // no parameters
       ) const
   {
    return ( rootNode == NULL );
   }

template<typename DataType>
void BSTClass<DataType>::preOrderTraversal
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

template<typename DataType>
void BSTClass<DataType>::inOrderTraversal
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

template<typename DataType>
void BSTClass<DataType>::postOrderTraversal
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

template<typename DataType>
int BSTClass<DataType>::getHeight
       (
        // no parameters
       ) const
   {
    return getHeightHelper( rootNode );
   }

////////////////////////////// to be implemented //////////////////////////////
template<typename DataType>
int BSTClass<DataType>::getWidthAtRow( int row ) const
{
  return widthHelp(rootNode, row);
}

template <typename DataType>
int BSTClass<DataType>::widthHelp(BSTNode<DataType> *ptr, int row) const
{
  if(ptr == NULL || row < 0)
  {
    return 0;
  }
  if(row == 0)
  {
    return 1;
  }
  else if(row >= 1)
  {
    return widthHelp(ptr->left, row-1) + widthHelp(ptr->right, row-1);
  }
  //return 0;
}

////////////////////////////// to be implemented //////////////////////////////
template<typename DataType>
void BSTClass<DataType>::getMaxWidth(int &maxWidth, int &maxWidthRow) const
{
  maxWidthHelp(rootNode, maxWidth, maxWidthRow);
}

template <typename DataType>
void BSTClass<DataType>::maxWidthHelp(BSTNode<DataType> *ptr, int &maxWidth, int &maxWidthRow) const
{
  maxWidth = 0;
  maxWidthRow = 0;
  int width;
  int height = getHeightHelper(ptr);
  for(int i = 1; i <= height; i++)
  {
    width = widthHelp(ptr, i);
    if(width > maxWidth)
    {
      maxWidth = width;
      maxWidthRow = i;
    }
  }
}

////////////////////////////// to be implemented //////////////////////////////
template<typename DataType>
void BSTClass<DataType>::getMinWidth
      (
        int &minWidth,        // out: min width found
        int &minWidthRow      // out: row at which min width found
       ) const
   {
    minWidthHelp(rootNode, minWidth, minWidthRow);
   }

template <typename DataType>
void BSTClass<DataType>::minWidthHelp(BSTNode<DataType> *ptr, int &minWidth, int &minWidthRow) const
{
  minWidth = 10;
  minWidthRow = 0;
  int width;
  int index;
  int height = getHeightHelper(ptr);
  for(int i = 1; i <= height; i++)
  {
    width = widthHelp(ptr, i);
    if(width < minWidth)
    {
      minWidth = width + 1;
    }
  }
}

////////////////////////////// to be implemented //////////////////////////////
template<typename DataType>
int BSTClass<DataType>::getBottomWidth() const
{
  return botWidthHelp(rootNode);
}

template <typename DataType>
int BSTClass<DataType>::botWidthHelp(BSTNode<DataType> *ptr) const
{
  int height = getHeightHelper(ptr);
  int width = widthHelp(ptr, height - 1);
  return width;
}

//////////////////////////////////////////////////////////////////////////////////
template<typename DataType>
bool BSTClass<DataType>::isCompleteTree
       (
        // no parameters
       ) const
   {
    int depth;

    if( rootNode != NULL )
       {
        checkDepth( INITIALIZE, getHeight() - 1 );

        for( depth = 0; depth < getHeight() - 1; depth++ )
           {
            if( getWidthAtRow( depth ) != toPower( 2, depth ) )
               {
                return false;
               }
           }
       }

    isCompleteTreeHelper( rootNode, getHeight() - 1, 0 );

    return checkDepth( GET_RESULT, 0 );
   }

////////////////////////////// to be implemented //////////////////////////////
template<typename DataType>
bool BSTClass<DataType>::isFullTree
       (
        // no parameters
       ) const
   {
    return fullHelp(rootNode);
   }

template <typename DataType>
bool BSTClass<DataType>::fullHelp(BSTNode<DataType> *ptr) const
{
  if(ptr == NULL)
  {
    return true;
  }
  if(ptr->left == NULL && ptr->right == NULL)
  {
    return true;
  }
  if((ptr->left) && (ptr->right))
  {
    return(fullHelp(ptr->left) && fullHelp(ptr->right));
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////
template<typename DataType>
void BSTClass<DataType>::showStructure
       ( 
        // no parameters
       ) const
   {
    int height = getHeight();

    showStructureHelper( rootNode, height, 0 );

    cout << endl;
   }

template<typename DataType>
void BSTClass<DataType>::showStructureHelper
       ( 
        BSTNode<DataType> *workingPtr,
        int fullHeight,
        int presentHeight
       ) const
   {
    char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
    int acctNum;

    if( workingPtr != NULL )
       {
        showStructureHelper( workingPtr->left, fullHeight, presentHeight + 1 );

        cout << endl;
        showTabs( fullHeight - presentHeight );

        workingPtr->dataItem.getAccount( acctName, acctNum, acctType );

        cout << acctName << endl;

        showStructureHelper( workingPtr->right, fullHeight, presentHeight + 1 );
       }
   }

template<typename DataType>
int BSTClass<DataType>::getHeightHelper
       (
        BSTNode<DataType> *workingPtr
       ) const
   {
    int sizeLeft, sizeRight;

    if( workingPtr != NULL )
       {
        sizeLeft = getHeightHelper( workingPtr->left ) + 1;
        sizeRight = getHeightHelper( workingPtr->right ) + 1;

        if( sizeLeft > sizeRight )
           {
            return sizeLeft;
           }

        return sizeRight;
       }

    return 0;
   }

template<typename DataType>
void BSTClass<DataType>::copyTreeHelper
       ( 
        BSTNode<DataType> *&workingPtr,      // local working pointer
        const BSTNode<DataType> *sourcePtr  // incoming source pointer
       )
   {
    if( sourcePtr != NULL )
       {
        workingPtr = new BSTNode<DataType>( sourcePtr->dataItem, NULL, NULL );
        copyTreeHelper( workingPtr->left, sourcePtr->left );
        copyTreeHelper( workingPtr->right, sourcePtr->right );
       }
   }

template <typename DataType>
void BSTClass<DataType>::clearTreeHelper
       ( 
        BSTNode<DataType> *workingPtr 
       )
   {
    if ( workingPtr != NULL )
       {
        clearTreeHelper( workingPtr->left );
        clearTreeHelper( workingPtr->right );
        delete workingPtr;
       }
   }

template <typename DataType>
void BSTClass<DataType>::insertHelper
       ( 
        BSTNode<DataType> *&workingPtr,
        const DataType &newData
       )
   {
    if ( workingPtr == NULL )
       {
        workingPtr = new BSTNode<DataType>( newData, NULL, NULL );
       }

    else if ( newData.compareTo( workingPtr->dataItem ) < 0 )
       {
        insertHelper( workingPtr->left, newData );
       }

    else if ( newData.compareTo( workingPtr->dataItem ) > 0 )
       {
        insertHelper( workingPtr->right, newData);
       }

    else
       {
        workingPtr->dataItem = newData;
       }
   }

template<typename DataType>
void BSTClass<DataType>::isCompleteTreeHelper
       ( 
        BSTNode<DataType> *workingPtr,  // in: pointer to tree node
        int testDepth,                  // in: depth to test for
        int currentDepth                // in: current depth
       ) const
   {
    if( workingPtr != NULL )
       {
        isCompleteTreeHelper( workingPtr->left, testDepth, currentDepth + 1 );
        isCompleteTreeHelper( workingPtr->right, testDepth, currentDepth + 1 );
       }

    else
       {
        checkDepth( AT_BOTTOM, currentDepth - 1 );
       }
   }

template<typename DataType>
void BSTClass<DataType>::preOrderTraversalHelper
       ( 
        BSTNode<DataType> *workingPtr 
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

template<typename DataType>
void BSTClass<DataType>::inOrderTraversalHelper
       ( 
        BSTNode<DataType> *workingPtr 
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

template<typename DataType>
void BSTClass<DataType>::postOrderTraversalHelper
       ( 
        BSTNode<DataType> *workingPtr 
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

template<typename DataType>
void BSTClass<DataType>::showTabs 
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

template<typename DataType>
bool BSTClass<DataType>::checkDepth
       ( 
        int cmdCode,       // in: informs system where to set
        int depth          // in: present depth information
       ) const
   {
    static int depthHolder = 0;
    static int counter = 0;
    static bool fullState = false;
    static bool leftState = false;
    static bool rightState = false;

    switch( cmdCode )
       {
        case INITIALIZE:
           depthHolder = depth;
           break;

        case AT_BOTTOM:
           if( counter == 1 && depth == depthHolder )
              {
               leftState = true;
               fullState = true;
              }

           else if( leftState && !rightState )
              {
               if( depth == depthHolder - 1 )
                  {
                   rightState = true;

                   depthHolder = depth;
                  }
              }

           else if( leftState && rightState && fullState )
              {
               if( depth != depthHolder )
                  {
                   fullState = false;
                  }
              } 
           break;
       }

    counter++;

    return fullState;
   }

template<typename DataType>
int BSTClass<DataType>::toPower
       ( 
        int base,    // in: base
        int exponent // in: times to multiply base by itself
       ) const
   {
    int index, result = 1;
   
    for( index = 0; index < exponent; index++ )
       {
        result *= base;
       }

    return result;
   }

#endif	// define BST_CLASS_CPP


