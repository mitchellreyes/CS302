// Program Information ////////////////////////////////////////////////////////
/**
 * @file SorterClass.cpp
 * 
 * @brief Implementation file for SorterClass
 * 
 * @author Michael Leverington
 *
 * @details Implements all member methods of the SorterClass
 *
 * @version 1.00 (11 September 2015)
 *
 * @Note Requires SorterClass.h, SimpleVector.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef SORTERCLASS_CPP
#define SORTERCLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "SorterClass.h"
#include "SimpleVector.h"

/**
 * @brief Default constructor
 *
 * @details Constructs sorter class with default vector class initialization
 *          
 * @param None
 *
 * @note None
 */
template <typename DataType>
SorterClass<DataType>::SorterClass
       (
        // no parameters
       )
     : SimpleVector<DataType>()
   {
    // construct parent
   }

/**
 * @brief Initialization constructor
 *
 * @details Constructs sorter class with specified vector class initialization
 *          
 * @param in: initial capacity
 *
 * @note None
 */
template <typename DataType>
SorterClass<DataType>::SorterClass
       (
        int initialCapacity // in: initial capacity for vector
       )
     : SimpleVector<DataType>( initialCapacity )
   {
    // construct parent
   }

/**
 * @brief Copy constructor
 *
 * @details Constructs sorter class with copied object
 *          
 * @param in: other SorterClass object
 *
 * @note None
 */
template <typename DataType>
SorterClass<DataType>::SorterClass
       (
        const SorterClass<DataType> &copiedSorter // in: other sorter class object
       )
     : SimpleVector<DataType>( copiedSorter )
   {
    // construct parent
   }

/**
 * @brief Class destructor
 *
 * @details Destructs sorter class
 *          
 * @param in: None
 *
 * @note Implements SimpleVector destructor
 */
template <typename DataType>
SorterClass<DataType>::~SorterClass
     (
      // no parameters
     )
   {
    // parent class (SimpleVector) destructs
   }

/**
 * @brief add item to sorter list
 *
 * @details adds item to list for sorting
 *          
 * @param in: object to be added
 *
 * @note None
 */
template <typename DataType>
void SorterClass<DataType>::add
       ( 
        const DataType &addedObject // in: object to be added to list
       )
   {
    if( this->getSize() == this->getCapacity() )
      {
       // for case of empty capacity
       if( this->getCapacity() > 0 )
          {
           this->grow( this->getCapacity() ); // double capacity
          }

       else
          {
           this->grow( this->DEFAULT_CAPACITY );
          }
      }

    this->setValueAt( this->getSize(), addedObject );

    this->incrementSize();
   }

/**
 * @brief Object comparison, necessary for sorting
 *
 * @details Compares objects mathematically, 
 *          returns value < 0 if lhO < rhO
 *          returns  0 if lhO = rhO
 *          returns value > 0 if lhO > rhO
 *          
 * @param in: Left hand object, right hand object
 *
 * @note Simple mathematical base operation; assumed to be overridden
 */
template <typename DataType>
int SorterClass<DataType>::compareTo 
     (
      const DataType &lhObject, // in: leftHandObject
      const DataType &rhObject  // in: rightHandObject
     )
   {
    // virtual method takes no action
    return 0;
   }

/**
 * @brief Sorting operation
 *
 * @details Virtual sort method that can be overridden
 *          to use various sorting strategies
 *          
 * @param in: None
 *
 * @note None, virtual method takes no action, assumed to be overridden
 */
template <typename DataType>
bool SorterClass<DataType>::sort()
   {
    // virtual method takes no action

    return false; // temporary virtual method return
   }

#endif // ifndef SORTERCLASS_CPP

