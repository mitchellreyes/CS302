// Program Information ////////////////////////////////////////////////////////
/**
 * @file PA06.cpp
 *
 * @brief Driver program to exercise the BST class
 * 
 * @details Allows for testing the BST class,
 *          along with a timer class that will be used for evaluation
 *
 * @version 1.00 (3 October 2015)
 *
 * @Note Requires iostream, cstring, NameType.h, and BSTClass.h
 */

// Precompiler directives /////////////////////////////////////////////////////

   // None

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "NameType.h"
#include "BSTClass.cpp"

using namespace std;

// Global constant definitioans  //////////////////////////////////////////////

const char ENDLINE_CHAR = '\n';
const char CARRIAGE_RETURN_CHAR = '\r';
const char NULL_CHAR = '\0';
const int MAX_NAME_LEN = 80;

// Free function prototypes  //////////////////////////////////////////////////

bool getALine( istream &consoleIn, char *str );

// Main function implementation  //////////////////////////////////////////////

int  main()
   {
    BSTClass<NameType> BC_1, BC_2;
    char inputStr[ MAX_NAME_LEN ];

    while( getALine( cin, inputStr ) )
       {
        BC_1.insert( NameType( inputStr ) );
       }

    cout << endl << "BC_1 In Order Traversal: " << endl;
    BC_1.inOrderTraversal();

    cout << endl << "BC_1 Tree Structure: " << endl;
    BC_1.showStructure();

    BC_1.removeItem( NameType( "Opperman, Nathaniel" ) );

    BC_2 = BC_1;

    cout << endl << "BC_2 In Order Traversal: " << endl;
    BC_2.inOrderTraversal();

    cout << endl << "BC_2 Pre Order Traversal: " << endl;
    BC_2.preOrderTraversal();

    // Non-standard action: Object instantiated in a location
    //   not at the beginning of the function
    BSTClass<NameType> BC_3( BC_1 );

    cout << endl << "BC_3 In Order Traversal: " << endl;
    BC_3.inOrderTraversal();

    cout << endl << "BC_3 Post Order Traversal: " << endl;
    BC_3.postOrderTraversal();

    cout << endl << "Height of BC_3: " << BC_3.getHeight() << endl;

    BC_3.clearTree();

    cout << endl << "BC_3 Post Order Traversal (empty tree): " << endl;
    BC_3.postOrderTraversal();

    cout << endl << "BC_1 Tree Structure: " << endl;
    BC_1.showStructure();

    return 0;
   }

// Free function implementation  //////////////////////////////////////////////

/**
 * @brief Gets name in the form <Last Name>, <First Name>
 *
 * @details dates are input using cin, and then recombined for string
 *          accommodates testing (Submit) system
 *          
 * @param in: istream object
 * @param out: string with date
 *
 * @note resolution for redirected input, getline did not work
 */
bool getALine( istream &consoleIn, char *str )
   {
    char inChar;
    int index = 0;

    consoleIn.get( inChar );

    while( inChar != ENDLINE_CHAR && index < MAX_NAME_LEN - 1 )
       {
        if( inChar != CARRIAGE_RETURN_CHAR )
           {
            str[ index ] = inChar;

            index++;

            str[ index ] = NULL_CHAR;
           }

        consoleIn.get( inChar );
       }

    if( strcmp( str, "QUIT" ) == 0 )
       {
        return false;
       }

    return true;
   }








