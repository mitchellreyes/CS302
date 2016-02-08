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
void displayList( const SelSorter &dates, char dispID, bool sorted  );

// Main function implementation  //////////////////////////////////////////////

int  main()
   {
    SelSorter dateObjectI1;
    MrgSorter dateObjectM1;
    QkSorter dateObjectQ1;
    DateType dateValue;
    SimpleTimer timer;
    char tempString[ SMALL_STR_LEN ], insTime[ SMALL_STR_LEN ];
    char qkTime[ SMALL_STR_LEN ], mrgTime[ SMALL_STR_LEN ]; 
    bool qSortGood = false, mSortGood = false, iSortGood = false;

    // load dates ////////////////////////////////////////////////////////////
    cout << endl << "Enter list of dates: " << endl;

    while( getALine( cin, tempString ) )
       {
        dateObjectI1.add( tempString );
       }

    // assign dates to other objects /////////////////////////////////////////
    dateObjectM1 = dateObjectI1;

    dateObjectQ1 = dateObjectM1;

    // display lists, unsorted ///////////////////////////////////////////////
    displayList( dateObjectI1, 'S', UNSORTED );

    displayList( dateObjectM1, 'M', UNSORTED );

    displayList( dateObjectQ1, 'Q', UNSORTED );

    // Selection sort operation //////////////////////////////////////////////
    timer.start();

    if( dateObjectI1.sort() )
       {
        timer.stop();
        timer.getElapsedTime( insTime );
        displayList( dateObjectI1, 'I', SORTED );
        iSortGood = true;
       }

    // stop timer in case of failure
    timer.stop();

    // Merge sort operation //////////////////////////////////////////////////
    timer.start();

    if( dateObjectM1.sort() )
       {
        timer.stop();
        timer.getElapsedTime( mrgTime );
        displayList( dateObjectM1, 'M', SORTED );
        mSortGood = true;
       }

    // stop timer in case of failure
    timer.stop();

    // Quick sort operation //////////////////////////////////////////////////
    timer.start();

    if( dateObjectQ1.sort() )
       {
        timer.stop();
        timer.getElapsedTime( qkTime );
        displayList( dateObjectQ1, 'Q', SORTED );
        qSortGood = true;
       }

    // stop timer in case of failure
    timer.stop();

    // Results displayed /////////////////////////////////////////////////////
    if( iSortGood )
       {
        cout << "Elapsed Time for Selection Sort: " 
             << insTime << " seconds." << endl;
       }
    else
       {
        cout << "ERROR: Failure of selection sort due to bad input" 
             << endl << endl;
       }

    if( mSortGood )
       {
        cout << endl << "Elapsed Time for Merge Sort: " 
             << mrgTime << " seconds." << endl;
       }
    else
       {
        cout << "ERROR: Failure of merge sort due to bad input" 
             << endl << endl;
       }


    if( qSortGood )
       {
        cout << endl << "Elapsed Time for Quick Sort: " 
             << qkTime << " seconds." << endl << endl;
       }
    else
       {
        cout << "ERROR: Failure of quick sort due to bad input" 
             << endl << endl;
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
void displayList( const SelSorter &dates, char dispID, bool sorted )
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








