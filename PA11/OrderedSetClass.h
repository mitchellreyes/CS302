// Program Information ////////////////////////////////////////////////////////
/**
 * @file OrderedSetClass.h
 *
 * @brief Definition file for OrderedSetClass class
 * 
 * @author Michael Leverington
 * 
 * @details Specifies all member methods of the OrderedSetClass class
 *
 * @version 1.10 (15 November 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef ORDEREDSET_CLASS_H
#define ORDEREDSET_CLASS_H

// Header files ///////////////////////////////////////////////////////////////

#include "SimpleVector.h"
#include <iostream>

using namespace std;

// Class definition  //////////////////////////////////////////////////////////

class OrderedSetClass
   {
    public:

    // constants
    static const int DEFAULT_GROW_QUANTITY = 10;

    // constructors
    OrderedSetClass();
    OrderedSetClass( int newCapacity );
    OrderedSetClass( const OrderedSetClass &copiedOSC ); 

    // destructor
    ~OrderedSetClass( );

    // assignment
    const OrderedSetClass &operator = ( const OrderedSetClass &rhOSC );

    // append set
    const OrderedSetClass &operator += ( const OrderedSetClass &rhOSC );
    const OrderedSetClass &operator += ( char letter );

    // accessors
    int getCapacity() const;
    int getSize() const;
    bool peekAtEndItem( char &vertex ) const;
    void dumpSet() const;

    // modifiers

       // remove item at end of set
       bool removeEndItem( char &vertex );

       // clear set
       void clearOrderedSet();

    private:

       SimpleVector<char> OS_Data;
     
   };

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef ORDEREDSET_CLASS_H

