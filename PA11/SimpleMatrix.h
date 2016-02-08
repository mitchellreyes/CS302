// Program Information ////////////////////////////////////////////////////////
/**
 * @file SimpleMatrix.h
 *
 * @brief Definition file for SimpleMatrix class
 * 
 * @author Michael Leverington
 * 
 * @details Specifies all member methods of the SimpleMatrix class
 *
 * @version 1.00 (17 October 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_SIMPLEMATRIX_H
#define CLASS_SIMPLEMATRIX_H

// Header files ///////////////////////////////////////////////////////////////

#include <stdexcept>
#include "SimpleVector.cpp"

using namespace std;

// Class definition  //////////////////////////////////////////////////////////

template <class DataType>
class SimpleMatrix
   {
    public:

    // Internal constant
    static const int DEFAULT_CAPACITY = 10;

    // constructors
    SimpleMatrix();
    SimpleMatrix ( int newRows, int newCols );
    SimpleMatrix( int newRows, int newCols, const DataType &fillValue );
    SimpleMatrix( const SimpleMatrix &copiedMatrix ); 

    // destructor
    ~SimpleMatrix( );

    // assignment
    const SimpleMatrix &operator = ( const SimpleMatrix &rhMatrix );

    // accessors
    int getNumRows() const;
    int getNumCols() const;

    // index access
    SimpleVector<DataType> &operator [ ] ( int index ) throw ( logic_error );
    const SimpleVector<DataType> &operator [ ] ( int index ) 
                                                 const throw ( logic_error );

    // modifiers

       // set value in array, without index brackets
       void setValueAt( int rowIndex, int colIndex, const DataType &item )
                                                      throw ( logic_error );

       // get value in array, without index brackets
       void getValueAt( int rowIndex, int colIndex, DataType &item ) 
                                                const throw ( logic_error );

       // allows matrix resize
       void resize( int newNumRows, int newNumCols );

  private:

    int rowCapacity, colCapacity;
    SimpleVector<SimpleVector<DataType> > matrixData;

    void resizeRows( int newRowCapacity );
    void resizeCols( int newColCapacity );
    void copyMatrix( SimpleVector<SimpleVector<DataType> > &dest,
                       const SimpleVector<SimpleVector<DataType> > &source );
   };

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_SIMPLEMATRIX_H


