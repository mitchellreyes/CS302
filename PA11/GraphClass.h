// Program Information ////////////////////////////////////////////////////////
/**
 * @file GraphClass.h
 *
 * @brief Definition file for GraphClass class
 * 
 * @author Michael Leverington
 * 
 * @details Specifies all member methods of the GraphClass class
 *
 * @version 1.10 (15 November 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef GRAPHCLASS_H
#define GRAPHCLASS_H

// Header files ///////////////////////////////////////////////////////////////

#include "SimpleMatrix.h"
#include "PathType.h"
#include "VertexType.h"
#include <iostream>

using namespace std;

// Class definition  //////////////////////////////////////////////////////////

class GraphClass
   {
    public:

       // constants
       static const int DEFAULT_GROW_QUANTITY = 10;
       static const int INDEX_NOT_FOUND = -1;

       // constructors
       GraphClass();
       GraphClass( int newCapacity );
       GraphClass( const GraphClass &copiedGraph ); 

       // destructor
       ~GraphClass();

       // assignment
       const GraphClass &operator = ( const GraphClass &rhGraph );

       // accessors
       bool getNextVertex( char vertexRowLetter, int &startIndex, PathType &nextVertex );
       void dumpAdjacencyTable();

       // modifiers
       void setGraphSize( int newGraphSize );
       bool addPath( char oneVertex, int weight, char otherVertex );
       void setVertexState( char vertex, bool vertexState );

    private:

       bool getVertexIndex( char vertex, int &foundIndex );

       int graphSize;

       SimpleMatrix<PathType> AdjacencyMatrix;
       SimpleVector<VertexType> Vertices;
   };

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef GRAPHCLASS_H

