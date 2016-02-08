// Program Information ////////////////////////////////////////////////////////
/**
 * @file OrderedSetClass.cpp
 * 
 * @author Michael Leverington
 *
 * @brief Implementation file for OrderedSetClass class
 * 
 * @details Implements all member methods of the OrderedSetClass class
 *
 * @version 1.20 (18 October 2015) 
 *                corrected copy vector method issue
 *                corrected related grow and shrink issues
 *          1.10 (11 September 2015)
 *               added getter and setter for date elements
 *          1.00 (30 August 2015)
 *               origination
 *
 * @Note Requires OrderedSetClass.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef ORDEREDSET_CLASS_CPP
#define ORDEREDSET_CLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "OrderedSetClass.h"
#include "SimpleVector.cpp"

/**
 * @brief Default constructor
 *
 * @details Constructs OSC using SimpleVector as storage engine
 *          
 * @param None
 *
 * @note None
 */

OrderedSetClass::OrderedSetClass
       (
        // data loaded via initializers
       )
    : OS_Data()
   {
    // data loaded via initializers
   }

/**
 * @brief Initialization constructor
 *
 * @details Constructs OSC to given capacity
 *          using SimpleVector as storage engine
 *          
 * @param in: capacity with which to initialize vector
 *
 * @note None
 */
OrderedSetClass::OrderedSetClass
       ( 
        int newCapacity // in: new vector capacity
       )
     : OS_Data( newCapacity )
   {
    // data loaded via initializers
   }

/**
 * @brief Copy constructor
 *
 * @details Constructs OSC with copied OSC
 *          
 * @param in: Other OSC with which this OSC is constructed
 *
 * @note None
 */
OrderedSetClass::OrderedSetClass
       ( 
        const OrderedSetClass &copiedOSC // in: OSC to copy
       )
   {
    OS_Data = copiedOSC.OS_Data;
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
OrderedSetClass::~OrderedSetClass
       (
        // no parameters
       )
   {
    // No action - data is destructed in SimpleVector
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
const OrderedSetClass &
OrderedSetClass::operator = 
       (
        const OrderedSetClass &rhOSC // in: assigned right side
       )
   {
    if( this != &rhOSC )
       {
        OS_Data = rhOSC.OS_Data;
       }

    return *this; 
   }

/**
 * @brief addition assignment operation overload
 *
 * @details Appends data from right-hand OSC to this OSC
 *          
 * @param in: right-hand OSC object
 *
 * @note Appends right-hand side data to SimpleVector
 */
const OrderedSetClass &OrderedSetClass::operator += 
       (
        const OrderedSetClass &rhOSC // in: appended right side
       )
   {
    int localIndex = OS_Data.getSize();
    int newSize = OS_Data.getSize() + rhOSC.getSize() + 1;
    int rhIndex = 0;

    if( newSize >= OS_Data.getCapacity() )
       {
        OS_Data.grow( newSize - OS_Data.getCapacity() + DEFAULT_GROW_QUANTITY );
       }
    
    while( rhIndex < rhOSC.getSize() )
       {
        OS_Data[ localIndex ] = rhOSC.OS_Data[ rhIndex ];

        OS_Data.incrementSize();

        localIndex++; rhIndex++;
       }

    return *this; 
   }

/**
 * @brief addition assignment operation overload for one letter
 *
 * @details Appends data from letter to this OSC
 *          
 * @param in: vertex letter
 *
 * @note Appends vertex letter data to SimpleVector
 */
const OrderedSetClass &OrderedSetClass::operator += 
       (
        char vertexLetter // in: appended letter
       )
   {
    int newSize = OS_Data.getSize() + 1;

    if( newSize >= OS_Data.getCapacity() )
       {
        OS_Data.grow( newSize - OS_Data.getCapacity() + DEFAULT_GROW_QUANTITY );
       }
    
    OS_Data[ OS_Data.getSize() ] = vertexLetter;

    OS_Data.incrementSize();

    return *this; 
   }

/**
 * @brief OSC capacity accessor
 *
 * @details returns capacity of this OSC
 *          
 * @param None
 *
 * @note None
 */
int OrderedSetClass::getCapacity
       (
        // no parameters
       ) const
   {
    return OS_Data.getCapacity();
   }

/**
 * @brief OSC size accessor
 *
 * @details returns size of this OSC
 *          
 * @param None
 *
 * @note None
 */
int OrderedSetClass::getSize
       (
        // no parameters
       ) const
   {
    return OS_Data.getSize();
   }

/**
 * @brief OSC accessor for last item in set
 *
 * @details returns last item in set as reference parameter, 
 *          returns Boolean success if set had an item, 
 *          no class modification
 *          
 * @param None
 *
 * @note None
 */
bool OrderedSetClass::peekAtEndItem
       (
        char &vertex
       ) const
   {
    if( OS_Data.getSize() > 0 )
       {
        vertex = OS_Data[ OS_Data.getSize() - 1 ];

        return true;
       }

    return false;
   }

/**
 * @brief Dumps OSC data to vector
 *
 * @details loads OSC data to accessable vector for display or analysis
 *          
 * @param None
 *
 * @note None
 */
void OrderedSetClass::dumpSet
       (
       ) const
   {
    int index;

    if( OS_Data.getSize() > 0 )
       {
        cout << endl << "Vertices: ";

        for( index = 0; index < OS_Data.getSize(); index++ )
           {
            if( index > 0 )
               {
                cout << ", ";
               }

            cout << OS_Data[ index ];
           }

        cout << endl << endl;
       }

    else
       {
        cout << endl << "No Data: Empty Set" << endl << endl;    
       }
   }

/**
 * @brief Removes last item in OSC
 *
 * @details removes last item in OSC by reducing size value
 *          returns Boolean success if set had an item
 *          
 * @param None
 *
 * @note None
 */
bool OrderedSetClass::removeEndItem
       (
        char &vertex
       )
   {
    if( OS_Data.getSize() > 0 )
       {
        vertex = OS_Data[ getSize() - 1 ];

        OS_Data.decrementSize();

        return true;
       }

    return false;
   }

/**
 * @brief clears OSC
 *
 * @details clears OSC by setting size to zero
 *          
 * @param None
 *
 * @note None
 */
void OrderedSetClass::clearOrderedSet
       (
        // no parameter
       )
   {
    while( OS_Data.getSize() > 0 )
       {
        OS_Data.decrementSize();
       }
   }


// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef ORDEREDSET_CLASS_CPP







