// Program Information ////////////////////////////////////////////////////////
/**
 * @file HeapClass.h
 *
 * @brief Definition file for Heap class
 * 
 * @details Specifies all members of the Heap class
 *
 * @author Mitchell Reyes
 *
 * @version 1.00 (12 November 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef HEAP_CLASS_H
#define HEAP_CLASS_H

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

// Class constants ////////////////////////////////////////////////////////////

   // None

// Class definition ///////////////////////////////////////////////////////////

template <typename KeyType, typename DataType>
class HeapNode {
  public:
    HeapNode( const KeyType &nodeKey, const DataType &nodeData, 
       HeapNode *parentPtr, HeapNode *leftPtr, HeapNode *rightPtr );

    KeyType keyItem;
    DataType dataItem;

    HeapNode<KeyType, DataType> *parent;
    HeapNode<KeyType, DataType> *left;
    HeapNode<KeyType, DataType> *right;
};

template <typename KeyType, typename DataType>
class HeapClass {
  public:
    // constants
    static const char TAB = '\t';
    static const int MAX_STR_LEN = 80;
    
    // constructor
    HeapClass();
    HeapClass( const HeapClass<KeyType, DataType> &copied );

    // destructor
    ~HeapClass();

    // assignment operator
    const HeapClass &operator = ( const HeapClass<KeyType, DataType> &rhData );

    // modifiers
    void copyTree( const HeapClass<KeyType, DataType> &copied );
    void clearTree();
    // assigned method - addItem
    void addItem( const KeyType &newKey, const DataType &newData );
    // assigned method - removeItem
    bool removeItem( DataType &returnedDataItem, KeyType &returnedKeyItem );

    // accessors
    bool isEmpty() const;
    void preOrderTraversal() const; 
    void inOrderTraversal() const;  
    void postOrderTraversal() const;
    int getLeftHeight() const;
    int getRightHeight() const;
    void showStructure() const;

  private:

    void showStructureHelper( HeapNode<KeyType, DataType> *workingPtr, int fullHeight, int presentHeight ) const;

    int getHeightHelper( HeapNode<KeyType, DataType> *workingPtr, char leftRightIndicator ) const;

    void copyTreeHelper( HeapNode<KeyType, DataType> *&workingPtr, HeapNode<KeyType, DataType> *parentPtr, const HeapNode<KeyType, DataType> *sourcePtr );

    void clearTreeHelper( HeapNode<KeyType, DataType> *workingPtr );

    void preOrderTraversalHelper( HeapNode<KeyType, DataType> *workingPtr) const;
    void inOrderTraversalHelper( HeapNode<KeyType, DataType> *workingPtr) const;
    void postOrderTraversalHelper( HeapNode<KeyType, DataType> *workingPtr) const;
    void showTabs( int numTabs ) const;

    void adder(HeapNode<KeyType, DataType> *node, const KeyType &newKey,const DataType &newData);
    void sortDown(HeapNode<KeyType, DataType>* node);
    void sortUp(HeapNode<KeyType, DataType>* root);
    bool removeHelp(HeapNode<KeyType, DataType>* &node);
    void swap(HeapNode<KeyType, DataType>* childNode, HeapNode<KeyType, DataType>* parentNode);
    

    HeapNode<KeyType, DataType> *rootNode;
    int size;
};

#endif  // define HEAP_CLASS_H