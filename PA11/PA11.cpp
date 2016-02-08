// Program Information ////////////////////////////////////////////////////////
/**
 * @file PA11.cpp
 *
 * @brief Program finds shortest distances in cyclic graph
 * 
 * @details Uses an OrderedSetClass to manage vertices,
 *          uses a SimpleVector to manage paths/weights
 *
 * @version 1.00 (15 November 2015)
 *
 * @Note Requires iostream, cstring, SimpleVector.cpp, and OrderedSetClass.cpp,
 *                PathClass.h
 */

// Precompiler directives /////////////////////////////////////////////////////

   // None

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "PathType.h"
#include "OrderedSetClass.h"
#include "GraphClass.h"
#include "SimpleVector.cpp"

using namespace std;

// Global constant definitioans  //////////////////////////////////////////////

const char NULL_CHAR = '\0';
const char DATA_END_CHAR = '#';
const char COLON = ':';
const int MAX_STR_LEN = 80;
const int VERTICES_NOT_FOUND = -1;
const bool VERTEX_USED = true;
const bool VERTEX_NOT_USED = false;
const bool DISPLAY = true;
const bool NO_DISPLAY = false;

// Free function prototypes  //////////////////////////////////////////////////

bool getALine( istream &consoleIn, char &vert_1, int &wt, char &vert_2 );
bool getLine( istream &consoleIn, char *str, int length, char stopChar );
int findShortestDistanceBFS( GraphClass &graph, OrderedSetClass &path, char startVertex, char searchVertex, bool verbose );

// Main function implementation  //////////////////////////////////////////////

int  main()
{
    OrderedSetClass solutionPath;
    GraphClass workingGraph;
    char dummyStr[ MAX_STR_LEN ];
    int graphSize, weight, distance;
    char vertex_1, vertex_2;
    char startVertex, endVertex;

    getLine( cin, dummyStr, MAX_STR_LEN, COLON );
    cin >> graphSize;

    getLine( cin, dummyStr, MAX_STR_LEN, COLON );
    cin >> startVertex;

    getLine( cin, dummyStr, MAX_STR_LEN, COLON );
    cin >> endVertex;

    workingGraph.setGraphSize( graphSize );

    while( getALine( cin, vertex_1, weight, vertex_2 ) )
    {
        workingGraph.addPath( vertex_1, weight, vertex_2 );
    }

    distance = findShortestDistanceBFS( workingGraph, solutionPath, startVertex, endVertex, NO_DISPLAY );

    workingGraph.dumpAdjacencyTable();

    cout << "Distance: " << distance << endl;

    solutionPath.dumpSet();

    return 0;
}

// Free function implementation  //////////////////////////////////////////////

/**
 * @brief Finds shortest route between given vertices, 
 *        using breadth-first search     
 *
 * @details None
 *          
 * @param in: loaded graph
 * @param out: found solution path
 * @param in: start vertex
 * @param in: search vertex
 * @param in: verbose setting
 *
 * @note Initializes search, then calls and uses a helper function
 */
int findShortestDistanceBFS( GraphClass &graph, OrderedSetClass &path, char startVertex, char searchVertex, bool verbose )
{
    return 0; // temporary stub return
}








/**
 * @brief Gets a line of data from the stream for input to graph problem     
 *
 * @details Returns a vertex, the weight, and the other vertex
 *          
 * @param in/out: istream object
 * @param out: vertex one letter
 * @param out: weight
 * @param out: vertex other letter
 *
 * @note None
 */
bool getALine( istream &consoleIn, char &vert_1, int &wt, char &vert_2 )
   {
    char inChar;

    // get first vertex
    consoleIn >> vert_1;

    if( vert_1 == DATA_END_CHAR )
       {
        return false;
       }
   
    // get divider comma
    consoleIn >> inChar;

    // get path weight
    consoleIn >> wt;

    // get divider comma
    consoleIn >> inChar;

    // get second vertex
    consoleIn >> vert_2;

    return true;
   }

/**
 * @brief Gets a line of text from an input stream     
 *
 * @details Gets a line of text from an input stream
 *        up to a specified character, 
 *        or a specified length (-1 to allow for the null char);
 *        ending character is not placed in the string
 *          
 * @param in: istream object
 * @param in: specified length
 * @param in: specified ending character
 * @param out: string
 *
 * @note resolution for redirected input, getline did not work
 */
bool getLine( istream &consoleIn, char *str, int length, char stopChar )
   {
    const char LOWEST_PRINTABLE_CHAR = 32;  // space
    const char HIGHEST_PRINTABLE_CHAR = 126;  // tilde 
    int index = 0;
    int inVal;
    bool istreamState = consoleIn.good();

    inVal = consoleIn.get();

    while( char( inVal ) != stopChar && index < length - 1  )
       {
        if( inVal >= LOWEST_PRINTABLE_CHAR 
                                    && inVal <= HIGHEST_PRINTABLE_CHAR )
           {
            str[ index ] = char( inVal );

            index++;

            str[ index ] = NULL_CHAR;
           }

        inVal = consoleIn.get();
       }

    return istreamState;
   }





