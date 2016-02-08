// Program Information ////////////////////////////////////////////////////////
/**
 * @file VertexType.h
 *
 * @brief Definition file for VertexType class
 * 
 * @details Specifies all data of the VertexType class,
 *          along with a default constructor, and public data
 *
 * @author Michael Leverington
 *
 * @version 1.00 (15 November 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef VERTEXTYPE_H
#define VERTEXTYPE_H

// Header files ///////////////////////////////////////////////////////////////

#include <ostream>
#include <stdexcept>

using namespace std;

// Class constants ////////////////////////////////////////////////////////////

   // None

// Class definition ///////////////////////////////////////////////////////////

class VertexType
   {
    public:
       
       static const char DUMMY_VERTEX = '-';

       VertexType();
       VertexType( char letter, bool used );

       const VertexType &operator = ( const VertexType &rhVertexType );

       char vertexLetter;
       bool usedState;
   };

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef VERTEXTYPE_H



