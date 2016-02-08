// Program Information ////////////////////////////////////////////////////////
/**
 * @file VertexType.cpp
 *
 * @brief Implementation file for VertexType class
 * 
 * @details Implements member actions of the VertexType class
 *
 * @author Michael Leverington
 *
 * @version 1.00 (30 October 2015)
 *
 * @Note Requires VertexType.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef VERTEXTYPE_CPP
#define VERTEXTYPE_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "VertexType.h"

/**
 * @brief Default constructor
 *
 * @details Constructs empty VertexType
 *          
 * @param None
 *
 * @note None
 */
VertexType::VertexType
       ( 
        // no parameters
       )
     : vertexLetter( DUMMY_VERTEX ), usedState( false )
   {
    // assignment in initializers
   }

/**
 * @brief Initialization constructor
 *
 * @details Constructs VertexType with data
 *          
 * @param in: the vertex letter
 * @param in: The weight of the path to the vertex
 *
 * @note None
 */
VertexType::VertexType
       ( 
        char letter,   // in: vertex letter
        bool used     // in: the weight of the path to the vertex
       )
     : vertexLetter( letter ), 
       usedState( false )
   {
    // assignment in initializers
   }

/**
 * @brief Assignment operator
 *
 * @details Assigns VertexType
 *          
 * @param in: right-hand assigned
 *
 * @note None
 */
const VertexType &VertexType::operator = 
       ( 
        const VertexType &rhVertexType  // in: incoming right-hand value
       )
   {
    vertexLetter = rhVertexType.vertexLetter;
    usedState = rhVertexType.usedState;

    return *this;
   }

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef VERTEXTYPE_CPP



