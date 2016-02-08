// Program Information ////////////////////////////////////////////////////////
/**
 * @file SorterClass.h
 *
 * @brief Definition file for Sorter class
 * 
 * @author Michael Leverington
 * 
 * @details Specifies all member methods of the SorterClass
 *
 * @version 1.00 (11 September 2015)
 *
 * @Note Requires SimpleVector.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef SORTERCLASS_H
#define SORTERCLASS_H

// Header files ///////////////////////////////////////////////////////////////

#include "SimpleVector.h"

// Class definition  //////////////////////////////////////////////////////////

template <typename DataType> 
class SorterClass: public SimpleVector<DataType>
  {
    public: 

      SorterClass();
      SorterClass( int initialCapacity ); 
      SorterClass( const SorterClass<DataType> &copiedSorter );

      // Destructor
      virtual ~SorterClass();

      // modifier
      virtual void add( const DataType &addedObject );

      // Virtual Functions Defined
       
         // Compare Two elements
         virtual int compareTo( const DataType &lhObject, 
                                                    const DataType &rhObject);  

         // Sort List Using compareTo()
         virtual bool sort();   
  };

  #endif // ifndef SORTERCLASS_H


