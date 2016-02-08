// Program Information ////////////////////////////////////////////////////////
/**
 * @file PA03.cpp
 *
 * @brief Driver program to exercise the PriorityQueue class
 * 
 * @details Allows for testing all PriorityQueue methods 
 *          in an interactive environment
 *
 * @version 1.00 (07 September 2015)
 *
 * @Note Requires SimpleVector.cpp, SimpleVector.cpp
 */

// Precompiler directives /////////////////////////////////////////////////////

   // none

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "DataType.h"
#include "SimpleVector.cpp"
#include "PriorityQueue.cpp"

using namespace std;

// Global constant definitioans  //////////////////////////////////////////////

const int SMALL_STR_LEN = 25;

const bool VERBOSE = false;

const char ENDLINE_CHAR = '\n';
const char PERIOD = '.';

const int TEST_PQ_NUM_PRIORITIES = 12;

// Free function prototypes  //////////////////////////////////////////////////

void ShowMenu();
char GetCommandInput( char processString[], int &priority );

// Main function implementation  //////////////////////////////////////////////

int  main()
   {
    PriorityQueue<DataType> testPQA;
    PriorityQueue<DataType> testPQB;
    PriorityQueue<DataType> testPQC;
    char cmdChar;
    DataType dataItem;
    int qPriority;
    char qProcess[ SMALL_STR_LEN ];
    bool dataChanged;

    ShowMenu();

    do
       {
        dataChanged = false;

        cout << endl << "Command: ";                  // Read command
        
        cmdChar = GetCommandInput( qProcess, qPriority );

        switch ( cmdChar )
           {
            case 'c': case 'C':  // clear priority queue

               while( !testPQA.isEmpty() )
                  {
                   testPQA.dequeue( dataItem );
                  }

               if( VERBOSE )
                  {
                   cout << "  Priority Queue has been cleared " << endl;
                  }

               dataChanged = true;

               break;

            case 'd': case 'D':  // dequeue one data item

               testPQA.dequeue( dataItem );

               if( VERBOSE )
                  {
                   cout << "  Process: " << dataItem.process
                        << " has been dequeued with a priority of "
                        << dataItem.priority << PERIOD << endl;
                  }

               dataChanged = true;

               break;

            case 'e': case 'E':  // enqueue

               testPQA.enqueue( qPriority, qProcess );

               if( VERBOSE )
                  {
                   cout << "  Process: " << qProcess
                        << " has been enqueued with a priority of "
                        << qPriority << PERIOD << endl;
                  }

               dataChanged = true;

               break;

            case 'h': case 'H':  // help request

               ShowMenu();

               break;

            case 'p': case 'P':  // peek at next item

               testPQA.peekAtFront( dataItem );

               if( VERBOSE )
                  {
                    cout << "  Process: " << dataItem.process
                         << " with priority: " << dataItem.priority
                         << " found at front of queue." << endl;
                  }
               break;

            case 'q': case 'Q':  // quit the test program

               if( VERBOSE )
                  {
                   cout << "  End Program Requested" << endl;
                  }

               cout << endl;

               break;

            case 'x': case 'X':  // create copy constructor PQ

               // tempPQ constructed in code block to control scope
                  { 
                   PriorityQueue<DataType> tempPQ( testPQA );

                   testPQC = tempPQ;
                  }

               if( VERBOSE )
                  {
                   cout << "  Test PQ \'C\' has been constructed with test PQ \'A\'." 
                        << endl;
                  }

               dataChanged = true;

               break;

            case 'z': case 'Z':  // assign to b PQ

               testPQB = testPQA;

               if( VERBOSE )
                  {
                   cout << "  Test PQ \'A\' has been assigned to test PQ \'B\'." 
                        << endl;
                  }

               dataChanged = true;

               break;

            default :            // Invalid command

               // clear to end of line in case further data input
               cin.ignore( SMALL_STR_LEN, ENDLINE_CHAR );

               if( VERBOSE )
                  {
                   cout << "  Inactive or invalid command" << endl;
                  }
           }

        if( dataChanged )
           {
            testPQA.showStructure( 'A' );
            testPQB.showStructure( 'B' );
            testPQC.showStructure( 'C' );
           }
       }
    while ( cmdChar != 'q' && cmdChar != 'Q' );

    return 0;
   }

// Free function implementation  //////////////////////////////////////////////

/**
 * @brief ShowMenu: Displays choice of commands for exercising priority queue
 *
 * @details Command letters displayed indicate operations to be conducted
 *
 * @param None
 *
 * @note None
 */
void ShowMenu()
   {
    cout << endl << "Priority queue enqueues program process statements";
    cout << endl << "  with a priority of 1 being highest and succeeding";
    cout << endl << "  numbers are lower priority" << endl;
    cout << endl << "Commands:" << endl;
    cout << "  h      : Show this list of commands" << endl;
    cout << "  e x y  : Enqueue process x at priority y" << endl;
    cout << "  d      : Dequeue prioritized process" << endl;
    cout << "  p      : Peek at prioritized process" << endl;
    cout << "  c      : Clear priority queue" << endl;
    cout << "  x      : Tests copy constructor" << endl;
    cout << "  z      : Tests assignment operation" << endl;
    cout << "  q      : Quit the test program" << endl;
    cout << endl;
   }

/**
 * @brief GetCommandInput: Acquires command input from user
 *
 * @details Command letters are unique combinations of three letters
 *
 * @param None
 *
 * @note Clears input string, loads command letters individually
 *       using extraction operation; adds input character for display
 *       and output line for display clearance
 */
char GetCommandInput
       ( 
        char processString[], // out: process string if input
        int &priority          // out : priority value if input
       ) 
   {
    char inputChar;

    strcpy( processString, "-" );
    priority = 0;

    cin >> inputChar;

    if( inputChar == 'e' || inputChar == 'E' )
       {
        cin >> processString;
        cin >> priority;
       }

    cout << inputChar << endl;

    return inputChar;
   }













