// Program Information ////////////////////////////////////////////////////////
/**
 * @file PathType.cpp
 *
 * @brief Implementation file for PathType class
 * 
 * @details Implements member actions of the PathType class
 *
 * @author Michael Leverington
 *
 * @version 1.00 (30 October 2015)
 *
 * @Note Requires PathType.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef PATHTYPE_CPP
#define PATHTYPE_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "PathType.h"

/**
 * @brief Default constructor
 *
 * @details Constructs empty PathType
 *          
 * @param None
 *
 * @note None
 */
PathType::PathType
       ( 
        // no parameters
       )
     : vertexLetter( DUMMY_VERTEX ), pathWeight( 0 )
   {
    // assignment in initializers
   }

/**
 * @brief Initialization constructor
 *
 * @details Constructs PathType with data
 *          
 * @param in: the vertex letter
 * @param in: The weight of the path to the vertex
 *
 * @note None
 */
PathType::PathType
       ( 
        char letter,   // in: vertex letter
        int weight     // in: the weight of the path to the vertex
       )
     : vertexLetter( letter ), 
       pathWeight( weight )
   {
    // assignment in initializers
   }

/**
 * @brief Assignment operator
 *
 * @details Assigns PathType
 *          
 * @param in: right-hand assigned
 *
 * @note None
 */
const PathType &PathType::operator = 
       ( 
        const PathType &rhPathType  // in: incoming right-hand value
       )
   {
    vertexLetter = rhPathType.vertexLetter;
    pathWeight = rhPathType.pathWeight;

    return *this;
   }

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef PATHTYPE_CPP



