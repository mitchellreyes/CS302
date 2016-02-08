// Program Information ////////////////////////////////////////////////////////
/**
 * @file GraphClass.cpp
 * 
 * @author Michael Leverington
 *
 * @brief Implementation file for GraphClass class
 * 
 * @details Implements all member methods of the GraphClass class
 *
 * @Note Requires GraphClass.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef GRAPHCLASS_CPP
#define GRAPHCLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "GraphClass.h"
#include "SimpleMatrix.cpp"

/**
 * @brief Default constructor
 *
 * @details Constructs OSC using SimpleVector as storage engine
 *          
 * @param None
 *
 * @note None
 */
GraphClass::GraphClass
       (
        // data loaded via initializers
       )
    : AdjacencyMatrix(), Vertices()
   {
    graphSize = Vertices.getCapacity();
   }

/**
 * @brief Initialization constructor
 *
 * @details Constructs graph to given capacity
 *          using SimpleMatrix as storage engine
 *          
 * @param in: capacity with which to initialize vector
 *
 * @note None
 */
GraphClass::GraphClass
       ( 
        int newCapacity // in: new matrix (square) capacity
       )
     : graphSize( newCapacity ),
       AdjacencyMatrix( newCapacity, newCapacity ), 
       Vertices( newCapacity )
   {
    int rowIndex, colIndex;
    PathType emptyPT;

    for( rowIndex = 0; rowIndex < newCapacity; rowIndex++ )
       {
        for( colIndex = 0; colIndex < newCapacity; colIndex++ )
           {
            AdjacencyMatrix[ rowIndex ][ colIndex ] = emptyPT;
           }
       }
   }

/**
 * @brief Copy constructor
 *
 * @details Constructs OSC with copied graph
 *          
 * @param in: Other graph with which this graph is constructed
 *
 * @note None
 */
GraphClass::GraphClass
       ( 
        const GraphClass &copiedGraph // in: graph to copy
       )
     : graphSize( copiedGraph.graphSize ),
       AdjacencyMatrix( copiedGraph.AdjacencyMatrix ),
       Vertices( copiedGraph.Vertices )
   {
    // data loaded via initializers
   }

/**
 * @brief object destructor
 *
 * @details If capacity is greater than zero, releases memory to system
 *          
 * @param None
 *
 * @note None
 */
GraphClass::~GraphClass
       (
        // no parameters
       )
   {
    // No action - data is destructed in SimpleVector & SimpleMatrix
   }

/**
 * @brief assignment operation overload
 *
 * @details Assigns data from right-hand OSC to this OSC
 *          
 * @param in: right-hand OSC object
 *
 * @note Uses copyVector to move data into this OSC
 */

const GraphClass &GraphClass::operator = 
       (
        const GraphClass &rhGraph // in: assigned right side
       )
   {
    if( this != &rhGraph )
       {
        AdjacencyMatrix = rhGraph.AdjacencyMatrix;

        Vertices = rhGraph.Vertices;

        graphSize = rhGraph.graphSize;
       }

    return *this; 
   }

/**
 * @brief Sets graph size for specific graph
 *
 * @details Sizes both vertex vector and graph matrix
 *          
 * @param in: new size of graph
 *
 * @note None  
 */
void GraphClass::setGraphSize
       ( 
        int newGraphSize   // in: new graph size
       )
   {
    Vertices.shrink( Vertices.getCapacity() );
    Vertices.grow( newGraphSize );

    AdjacencyMatrix.resize( newGraphSize, newGraphSize );

    graphSize = newGraphSize;
   }

/**
 * @brief Adds a path from a base vertex to another vertex
 *
 * @details If the either vertex is not already in the vector,
 *          it is added as long as there is room
 *          
 * @param in: one of the two vertices
 * @param in: the other of the two vertices
 * @param in: the weight between them
 *
 * @note None  
 */
bool GraphClass::addPath
       (
        char oneVertex,     // in: one of the two vertices
        int weight,         // in: the weight of the path between the vertices
        char otherVertex    // in: the other of the two vertices
       )
   {
    int vertexIndex, oneVertexIndex, otherVertexIndex;
    PathType newPathTypeItem;

    if( getVertexIndex( oneVertex, vertexIndex ) )
       {
        oneVertexIndex = vertexIndex;
       }

    else if( Vertices.getSize() < graphSize )
       {
        oneVertexIndex = Vertices.getSize();

        Vertices[ Vertices.getSize() ].vertexLetter = oneVertex;

        Vertices.incrementSize();
       }

    else
       {
        return false;
       }

    if( getVertexIndex( otherVertex, vertexIndex ) )
       {
        otherVertexIndex = vertexIndex;
       }

    else if( Vertices.getSize() < graphSize )
       {
        otherVertexIndex = Vertices.getSize();

        Vertices[ Vertices.getSize() ].vertexLetter = otherVertex;

        Vertices.incrementSize();
       }

    else
       {
        return false;
       }

    newPathTypeItem.vertexLetter = otherVertex;
    newPathTypeItem.pathWeight = weight;
    AdjacencyMatrix[ oneVertexIndex ][ otherVertexIndex ] = newPathTypeItem;

    newPathTypeItem.vertexLetter = oneVertex;
    newPathTypeItem.pathWeight = weight;
    AdjacencyMatrix[ otherVertexIndex ][ oneVertexIndex ] = newPathTypeItem;

    return true;
   }

/**
 * @brief Sets vertex state to used or not used
 *
 * @details None
 *          
 * @param in: Vertex letter to be used
 * @param in: Boolean state to set vertex
 *
 * @note None
 */
void GraphClass::setVertexState
       (
        char vertex,      // in: vertex letter to be used
        bool vertexState  // in: vertex state to be applied
       )
   {
    int vertexIndex;

    if( getVertexIndex( vertex, vertexIndex ) )
       {
        Vertices[ vertexIndex ].usedState = vertexState;
       }
   }

/**
 * @brief Gets next vertex for the given base, if available
 *
 * @details Returns vertex and true if successful,
 *          dummy vertex and false if not
 *          
 * @param in/out: index at which to start searching,
 *                returns present location to calling function
 *        out: PathType object returned
 *
 * @note None
 */
bool GraphClass::getNextVertex
       (
        char vertexRowLetter,  // in: identifies row in adj matrix
        int &startIndex,       // in: specifies column index in adj matrix
        PathType &nextVertex   // in: PathType to be returned
       )
   {
    int rowIndex, letterFoundIndex;
    char letterFound;
    bool letterFoundState;

    while( startIndex < graphSize )
       {
        getVertexIndex( vertexRowLetter, rowIndex );

        letterFound = AdjacencyMatrix[ rowIndex ][ startIndex ].vertexLetter;

        letterFoundState = ( letterFound != PathType::DUMMY_VERTEX );

        getVertexIndex( letterFound, letterFoundIndex );

        if( letterFoundState && !Vertices[ letterFoundIndex ].usedState )
           {
            nextVertex = AdjacencyMatrix[ rowIndex ][ startIndex ];

            startIndex++;  // starts at next element in subsequent call

            return true;
           }

        startIndex++;
       }

    return false;
   }

/**
 * @brief Displays adjacency table
 *
 * @details None
 *          
 * @param in: None
 *
 * @note None
 */

void GraphClass::dumpAdjacencyTable
       (
        // no parameters
       )
   {
    int rowIndex, colIndex;

    cout << endl << "Adjacency Table:" << endl;

    for( rowIndex = 0; rowIndex < graphSize; rowIndex++ )
       {
        cout << Vertices[ rowIndex ].vertexLetter << ": ";

        for( colIndex = 0; colIndex < graphSize; colIndex++ )
           {
            if( colIndex > 0 )
               {
                cout << "; ";
               }

            cout << AdjacencyMatrix[ rowIndex ][ colIndex ].vertexLetter;
            cout << ", " 
                 << AdjacencyMatrix [ rowIndex][ colIndex ].pathWeight;
           }

        cout << endl;
       }

    cout << endl << endl;
   }

/**
 * @brief Gets vertex index if it is in the array
 *
 * @details Returns vertex index and true if it is found,
 *          false otherwise
 *          
 * @param in: vertex letter requested
 *
 * @note None
 */
bool GraphClass::getVertexIndex
       (
        char vertex,
        int &foundIndex
       )
   {
    int index = 0;

    foundIndex = INDEX_NOT_FOUND;

    while( index < graphSize )
       {
        if( Vertices[ index ].vertexLetter == vertex ) 
           {
            foundIndex = index;

            return true;
           }

        index++;
       }

    return false;
   }

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef GRAPHCLASS_CPP







