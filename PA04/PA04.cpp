// Program Information ////////////////////////////////////////////////////////
/**
 * @file PA04.cpp
 *
 * @brief Driver program to exercise the DateSorter class
 * 
 * @details Allows for testing the DateSorter class,
 *          along with a timer class that will be used for evaluation
 *
 * @version 1.00 (11 September 2015)
 *
 * @Note Requires DateType.h, SimpleVector.cpp, SorterClass.cpp, TestSorter.h
 *                cstring and iostream libraries
 */

// Precompiler directives /////////////////////////////////////////////////////

   // None

// Header files ///////////////////////////////////////////////////////////////

#include "DateType.h"
#include "SimpleVector.cpp"
#include "SorterClass.cpp"
#include "TestSorter.h"
#include "SimpleTimer.h"
#include <cstring>
#include <iostream>

using namespace std;

// Global constant definitioans  //////////////////////////////////////////////

const int SMALL_STR_LEN = 25;
const int DISPLAY_WIDTH_COUNT = 5;
const char BREAK[] = " - ";
const char ENDLINE_CHAR = '\n';
const char NULL_CHAR = '\0';
const char COLON = ':';
const bool SORTED = true;
const bool UNSORTED = false;

// Free function prototypes  //////////////////////////////////////////////////

bool getALine( istream &consoleIn, char *str );
void displayList( const TestSorter &dates, char dispID, bool sorted  );

// Main function implementation  //////////////////////////////////////////////

int  main()
   {
    TestSorter dateObjectA, dateObjectB;
    DateType dateValue;
    SimpleTimer timer;
    char tempString[ SMALL_STR_LEN ];

    cout << endl << "Enter list of dates: " << endl;

    timer.start();

    while( getALine( cin, tempString ) )
       {
        dateObjectA.add( tempString );
       }

    displayList( dateObjectA, 'A', UNSORTED );

    dateObjectB = dateObjectA;

    if( dateObjectA.sort() )
       {
        displayList( dateObjectA, 'A', SORTED );
       }

    else
       {
        cout << "ERROR: Failure of sort due to bad input" 
             << endl << endl;
       }

    // NONSTANDARD: Instantiation of object after beginning of function
    //              For test purposes only
    TestSorter dateObjectC( dateObjectA );

    displayList( dateObjectB, 'B', UNSORTED );

    displayList( dateObjectC, 'C', SORTED );

    timer.stop();

    // timer.getElapsedTime( tempString );

    // cout << "Elapsed Time: " << tempString << " seconds." << endl;

    return 0;
   }

// Free function implementation  //////////////////////////////////////////////

/**
 * @brief Displays dates in order held
 *
 * @details dates are displayed in a formatted way so they do not
 *          take as much vertical space
 *          
 * @param in: TestSorter object
 *
 * @note virtual method uses specific strategy to sort objects
 */
void displayList( const TestSorter &dates, char dispID, bool sorted )
   {
    int index = 0;
    DateType dateValue;

    cout << "List " << dispID;

    if( sorted )
       {
        cout << " (sorted):";
       }

    else
       {
        cout << " (unsorted):";
       }

    for( index = 0; index < dates.getSize(); index++ )
       {
        dates.getValueAt( index, dateValue );

        if( index % DISPLAY_WIDTH_COUNT != 0 )
           {
            cout << BREAK;
           }

        if( index % DISPLAY_WIDTH_COUNT == 0 )
           {
            cout << endl;
           }

        cout << dateValue;
       }

    cout << endl << endl;
   }

/**
 * @brief Gets dates in three parts, combines to one string
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
    char tempStr[ SMALL_STR_LEN ];

    cin >> tempStr;

    if( strcmp( tempStr, "QUIT" ) != 0 )
       {
        strcpy( str, tempStr );
        strcat( str, " " );

        cin >> tempStr;
        strcat( str, tempStr );
        strcat( str, " " );

        cin >> tempStr;
        strcat( str, tempStr );

        return true;
       }

    return false;
   }








