// Program Information ////////////////////////////////////////////////////////
/**
 * @file DataType.cpp
 *
 * @brief Implementation file for DataType class
 * 
 * @details Implements the constructor method of the DataType class
 *
 * @version 1.00 (07 September 2015)
 *
 * @Note Requires DataType.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_DATATYPE_CPP
#define CLASS_DATATYPE_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "DataType.h"
#include <cstring>

using namespace std;

/**
 * @brief Default constructor
 *
 * @details Constructs empty DataType
 *          
 * @param None
 *
 * @note None
 */
DataType::DataType
       ( 
        // no parameters
       )
     : priority( 0 ) 
   {
    strcpy( process, "" );
   }

/**
 * @brief Initialization constructor
 *
 * @details Constructs DataType with data components
 *          
 * @param in: priority level to be loaded into DataType
 * @param in: process data to be loaded into DataType
 *
 * @note None
 */
DataType::DataType
       ( 
        int newPriority, // in: new priority
        char *newProcess // in: new process
       )
     : priority( newPriority ) 
   {
    strcpy( process, newProcess );
   }

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_DATATYPE_CPP



