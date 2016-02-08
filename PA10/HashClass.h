// Program Information ////////////////////////////////////////////////////////
/**
 * @file HashClass.h
 *
 * @brief Definition file for HashClass
 * 
 * @details Specifies all data and other members of the HashClass
 *
 * @author Michael Leverington
 *
 * @version 1.00 (06 November 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef HASH_CLASS_H
#define HASH_CLASS_H

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>
#include "SimpleVector.h"

using namespace std;

// Class constants ////////////////////////////////////////////////////////////

   // None

// Class definition ///////////////////////////////////////////////////////////

template <typename DataType>
class HashNode
   {
    public:

       HashNode( const DataType &newData, HashNode *next );

       DataType data;

       HashNode *nextPtr;
   };

template <typename DataType>
class HashClass
   {
    public:

       // constants
       static const char TAB = '\t';
       static const int DEFAULT_HASH_LETTER_COUNT = 3;
       static const int STD_STR_LEN = 50;

       // constructor
       HashClass();
       HashClass( const HashClass<DataType> &copied );

       // destructor
       ~HashClass();

       // assignment operator
       const HashClass &operator = (const HashClass<DataType> &rhData );

       // modifiers
       void setTableLength( int newTableLength );
       void setHashLetterCount( int newHashLetterCount );


       bool addItem( const DataType &newData );
       bool findItem( const DataType &dataItem );
       bool removeItem( const DataType &dataItem );

       // accessors
       bool isEmpty() const;
       void clearList();
       double getChainLengthMean() const;
       double getChainLengthMedian() const;
       void showStructure() const;

    private:

       int hash( const DataType &dataItem );

       int tableLength;
       int hashLetterCount;

       SimpleVector<HashNode<DataType> *> list;    
   };

#endif	// define HASH_CLASS_H



