// Program Information ////////////////////////////////////////////////////////
/**
 * @file DateType.h
 *
 * @brief Definition file for DateType class
 * 
 * @details Specifies all data of the DateType class,
 *          along with the constructor,
 *          DateType class is entered and stored as a string
 *
 * @author Michael Leverington
 *
 * @version 1.00 (11 September 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_DATETYPE_H
#define CLASS_DATETYPE_H

// Header files ///////////////////////////////////////////////////////////////

#include <ostream>

using namespace std;

// Class constants ////////////////////////////////////////////////////////////

   // None

// Class definition ///////////////////////////////////////////////////////////

class DateType
   {
    public:

       DateType();

       DateType( char *newDate );

       static const int STD_STR_LEN = 25;

       char date[ STD_STR_LEN ];
   };

// Free function output operator  /////////////////////////////////////////////

ostream& operator << ( ostream& outStream, const DateType &dateItem );

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_DATETYPE_H



