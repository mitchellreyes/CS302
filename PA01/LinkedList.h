// Program Information ////////////////////////////////////////////////////////
/*
     File Name:    LinkedList.h

     Description:  header file for linked list class
*/

// Version/Revision Information ///////////////////////////////////////////////
/*
     1.00 (08/21/2015) - Michael Leverington
          program developed for first programming assignment
          materials loosely based on linked list exercise in Brandle, et. al.
          in C++ Data Structures: A Laboratory Course, (c) 2009
*/

// Program description/support ////////////////////////////////////////////////
/*
     See driver program (PA01) for dependencies
*/

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_LINKEDLIST_H
#define CLASS_LINKEDLIST_H

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>
#include "ListNode.h"

using namespace std;

// Class definitions  /////////////////////////////////////////////////////////

class LinkedList 
   {
    public:
       // constructors
       LinkedList( int maxSize = 10 );
       LinkedList( const LinkedList& other );
       ~LinkedList();

       // modifiers
       bool insertBeforeCursor( int newDataItem );
       bool insertAfterCursor( int newDataItem );
       bool replaceBeforeCursor( int newDataItem );     
       bool replaceAtCursor( int newDataItem );
       bool replaceAfterCursor( int newDataItem );

       bool removeAtCursor( int &dataVal );
       void clear();
       
       LinkedList& isAssigned( const LinkedList& other );
       LinkedList& operator = ( const LinkedList& other );

       // accessors
       bool getDataAtCursor( int &dataVal ) const;
       void showStructure( char listID ) const;

       bool isEmpty() const;
       bool isFull() const;

       bool goToBeginning();
       bool goToEnd();
       bool goToNext();
       bool goToPrior();

    private:

       ListNode* head;
       ListNode* cursor;

       int capacity;
       int size;
   };

// Terminating precompiler directives  ////////////////////////////////////////

#endif // ifndef CLASS_LINKEDLIST

