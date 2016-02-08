// Program Information ////////////////////////////////////////////////////////
/*
     File Name:    ListNode.h

     Description:  Header file for list node class (struct)
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

#ifndef STRUCT_LISTNODE_H
#define STRUCT_LISTNODE_H

// Header files ///////////////////////////////////////////////////////////////

   // none

// Class implementations  /////////////////////////////////////////////////////

using namespace std;

struct ListNode
   {
 	 ListNode( int nodeData, ListNode* nextPtr);

	 int dataItem;

	 ListNode* next;
   };

// Terminating precompiler directives  ////////////////////////////////////////

#endif  // STRUCT_LISTNODE_H

