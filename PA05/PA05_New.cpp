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
 * @Note Requires DateType.h, SimpleVector.cpp, SorterClass.cpp, InsSorter.h
 *                cstring and iostream libraries
 */

// Precompiler directives /////////////////////////////////////////////////////

   // None

// Header files ///////////////////////////////////////////////////////////////

#include "DateType.h"
#include "SimpleVector.cpp"
#include "SorterClass.cpp"
#include "SelSorter.h"
#include "MrgSorter.h"
#include "QkSorter.h"
#include "SimpleTimer.h"
#include <cstring>
#include <iostream>

using namespace std;

// Global constant definitioans  //////////////////////////////////////////////

const int SMALL_STR_LEN = 25;
const int DISPLAY_WIDTH_COUNT = 5;
const int SORTER_ITEMS = 3;
const char BREAK[] = " - ";
const char ENDLINE_CHAR = '\n';
const char NULL_CHAR = '\0';
const char COLON = ':';
const bool SORTED = true;
const bool UNSORTED = false;

// Free function prototypes  //////////////////////////////////////////////////

bool getALine( istream &consoleIn, char *str );
void displayList( const InsSorter &dates, char dispID, bool sorted  );

// Main function implementation  //////////////////////////////////////////////

int  main()
   {
    SorterClass<DateType> *sorterPtrArray[ SORTER_ITEMS ];
    DateType dateValue;
    SimpleTimer timer;
    char sortLtrs[] = { 'S', 'M', 'Q' };
    char sortNames[][ SMALL_STR_LEN ] = { "Selection", "Merge", "Quick" };
    char sortTimes[ SORTER_ITEMS ][ SMALL_STR_LEN ];
    bool sortStates[] = { false, false, false };
    char tempString[ SMALL_STR_LEN ];
    int index;

    // load objects
    sorterPtrArray[ 0 ] = new SelSorter;
    sorterPtrArray[ 1 ] = new MrgSorter;
    sorterPtrArray[ 2 ] = new QkSorter;

    // load dates ////////////////////////////////////////////////////////////
    cout << endl << "Enter list of dates: " << endl;

    while( getALine( cin, tempString ) )
       {
        sorterPtrArray[ 0 ]->add( tempString );
       }

    // assign dates to other objects /////////////////////////////////////////
    for( index = 1; index < SORTER_ITEMS; index++ )
       {
        *sorterPtrArray[ index ] = *sorterPtrArray[ index - 1 ];
       }

    // display lists, unsorted ///////////////////////////////////////////////
    for( index = 0; index < SORTER_ITEMS; index++ )
       {
        displayList( *sorterPtrArray[ index ], sortLtrs[ index ], UNSORTED );
       }

    // all sort operations ///////////////////////////////////////////////////
    for( index = 0; index < SORTER_ITEMS; index++ )
       {
        timer.start();

        if( sorterPtrArray[ index ]->sort() )
           {
            timer.stop();
            timer.getElapsedTime( sortTimes[ index ] );
            displayList( *sorterPtrArray[ index ], sortLtrs[ 0 ], SORTED );
            sortStates[ index ] = true;
           }

        // stop timer in case of failure
        timer.stop();
       }

    // Results displayed /////////////////////////////////////////////////////
    for( index = 0; index < SORTER_ITEMS; index++ )
       {
        if( sortStates[ index ] )
           {
            cout << "Elapsed Time for " << sortNames[ index ] << ": " 
                 << sortTimes[ index ] << " seconds." << endl;
           }
        else
           {
            cout << "ERROR: Failure of " << sortNames[ index ] 
                 << " sort due to bad input." 
                 << endl << endl;
           }
       }

    return 0;
   }

// Free function implementation  //////////////////////////////////////////////

/**
 * @brief Displays dates in order held
 *
 * @details dates are displayed in a formatted way so they do not
 *          take as much vertical space
 *          
 * @param in: InsSorter object
 *
 * @note virtual method uses specific strategy to sort objects
 */
void displayList( const InsSorter &dates, char dispID, bool sorted )
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








