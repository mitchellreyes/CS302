// Program Information ////////////////////////////////////////////////////////
/**
 * @file PA08.cpp
 *
 * @brief Driver program to place sub-rectangles in a rectangle
 * 
 * @details Uses recursion and backtracking
 *
 * @version 1.00 (17 October 2015)
 *
 * @Note Requires SimpleVector.cpp, SimpleMatrix.cpp, Rectangle.h, SolverClass
 */

// Precompiler directives /////////////////////////////////////////////////////

   // None

// Header files ///////////////////////////////////////////////////////////////

#include "SimpleVector.cpp"
#include "SimpleMatrix.cpp"
#include "SimpleTimer.h"
#include "Rectangle.h"
#include "SolverClass.h"

#include <iostream>

using namespace std;

// Global constant definitioans  //////////////////////////////////////////////

const int LARGE_STR_LEN = 100;
const int STD_STR_LEN = 35;
const char COLON = ':';
const char ENDLINE_CHAR = '\0';
const char NULL_CHAR = '\n';
const char CARRIAGE_RETURN_CHAR = char( 10 );

// Free function prototypes  //////////////////////////////////////////////////

void getLine( istream &consoleIn, char *str, int length, char stopChar );
bool getData( istream &consoleIn, int &firstVal, int &secondVal );

// Main function implementation  //////////////////////////////////////////////

int  main()
   {
    Rectangle RCT;
    SolverClass SC;
    SimpleTimer ST;
    char timerStr[ STD_STR_LEN ];
    int width, height; 

    getData( cin, height, width );

    SC.setContainerRectangle( height, width );

    while( getData( cin, height, width ) )	 
       {
        SC.addInsideRectangle( height, width );
       }

    SC.setDisplayFlag( false );

    ST.start();

    if( SC.findSolution() )
       {
        ST.stop();
        cout << "Solution found!" << endl << endl;
       }

    else
       {
        ST.stop();
        cout << "Solution not found" << endl << endl;
       }

    ST.getElapsedTime( timerStr );

//    cout << "Time Taken: " << timerStr << endl << endl;

    SC.setDisplayFlag( true );

    SC.displayField();

    return 0;
   }

// Free function implementation  //////////////////////////////////////////////


/**
 * @brief Gets two data values needed for operation, returns success
 *
 * @details ignores three text items and comma, gets two values,
 *          if they are not zeros, returns true, otherwise returns false
 *          
 * @param in: istream object
 * @param out: first value
 * @param out: second value
 *
 * @notes still not able to implement a working getline
 */
bool getData( istream &consoleIn, int &firstVal, int &secondVal )
   {
    char tempStr[ LARGE_STR_LEN ];
    char dummyChar;

    cin >> tempStr >> tempStr >> tempStr >> firstVal >> dummyChar >> secondVal;

    if( firstVal != 0 && secondVal != 0 )
       {
        return true;
       }

    return false;
   }







