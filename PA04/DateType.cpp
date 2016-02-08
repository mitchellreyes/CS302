// Program Information ////////////////////////////////////////////////////////
/**
 * @file DateType.cpp
 *
 * @brief Implementation file for DateType class
 * 
 * @details Implements the constructor method of the DateType class
 *
 * @author Michael Leverington
 *
 * @version 1.00 (11 September 2015)
 *
 * @Note Requires DateType.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_DATETYPE_CPP
#define CLASS_DATETYPE_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "DateType.h"
#include <cstring>

using namespace std;

/**
 * @brief Default constructor
 *
 * @details Constructs empty DateType
 *          
 * @param None
 *
 * @note None
 */
DateType::DateType
       ( 
        // no parameters
       )
   {
    strcpy( date, "" );
   }

/**
 * @brief Initialization constructor
 *
 * @details Constructs DateType with data components
 *          
 * @param in: new data, in string form
 *
 * @note None
 */
DateType::DateType
       ( 
        char *newDate // in: new date
       )
   {
    strcpy( date, newDate );
   }

// Free function output operator  ////////////////////////////////////////////
/**
 * @brief ostream output operator
 *
 * @details Free function outputs DateType to stream
 *          
 * @param in: ostream file object
 * @param in: DateType data item
 *
 * @note None
 */
ostream& operator << ( ostream &outStream, const DateType &dateItem )
   {
    outStream << dateItem.date;

    return outStream;
   }

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_DATETYPE_CPP



