// Program Information ////////////////////////////////////////////////////////
/**
 * @file SimpleMatrix.cpp
 * 
 * @author Michael Leverington
 *
 * @brief Implementation file for SimpleMatrix class
 * 
 * @details Implements all member methods of the SimpleMatrix class
 *
 * @version 1.10 (17 October 2015)
 *
 *
 * @Note Requires SimpleMatrix.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_SIMPLEMATRIX_CPP
#define CLASS_SIMPLEMATRIX_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "SimpleMatrix.h"

/**
 * @brief Default constructor
 *
 * @details Constructs vector capacity to default and vector size to zero
 *          creates default size data array
 *          
 * @param None
 *
 * @note None
 */
template <class DataType>
SimpleMatrix<DataType>::SimpleMatrix
       (
        // data loaded via initializers
       )
    : rowCapacity( DEFAULT_CAPACITY ), colCapacity( DEFAULT_CAPACITY), 
      matrixData()
   {
    // data loaded via initializers
   }

/**
 * @brief Initialization constructor
 *
 * @details Constructs matrix capacities to given capacities
 *          creates matrix of given row/col capacity size
 *          
 * @param in: row capacity with which to initialize matrix
 * @param in: col capacity with which to initialize matrix
 *
 * @notes None
 */
template <class DataType>
SimpleMatrix<DataType>::SimpleMatrix
       ( 
        int newRows,    // in: new row capacity
        int newCols     // in: new col capacity
        )
     : rowCapacity( newRows ), colCapacity( newCols),
       matrixData( rowCapacity )
   {
    resizeCols( newCols );       
   }

/**
 * @brief Initialization constructor
 *
 * @details Constructs vector to given capacity and zero size
 *          and sets each element to given fill value
 *          
 * @param in: capacity with which to initialize vector
 * @param in: fill value with which to initialize each element
 *
 * @note None
 */
template <class DataType>
SimpleMatrix<DataType>::SimpleMatrix
       ( 
        int newRows,          // in: new row capacity
        int newCols,          // in: new col capacity
        const DataType &fillValue // in: fill value for all elements
       )
     : rowCapacity( newRows ), colCapacity( newCols ), 
       matrixData( rowCapacity )
   {
    int rowIndex, colIndex;

    resizeCols( newCols );

    for( rowIndex = 0; rowIndex < rowCapacity; rowIndex++ )
       {
        for( colIndex = 0; colIndex < colCapacity; colIndex++ )
           {
            matrixData[ rowIndex ][ colIndex ] = fillValue;
           }
       }
   }

/**
 * @brief Copy constructor
 *
 * @details Constructs matrix capacity to copied specifications,
 *          with copied data
 *          
 * @param in: Other vector with which this vector is constructed
 *
 * @note Uses copyVector to move data into this 
 */
template <class DataType>
SimpleMatrix<DataType>::SimpleMatrix
       ( 
        const SimpleMatrix<DataType> & copiedMatrix // in: matrix to copy
       )
     : rowCapacity( copiedMatrix.rowCapacity ),
       colCapacity( copiedMatrix.colCapacity ),
       matrixData( rowCapacity )
   {
    resizeCols( colCapacity );

    copyMatrix( matrixData, copiedMatrix.matrixData );
   }

/**
 * @brief object destructor
 *
 * @details Uses parent (SimpleVector) destructors
 *          
 * @param None
 *
 * @note None
 */
template <class DataType>
SimpleMatrix<DataType>::~SimpleMatrix
       (
        // no parameters
       )
   {
    // destruction conducted in SimpleVector(s)
   }

/**
 * @brief assignment operation overload
 *
 * @details Assigns data from right-hand object to this object
 *          
 * @param in: right-hand vector object
 *
 * @note Uses copyVector to move data into this vector
 */
template <class DataType>
const SimpleMatrix<DataType> &
SimpleMatrix<DataType>::operator = 
       (
        const SimpleMatrix<DataType> &rhMatrix // in: assigned right side
       )
   {
    if( this != &rhMatrix )
       {
        rowCapacity = rhMatrix.rowCapacity;
        colCapacity = rhMatrix.colCapacity;

        resizeRows( rowCapacity );
        resizeCols( colCapacity );

        copyMatrix( matrixData, rhMatrix.matrixData );
       }

    return *this; 
   }

/**
 * @brief matrix row capacity accessor
 *
 * @details returns row capacity of this matrix
 *          
 * @param None
 *
 * @note None
 */
template <class DataType>
int SimpleMatrix<DataType>::getNumRows
       (
        // no parameters
       ) const
   {
    return rowCapacity;
   }

/**
 * @brief matrix col capacity accessor
 *
 * @details returns col capacity of this matrix
 *          
 * @param None
 *
 * @note None
 */
template <class DataType>
int SimpleMatrix<DataType>::getNumCols
       (
        // no parameters
       ) const
   {
    return colCapacity;
   }

/**
 * @brief matrix row overloaded bracket operation
 *
 * @details allows assignment of data to element in this matrix row
 *          
 * @param in: index of row to be assigned
 *
 * @note throws logic error if index is out of bounds
 */
template <class DataType>
SimpleVector<DataType> &SimpleMatrix<DataType>::operator [] 
       ( 
        int index // in: index for array element
       ) 
     throw ( logic_error )
   {
    if ( index >= 0 && index < rowCapacity )
       {
        return matrixData[ index ];
       }

    throw logic_error( "ERROR: Array Row index out of bounds" );
   }

/**
 * @brief matrix overloaded bracket operation
 *
 * @details allows assignment of data from row in this matrix
 *          
 * @param in: index of matrix row to be assigned
 *
 * @note throws logic error if index is out of bounds
 */
template <class DataType>
const SimpleVector<DataType> &SimpleMatrix<DataType>::operator [] 
       ( 
        int index // in: index for array element
       ) const 
         throw ( logic_error )
   {
    if ( index >= 0 && index < rowCapacity )
       {
        return matrixData[ index ];
       }

    throw logic_error( "ERROR: Array Row index out of bounds" );
   }

/**
 * @brief vector data setting operation
 *
 * @details allows assignment of data directly to the vector
 *          
 * @param in: row index of element to be assigned
 * @param in: col index of element to be assigned
 * @param in: data item to be stored in array
 *
 * @note throws logic error if index is out of bounds
 */
template <class DataType>
void SimpleMatrix<DataType>::setValueAt
       ( 
        int rowIndex,            // in: row index of matrix element
        int colIndex,            // in: col index of matrix element
        const DataType &item     // in: data to be stored
       )
     throw ( logic_error )
   {
    if( rowIndex >= 0 && rowIndex < rowCapacity 
                     && colIndex >= 0 && colIndex < colCapacity )
       {
        matrixData[ rowIndex ][ colIndex ] = item;
       }

    else
       {
        throw logic_error( "ERROR: Array index out of bounds" );
       }
   }

/**
 * @brief matrix data getting operation
 *
 * @details allows direct access of the data from the matrix
 *          
 * @param in: row index of element to be retrieved
 * @param in: col index of element to be retrieved
 * @param in: data item to be retrieved from array
 *
 * @note throws logic error if index is out of bounds
 */
template <class DataType>
void SimpleMatrix<DataType>::getValueAt
       ( 
        int rowIndex,      // in: row index of matrix element
        int colIndex,      // in: col index of matrix element
        DataType &item  // out: data accessed from vector
       ) 
     const throw ( logic_error )
   {
    if( rowIndex >= 0 && rowIndex < rowCapacity 
                     && colIndex >= 0 && colIndex < colCapacity )
       {
        item = matrixData[ rowIndex ][ colIndex ];
       }

    else
       {
        throw logic_error( "ERROR: Array index out of bounds" );
       }
   }

/**
 * @brief matrix resize operation
 *
 * @details resizes rows and columns
 *          
 * @param in: new row capacity
 * @param in: new col capacity
 *
 * @note None
 *       
 */
template <class DataType>
void SimpleMatrix<DataType>::resize
       ( 
        int newRowCapacity,   // in: new row capacity requested
        int newColCapacity   // in: new col capacity requested
       )
   {
    resizeRows( newRowCapacity );

    rowCapacity = newRowCapacity;

    resizeCols( newColCapacity );

    colCapacity = newColCapacity;
   }

/**
 * @brief matrix row resizing tool
 *
 * @details row resize
 *          
 * @param in: new row capacity
 *
 * @note None
 *       
 */
template <class DataType>
void SimpleMatrix<DataType>::resizeRows
       ( 
        int newRowCapacity   // in: new capacity requested
       )
   {
    if( newRowCapacity > matrixData.getCapacity() )
       {
        matrixData.grow( newRowCapacity - matrixData.getCapacity() );
       }

    else if( newRowCapacity < matrixData.getCapacity() )
       {
        matrixData.shrink( matrixData.getCapacity() - newRowCapacity );
       }
   }

/**
 * @brief matrix column resizing tool
 *
 * @details row by row resize
 *          
 * @param in: new column capacity
 *
 * @note None
 *       
 */
template <class DataType>
void SimpleMatrix<DataType>::resizeCols
       ( 
        int newColCapacity   // in: new capacity requested
       )
   {
    int presentCapacity = matrixData[ 0 ].getCapacity();

    int rowIndex;

    if( newColCapacity > presentCapacity )
       {
        for( rowIndex = 0; rowIndex < rowCapacity; rowIndex++ )
           {
            matrixData[ rowIndex ].grow( newColCapacity 
                                     - matrixData[ rowIndex ].getCapacity() );
           }
       }

    else if( newColCapacity < presentCapacity )
       {
        for( rowIndex = 0; rowIndex < rowCapacity; rowIndex++ )
           {
            matrixData[ rowIndex ].shrink( matrixData[ rowIndex ].getCapacity() 
                                                           - newColCapacity );
           }
       }

   }

/**
 * @brief matrix copy tool
 *
 * @details private element by element copy operation
 *          
 * @param in: destination matrix
 * @param in: source matrix
 *
 * @note copies data from source matrix to destination matrix
 *       element by element
 *       
 */
template <class DataType>
void SimpleMatrix<DataType>::copyMatrix
       ( 
        SimpleVector<SimpleVector<DataType> > &dest, // out: copied matrix, destination
        const SimpleVector<SimpleVector<DataType> > &source   // in: matrix copied, source
       )
   {
    int rowIndex;

    for( rowIndex = 0; rowIndex < rowCapacity; rowIndex++ )
       {
        dest[ rowIndex ] = source[ rowIndex ];
       }
   }

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_SIMPLEMATRIX_CPP







