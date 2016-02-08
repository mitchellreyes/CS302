// Program Information ////////////////////////////////////////////////////////
/**
 * @file BSTClass.h
 *
 * @brief Definition file for Binary Search Tree class
 * 
 * @details Specifies all data of the BST class
 *
 * @author Michael Leverington
 *
 * @version 1.00 (03 October 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef BST_CLASS_H
#define BST_CLASS_H

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

// Class constants ////////////////////////////////////////////////////////////

   // None

// Class definition ///////////////////////////////////////////////////////////

template <typename DataType>
class BSTNode
   {
    public:

       BSTNode( const DataType &nodeData, BSTNode *leftPtr, BSTNode *rightPtr );

       DataType dataItem;

       BSTNode<DataType> *left;
       BSTNode<DataType> *right;
   };

template <typename DataType>
class BSTClass
   {
    public:

       // constants
       static const char TAB = '\t';
       static const int MAX_STR_LEN = 80;
       static const int INITIALIZE = 101;
       static const int AT_BOTTOM = 102;
       static const int GET_RESULT = 103;

       // constructor
       BSTClass();
       BSTClass( const BSTClass<DataType> &copied );

       // destructor
       ~BSTClass();

       // assignment operator
       const BSTClass &operator = (const BSTClass<DataType> &rhData );

       // modifiers
       void copyTree( const BSTClass<DataType> &copied );
       void clearTree();
       void insert( const DataType &newData );
       bool findItem( DataType &searchDataItem ) const;          // assigned
       bool removeItem( const DataType &dataItem );              // assigned

       // accessors
       bool isEmpty() const;
       void preOrderTraversal() const; 
       void inOrderTraversal() const;  
       void postOrderTraversal() const;
       int getHeight() const;
       int getWidthAtRow( int row ) const;                       // assigned
       void getMaxWidth( int &maxWidth, int &maxWidthRow ) const;  // assigned
       void getMinWidth( int &minWidth, int &minWidthRow ) const;  // assigned
       int getBottomWidth() const;                               // assigned
       bool isCompleteTree() const;                              
       bool isFullTree() const;                                  // assigned
       void showStructure() const;
 
    private:

       void showStructureHelper( BSTNode<DataType> *workingPtr, int fullHeight, int presentHeight ) const;
       int getHeightHelper( BSTNode<DataType> *workingPtr ) const;
       void copyTreeHelper( BSTNode<DataType> *&workingPtr, const BSTNode<DataType> *sourcePtr );
       void clearTreeHelper( BSTNode<DataType> *workingPtr );
       void insertHelper( BSTNode<DataType> *&workingPtr, const DataType &newData );
       void isCompleteTreeHelper( BSTNode<DataType> *workingPtr, int testDepth, int currentDepth ) const;
       void preOrderTraversalHelper( BSTNode<DataType> *workingPtr) const;
       void inOrderTraversalHelper( BSTNode<DataType> *workingPtr) const;
       void postOrderTraversalHelper( BSTNode<DataType> *workingPtr) const;
       void showTabs( int numTabs ) const;
       bool checkDepth( int cmdCode, int depth ) const;
       int toPower( int base, int exponent ) const;
       //////////////////////////////////////created/////////////////////////////////////////////////////////
       bool findHelper(BSTNode<DataType> *ptr, DataType &dataItem) const;
       bool removeHelp( BSTNode<DataType>* &ptr, const DataType &outVal);
       bool removeRoot(BSTNode<DataType>* &ptr);
       int widthHelp(BSTNode<DataType> *ptr, int row) const;
       void maxWidthHelp(BSTNode<DataType> *ptr, int &maxWidth, int &maxWidthRow) const;
       void minWidthHelp(BSTNode<DataType> *ptr, int &minWidth, int &minWidthRow) const;
       int botWidthHelp(BSTNode<DataType> *ptr) const;
       bool fullHelp(BSTNode<DataType> *ptr) const;

       ///////////////////////////////////////given data member//////////////////////////////////////////////
       BSTNode<DataType> *rootNode;    
   };

#endif	// define BST_CLASS_H



