// Program Information ////////////////////////////////////////////////////////
/**
 * @file PA01.cpp
 *
 * @brief Driver program to exercise the SimpleVector class
 * 
 * @details Allows for testing all SimpleVector methods 
 *          in an interactive operation
 *
 * @version 1.00 (30 August 2015)
 *
 * @Note Requires SimpleVector.h, SimpleVector.cpp
 */

// Precompiler directives /////////////////////////////////////////////////////

   // none

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "SimpleVector.cpp"

using namespace std;

// Global constant definitioans  //////////////////////////////////////////////

const int SMALL_STR_LEN = 25;

enum CONTROL_CODES { AAI_CODE, ATB_CODE, CNC_CODE, DCS_CODE, ETP_CODE, 
                       GAI_CODE, GBX_CODE, HLP_CODE, NOP_CODE, IBC_CODE, 
                         INS_CODE, RTC_CODE, RTS_CODE, SBX_CODE };

const bool VERBOSE = false;

const char ENDLINE_CHAR = '\n';

const int TEST_VECTOR_B_CAPACITY = 12;
const int TEST_VECTOR_D_CAPACITY = 15;

// Free function prototypes  //////////////////////////////////////////////////

void ShowMenu();
void GetCommandInput( char inputString[] );
void GetDataInput( const char inputString[], int &dataIndex, char &dataValue );
CONTROL_CODES ProcessInput( const char inStr[] );
void showData( char idLetter, const SimpleVector<char> dispVector );

// Main function implementation  //////////////////////////////////////////////

int  main()
   {
    SimpleVector<char> testVectorA;
    SimpleVector<char> testVectorB( TEST_VECTOR_B_CAPACITY );
    SimpleVector<char> testVectorC( testVectorB );
    SimpleVector<char> testVectorD( TEST_VECTOR_D_CAPACITY, 'O' );
    //cout << "error" << endl;
    int indexOrControl;          // List index or control
    char dataItem;               // data value
    int value = 0, dummy = 0;    // dummy used to fool compiler (no warnings allowed)
    bool dataChanged;
    char commandString[ SMALL_STR_LEN ];
    CONTROL_CODES command;

    ShowMenu();

    do
       {
        dataChanged = false;

        cout << endl << "Command: ";                  // Read command
        
        GetCommandInput( commandString );

        GetDataInput( commandString, indexOrControl, dataItem );

        command = ProcessInput( commandString );

        if( !VERBOSE )
           {
            cout << commandString << ", index-control: " 
                 <<  indexOrControl << ", data item: " 
                 << dataItem << endl;
           }

        switch ( command )
           {
            case AAI_CODE:  // assign at index

               testVectorA[ indexOrControl ] = dataItem;

               dataChanged = true;

               if( VERBOSE )
                  {
                   cout << "  Value " << dataItem 
                        << " has been assigned to the array at index "
                        << indexOrControl << endl;
                  }
               break;

            case ATB_CODE:  // assign to vector b

               testVectorB = testVectorA;

               dataChanged = true;

               if( VERBOSE )
                  {
                   cout << "  Test list \'A\' has been assigned to test list \'B\'." 
                        << endl;
                  }
               break;

            case CNC_CODE:  // construct c test list

               // tempTestList constructed in code block to control scope
                  { 
                   SimpleVector<char> tempVector( testVectorA );

                   testVectorC = tempVector;
                  }

               dataChanged = true;

               if( VERBOSE )
                  {
                   cout << "  Test list \'C\' has been constructed with test list \'A\'." 
                        << endl;
                  }
               break;

            case DCS_CODE:  // decrement size operation

               testVectorA.decrementSize();

               if( VERBOSE )
                  {
                   cout << "  The size of Vector A has been decreased by one "
                            << "and now has a size of " << testVectorA.getSize()
                            << '.' << endl;
                  }
               break;

            case GAI_CODE:  // get value at index

               dataItem = testVectorA[ indexOrControl ];

               if( VERBOSE )
                  {
                    cout << "  Value: " << dataItem
                         << " found at index " << indexOrControl << '.' << endl;
                  }
               break;

            case HLP_CODE:  // Help
               ShowMenu();
               break;

            case GBX_CODE:  // grow by operation

               testVectorA.grow( indexOrControl );

               if( VERBOSE )
                  {
                   cout << "  Vector A has been increased by " << indexOrControl
                            << " and now has a capacity of " << testVectorA.getCapacity()
                            << '.' << endl;
                  }
               break;

            case INS_CODE:  // increment size operation

               testVectorA.incrementSize();

               if( VERBOSE )
                  {
                   cout << "  The size of Vector A has been increased by one "
                            << "and now has a size of " << testVectorA.getSize()
                            << '.' << endl;
                  }
               break;

            case RTC_CODE:  // return the capacity

               value = testVectorA.getCapacity();

               if( VERBOSE )
                  {
                   cout << "  The capacity of Vector A is " 
                        << value << endl;
                  }
               break;

            case RTS_CODE:  // return the size

               value = testVectorA.getSize();

               if( VERBOSE )
                  {
                   cout << "  The size of Vector A is " 
                        << value << endl;
                  }
               break;

            case SBX_CODE:  // shrink by operation

               testVectorA.shrink( indexOrControl );

               dataChanged = true;

               if( VERBOSE )
                  {
                   cout << "  Vector A has been decreased by " << indexOrControl
                            << " and now has a capacity of " << testVectorA.getCapacity()
                            << '.' << endl;
                  }
               break;

            case ETP_CODE:  // clear the list

               if( VERBOSE )
                  {
                   cout << "  End Program Requested" << endl;
                  }

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
            showData( 'A', testVectorA );
            showData( 'B', testVectorB );
            showData( 'C', testVectorC );
            showData( 'D', testVectorD );
           }
       }
    while ( command != ETP_CODE );

    dummy += value; // to eliminate compiler warning

    return 0;
   }

// Free function implementation  //////////////////////////////////////////////

/**
 * @brief ShowMenu: Displays choice of commands for exercising linked list
 *
 * @details Command letters displayed are unique combinations of three letters;
 *          each letter combination is described
 *
 * @param in: None
 *
 * @note None
 */
void ShowMenu()
   {
    cout << endl << "Commands:" << endl << endl;
    cout << "  hlp      : Show this list of commands" << endl << endl;

    cout << "  atb      : Assign to \'B\' test list" << endl;
    cout << "  cnc      : Construct \'C\' test list with test list \'A\'" << endl;

    cout << "  aai x y  : Assign the value x at index y" << endl;
    cout << "  gai x    : Get the value at index x" << endl << endl;

    cout << "  ins      : Increment the array size" << endl;
    cout << "  dcs      : Decrement the array size" << endl << endl;

    cout << "  gbx x    : Grow the array by x" << endl;
    cout << "  sbx x    : Shrink the array by y" << endl << endl;

    cout << "  rtc      : Return the array capacity" << endl;
    cout << "  rts      : Return the array size" << endl << endl;

    cout << "  etp      : End the test program" << endl;
    cout << endl;
   }

/**
 * @brief GetCommandInput: Acquires command input from user
 *
 * @details Command letters are unique combinations of three letters
 *
 * @param in: None
 *
 * @note Clears input string, loads command letters individually
 *       using extraction operation
 */
void GetCommandInput
  ( 
   char inputString[] // output: string to be returned
  )
   {
    strcpy( inputString, "   " );

    cin >> inputString[ 0 ] >> inputString[ 1 ] >> inputString[ 2 ];
   }

/**
 * @brief GetDataInput: Acquires data input value(s) if a specific command
 *        was input
 *
 * @details Accepts input for all operations starting with "A/a"
 *          for inputting two inputs, and "G/g" or "S/s"
 *          for inputting one input;
 *          does not input anything otherwise
 *
 * @param out: c-string input from user
 *
 * @note Tests for first character, accepts input if appropriate,
 *       returns data value or zero if no input accepted
 */
void GetDataInput
  ( 
   const char inputString[], // input: string used to decide to input
   int &dataIndex,           // output: index from input
   char &dataValue           // output: data value from input
  )
   {
    char inChar = inputString[ 0 ];
    char secondChar = inputString[ 1 ];

    dataValue = '0'; dataIndex = 0;

    if( ( inChar == 'a' || inChar == 'A' ) && ( secondChar == 'a' || secondChar == 'A' ) )
       {
        cin >> dataValue >> dataIndex;
       }

    else if( inChar == 'G' || inChar == 'g' || inChar == 'S' || inChar == 's' )
       {
        cin >> dataIndex;
       }
   }

/**
 * @brief ProcessInput: Translates three-character string input
 *        constant value for use in main function control
 *
 * @details Only correct three-character combinations are accepted;
 *          otherwise "no operation" value is returned;
 *
 * @param in: input string from user
 *
 * @note Individually tests for letter combinations,
 *       allows upper or lower case for any one or more
 *       letters in combination
 */
CONTROL_CODES ProcessInput
  ( 
   const char inStr[] // input: string used to translate commands
  )
   {
    char ltr1 = inStr[ 0 ], ltr2 = inStr[ 1 ], ltr3 = inStr[ 2 ];

    switch( ltr1 )
       {
        case 'a': case 'A':

           if( ltr2 == 't' || ltr2 == 'T' )
              {
               if( ltr3 == 'b' || ltr3 == 'B' )
                  {
                   return ATB_CODE;
                  }
              }

           else if( ltr2 == 'a' || ltr2 == 'A' )
              {
               if( ltr3 == 'i' || ltr3 == 'I' )
                  {
                   return AAI_CODE;
                  }
              }

           break;

        case 'c': case 'C':

           if( ltr2 == 'n' || ltr2 == 'N' )
              {
               if( ltr3 == 'c' || ltr3 == 'C' )
                  {
                   return CNC_CODE;
                  }
              }

           break;

        case 'd': case 'D':

           if( ltr2 == 'c' || ltr2 == 'C' )
              {
               if( ltr3 == 's' || ltr3 == 'S' )
                  {
                   return DCS_CODE;
                  }
              }

           break;

        case 'e': case 'E':

           if( ltr2 == 't' || ltr2 == 'T' )
              {
               if( ltr3 == 'p' || ltr3 == 'P' )
                  {
                   return ETP_CODE;
                  }
              }

           break;

        case 'g': case 'G':

           if( ltr2 == 'a' || ltr2 == 'A' )
              {
               if( ltr3 == 'i' || ltr3 == 'I' )
                  {
                   return GAI_CODE;
                  }
              }

           else if( ltr2 == 'b' || ltr2 == 'B' )
              {
               if( ltr3 == 'x' || ltr3 == 'X' )
                  {
                   return GBX_CODE;
                  }
              }

           break;

        case 'h': case 'H':

           if( ltr2 == 'l' || ltr2 == 'L' )
              {
               if( ltr3 == 'p' || ltr3 == 'P' )
                  {
                   return HLP_CODE;
                  }
              }
           break;

        case 'i': case 'I':

           if( ltr2 == 'n' || ltr2 == 'N' )
              {
               if( ltr3 == 's' || ltr3 == 'S' )
                  {
                   return INS_CODE;
                  }
              }
           break;

        case 's': case 'S':

           if( ltr2 == 'b' || ltr2 == 'B' )
              {
               if( ltr3 == 'x' || ltr3 == 'X' )
                  {
                   return SBX_CODE;
                  }
              }
           break;

        case 'r': case 'R':

           if( ltr2 == 't' || ltr2 == 'T' )
              {
               if( ltr3 == 'c' || ltr3 == 'C' )
                  {
                   return RTC_CODE;
                  }

               else if( ltr3 == 's' || ltr3 == 'S' )
                  {
                   return RTS_CODE;
                  }
              }
           break;
       }

    return NOP_CODE;
   }

void showData( char idLetter, const SimpleVector<char> dispVector )
   {
    int index = 0;

    cout << "Vector " << idLetter << ": ";

    if( dispVector.getSize() > 0 )
       {
        cout << dispVector[ index ];
       }

    for( index = 1; index < dispVector.getSize(); index++ )
       {
        cout << ", " << dispVector[ index ];
       }

    cout << endl;
   }













