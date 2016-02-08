// Program Information ////////////////////////////////////////////////////////
/**
 * @file DataType.h
 *
 * @brief Definition file for DataType class
 * 
 * @details Specifies all data of the DataType class,
 *          along with the constructor
 *
 * @version 1.00 (07 September 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_DATATYPE_H
#define CLASS_DATATYPE_H

// Header files ///////////////////////////////////////////////////////////////

   // None

// Class constants ////////////////////////////////////////////////////////////

   // None

// Class definition ///////////////////////////////////////////////////////////

class DataType
   {
    public:

       DataType();

       DataType( int newPriority, char *newProcess );

       static const int STD_STR_LEN = 25;

       int priority;

       char process[ STD_STR_LEN ];
   };

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_DATATYPE_H



