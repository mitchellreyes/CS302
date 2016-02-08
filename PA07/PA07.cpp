// Program Information ////////////////////////////////////////////////////////
/**
 * @file PA07.cpp
 *
 * @brief Driver program to exercise the BST class, with account information
 * 
 * @details Allows for testing the BST class,
 *          along with a timer class that will be used for evaluation
 *
 * @version 1.00 (09 October 2015)
 *
 * @Note Requires iostream, cstring, AcctType.h, and BSTClass.h
 */

// Precompiler directives /////////////////////////////////////////////////////

   // None

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "AcctType.h"
#include "BSTClass.cpp"

using namespace std;

// Global constant definitioans  //////////////////////////////////////////////

const char ENDLINE_CHAR = '\n';
const char CARRIAGE_RETURN_CHAR = '\r';
const char TAB = '\t';
const char NULL_CHAR = '\0';
const char DOUBLE_QUOTES = '\"';
const char COLON = ':';
const int MAX_NAME_LEN = 80;

enum cCodes { DUMMY, BC_1_IOT, BC_1_IOT_W_HT, BC_1_TS, BC_1_RI, BC_1_FI, 
        BC_1_ASSGND, BC_1_INFO, BC_1_PSTOT, BC_1_PREOT, BC_1_CLRD, BC_1_CPYD };

// Free function prototypes  //////////////////////////////////////////////////

int getControlCode( istream &consoleIn );
bool getALine( istream &consoleIn, AcctType &inputData );
void displayCodeChoices();

// Main function implementation  //////////////////////////////////////////////

int  main()
   {
    AcctType AC_1, removeAcct, retrieveAcct;
    AcctType dummyAcct( "DummyName", 0, "DummyType" );
    BSTClass<AcctType> BC_1, BC_2;
    char accountName[ MAX_NAME_LEN ];
    char accountType[ MAX_NAME_LEN ];
    int accountNumber, controlCode, depth, treeHeight;
    int maxTreeWidth, maxTreeWidthRow, minTreeWidth, minTreeWidthRow;

    displayCodeChoices();

    controlCode = getControlCode( cin );

    cout << controlCode << endl << "Data Entry:" << endl;

    while( getALine( cin, AC_1 ) )
       {
        AC_1.getAccount( accountName, accountNumber, accountType );

        BC_1.insert( AC_1 );
       }

    switch( controlCode )
       {
        case BC_1_IOT:
           cout << endl << "BC_1 In Order Traversal: " << endl;
           BC_1.inOrderTraversal();
           break;

        case BC_1_IOT_W_HT:
           cout << endl << "BC_1 In Order Traversal: " << endl;
           BC_1.inOrderTraversal();
           cout << "Height of BC_1: " << BC_1.getHeight() 
                << endl << endl;
           break;

        case BC_1_TS:
           cout << endl << "BC_1 Tree Structure: " << endl;
           BC_1.showStructure();
           break;

        case BC_1_RI:
           cout << endl << "Test of removal operation" << endl;
           cout << endl << "BC_1 Traversal before removal: " << endl;
           BC_1.inOrderTraversal();

           removeAcct.setAccount( "Opperman, Nathaniel", 0, "0" );
           BC_1.removeItem( removeAcct );

           cout << endl 
                << "BC_1 Traversal after removal of Opperman, Nathaniel: " 
                << endl;
           BC_1.inOrderTraversal();
           break;

        case BC_1_FI:
           cout << endl << "Test of find operation" << endl;
           cout << endl << "BC_1 Traversal before search: " << endl;
           BC_1.inOrderTraversal();

           retrieveAcct.setAccount( "Niday, Brian", 0, "0" );

           if( BC_1.findItem( retrieveAcct ) )
              {
               retrieveAcct.getAccount( accountName, 
                                                 accountNumber, accountType );

               cout << endl 
                    << "Retrieve Account Information:" << endl
                    << "Name: " << accountName
                    << ", Account Number: " << accountNumber
                    << ", Account Type: " << accountType 
                    << endl;
              }

           else
              {
               cout << "ERROR: Name not found." << endl;
              }

           break;

        case BC_1_ASSGND:
           cout << endl << "Test of tree assignment operation" << endl;

           cout << endl << "BC_1 In Order Traversal: " << endl;
           BC_1.inOrderTraversal();
 
           BC_2 = BC_1;

           cout << endl << "BC_2 In Order Traversal: " << endl;
           BC_2.inOrderTraversal();
           break;

        case BC_1_PSTOT:
           cout << endl << "BC_1 Post Order Traversal: " << endl;
           BC_1.postOrderTraversal();
           break;

        case BC_1_PREOT:
           cout << endl << "BC_1 Pre Order Traversal: " << endl;
           BC_1.preOrderTraversal();
           break;

        case BC_1_CLRD:
           cout << endl << "Test of tree clearing operation" << endl;

           cout << endl << "BC_1 Traversal before cleared: " << endl;
           BC_1.inOrderTraversal();

           BC_1.clearTree();

           cout << endl << "BC_1 Traversal after removal: " << endl;
           BC_1.inOrderTraversal();
           break;

        case BC_1_INFO:
           cout << endl << "BC_1 Tree Structure: " << endl;

           BC_1.showStructure();

           cout << endl << "Tree Information Presentation" << endl;

           treeHeight = BC_1.getHeight();

           cout << endl << "BC_1 Tree height: " << treeHeight << endl;

           cout << endl << "BC_1 Tree widths:" << endl;

           for( depth = 0; depth < treeHeight; depth++ )
              {           
               cout << TAB << "BC_1 Tree width at row " << depth << ": " 
                                    << BC_1.getWidthAtRow( depth ) << endl;
              }

           BC_1.getMaxWidth( maxTreeWidth, maxTreeWidthRow );

           cout << endl << "BC_1 Maximum Tree Width: " 
                        << maxTreeWidth << " at row: "
                        << maxTreeWidthRow << endl;

           BC_1.getMinWidth( minTreeWidth, minTreeWidthRow );

           cout << endl << "BC_1 Minimum Tree Width: " 
                        << minTreeWidth << " at row: "
                        << minTreeWidthRow << endl;

           cout << endl << "BC_1 Bottom Row Tree Width: " 
                        << BC_1.getBottomWidth() << endl;

           if( BC_1.isCompleteTree() )
              {
               cout << endl << "BC_1 is a complete tree" << endl;
              }
           else
              {
               cout << endl << "BC_1 is not a complete tree" << endl;
              }

           if( BC_1.isFullTree() )
              {
               cout << endl << "BC_1 is a full tree" << endl;
              }
           else
              {
               cout << endl << "BC_1 is not a full tree" << endl;
              }

           cout << endl;

           break;

        case BC_1_CPYD:
           cout << endl << "Test of tree object copy operation" << endl;

           cout << endl << "BC_1 In Order Traversal: " << endl;
           BC_1.inOrderTraversal();

           // Non-standard action: Object instantiated in a location
           //   not at the beginning of the function
           BSTClass<AcctType> BC_3( BC_1 );
      
           cout << endl << "BC_3 In Order Traversal: " << endl;
           BC_3.inOrderTraversal();
           break;
       } 
       
    return 0;
   }

// Free function implementation  //////////////////////////////////////////////

/**
 * @brief Displays test choices
 *
 * @details Various codes implement different tests on tree system
 *          
 * @param in: None
 *
 * @note Codes are all enumerated
 */
void displayCodeChoices()
   {
    cout << "Here is the list of codes for the various tests:" << endl;

    cout << "Show in order traversal                 : " << BC_1_IOT << endl;
    cout << "Show in order traversal with tree height: " 
         << BC_1_IOT_W_HT << endl;
    cout << "Show Tree Structure of input data       : " << BC_1_TS << endl;
    cout << "Show remove item action                 : " << BC_1_RI << endl;
    cout << "Show retrieved data                     : " << BC_1_FI << endl;
    cout << "Show object assignment operation        : " << BC_1_ASSGND << endl;
    cout << "Show Tree Information                   : " << BC_1_INFO << endl;
    cout << "Show post order traversal               : " << BC_1_PSTOT << endl;
    cout << "Show pre order traversal                : " << BC_1_PREOT << endl;
    cout << "Show tree cleared action                : " << BC_1_CLRD << endl;
    cout << "Show tree copied action                 : " << BC_1_CPYD << endl;
    cout << endl << "Enter code number: ";
   }

/**

 * @brief Gets control code for testing
 *
 * @details code is used in program to test individual actions
 *          
 * @param in: istream object
 *
 * @return out: operation code
 *
 * @note gets integer, cleans out end line characters
 */
int getControlCode( istream &consoleIn )
   {
    char inChar;
    int codeNum;

    consoleIn >> codeNum;

    while( inChar != ENDLINE_CHAR )
       {
        consoleIn.get( inChar );
       }

    return codeNum;
   }
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
bool getALine( istream &consoleIn, AcctType &inputData )
   {
    AcctType testData;
    char inChar;
    int index = 0;
    bool openDoubleQuotes = false, closeDoubleQuotes = false;
    char inName[ MAX_NAME_LEN ], inAcctType[ MAX_NAME_LEN ];
    int inAcctNum;

    consoleIn.get( inChar );

    while( index < MAX_NAME_LEN - 1 && !closeDoubleQuotes )
       {
        if( inChar != CARRIAGE_RETURN_CHAR )
           {
            if( inChar == DOUBLE_QUOTES )
               {
                if( !openDoubleQuotes )
                   {
                    openDoubleQuotes = true;
                   }

                else
                   {
                    closeDoubleQuotes = true;
                   }
               }

            else
               {
                inName[ index ] = inChar;

                index++;
 
                inName[ index ] = NULL_CHAR;
               }
           }

        consoleIn.get( inChar );
       }

    if( strcmp( inName, "QUIT" ) == 0 )
       {
        return false;
       }

    consoleIn >> inAcctNum;

    consoleIn.get( inChar ); // next comma

    consoleIn.get( inChar ); // first letter of acct type

    index = 0;
   
    while( index < MAX_NAME_LEN - 1 && inChar != ENDLINE_CHAR )
       {
        if( inChar != CARRIAGE_RETURN_CHAR )
           {
            inAcctType[ index ] = inChar;

            index++;

            inAcctType[ index + 1 ] = NULL_CHAR;
           }

       consoleIn.get( inChar );
      }

    inputData.setAccount( inName, inAcctNum, inAcctType );
            
    return true;
   }








