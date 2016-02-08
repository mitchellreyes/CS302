// Program Information ////////////////////////////////////////////////////////
/**
 * @file NameType.h
 *
 * @brief Definition file for NameType class
 * 
 * @details Specifies all data of the NameType class,
 *          along with the constructor,
 *          NameType class is entered and stored as a string
 *
 * @author Michael Leverington
 *
 * @version 1.00 (03 October 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_NAMETYPE_H
#define CLASS_NAMETYPE_H

// Header files ///////////////////////////////////////////////////////////////

#include <ostream>
#include <stdexcept>

using namespace std;

// Class constants ////////////////////////////////////////////////////////////

   // None

// Class definition ///////////////////////////////////////////////////////////

class NameType
   {
    public:

       static const char NULL_CHAR = '\0';
       static const char COMMA = ',';
       static const char SPACE = ' ';
       static const int STD_NAME_LEN = 100;

       NameType();
       NameType( const char *newName );
       NameType( const NameType &newNameObject );

       ~NameType();

       const NameType &operator = ( const NameType &rhName );

       bool setName( const char *newName );
       void getName( char *retName ) const;

       int compareTo( const NameType &rhName ) const throw ( logic_error );

    private:

       void copyString( char *destination, const char *source ) const;
       int getStrLen( const char *str ) const;
       char toUpper( char letter ) const;

       char *nameData;
   };

// Free function output operator  /////////////////////////////////////////////

ostream& operator << ( ostream& outStream, const NameType &name );

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_NAMETYPE_H



