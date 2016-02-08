// Program Information ////////////////////////////////////////////////////////
/**
 * @file NameType.cpp
 *
 * @brief Implementation file for NameType class
 * 
 * @details Implements the constructor method of the NameType class
 *
 * @author Michael Leverington
 *
 * @version 1.00 (03 October 2015)
 *
 * @Note Requires NameType.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_NAMETYPE_CPP
#define CLASS_NAMETYPE_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "NameType.h"

/**
 * @brief Default constructor
 *
 * @details Constructs empty NameType
 *          
 * @param None
 *
 * @note None
 */
NameType::NameType
       ( 
        // no parameters
       )
     : nameData( NULL )
   {
    // assignment in initializers
   }

/**
 * @brief Initialization constructor
 *
 * @details Places name data into object
 *          
 * @param in: New string name
 *
 * @note None
 */
NameType::NameType
       ( 
        const char *newName // in: new c-string name
       )
     : nameData( NULL )
   {
    setName( newName );    
   }

/**
 * @brief Copy constructor
 *
 * @details Places name data into object
 *          
 * @param in: New NameType object
 *
 * @note None
 */
NameType::NameType
       ( 
        const NameType &newNameObject // in: new NameType object
       )
     : nameData( NULL )
   {
    setName( newNameObject.nameData );    
   }

/**
 * @brief Destructor
 *
 * @details Non-acting destructor, no dynamic data
 *          
 * @param None
 *
 * @note None
 */
NameType::~NameType
       ( 
       )
   {
    if( nameData != NULL )
       {
        delete nameData;

        nameData = NULL;
       }

    // no destructor action
   }

/**
 * @brief Overloaded assignment operator
 *
 * @details Assign data to other NameType
 *          
 * @param in: Assigned name
 *
 * @note None
 */
const NameType &NameType::operator =
       (
        const NameType &rhName // in: assigned name
       )
   {
    if( this != &rhName )
       {
        setName( rhName.nameData );
       }

    return *this;
   }

/**
 * @brief Sets name in data type
 *
 * @details Assign data to c-string
 *          
 * @param in: Assigned name
 *
 * @note Attempts to standardize name (LastName, FirstName)
 */
bool NameType::setName
       (
        const char *newName // in: assigned name
       )
   {
    int sourceIndex = 0, destIndex = 0;
    bool lastNameFound = false, firstNameFound = false;

    // make room for new name
    if( nameData != NULL )
       {
        delete nameData;
       }
 
    nameData = new char[ getStrLen( newName ) + 1 ];

    while( newName[ sourceIndex ] != NULL_CHAR 
                                          && newName[ sourceIndex ] == SPACE )
       {
        sourceIndex++;
       }

    while( newName[ sourceIndex ] != NULL_CHAR )
       {
        if( newName[ sourceIndex ] == SPACE 
                             && ( newName[ sourceIndex + 1 ] == SPACE
                             || newName[ sourceIndex + 1 ] == COMMA
                             || newName[ sourceIndex + 1 ] == NULL_CHAR ) )
           {
            sourceIndex++;
           }

        else if( newName[ sourceIndex ] == COMMA )
           {
            if( destIndex > 0 && !lastNameFound )
               {
                nameData[ destIndex ] = COMMA;
                destIndex++;

                if( newName[ sourceIndex + 1 ] != SPACE )
                   {
                    nameData[ destIndex ] = SPACE;
                    destIndex++;
                   }

                lastNameFound = true;
               }
        
            sourceIndex++;
           }

        else
           {
            nameData[ destIndex ] = newName[ sourceIndex ];

            destIndex++; sourceIndex++;

            nameData[ destIndex ] = NULL_CHAR;

            if( lastNameFound )
               {
                firstNameFound = true;
               }
           }
       }

    return lastNameFound && firstNameFound;
   }

/**
 * @brief Gets name from data type
 *
 * @details Return data as c-string
 *          
 * @param out: returned name
 *
 * @note None
 */
void NameType::getName
       (
        char *retName // in: returned name
       ) const
   {
    copyString( retName, nameData );
   }

#include <iostream>
using namespace std;

/**
 * @brief Compares this name against another
 *
 * @details Return < 0 if this item is less than right hand item
 *          Return > 0 if this item is greater than right hand item
 *          Return 0 if this item is equal to right hand item
 *          
 * @param out: returned name
 *
 * @note None
 */
int NameType::compareTo
       (
        const NameType &rhName
       )
     const throw ( logic_error )
   {
    int diff, index = 0;

    if( this == &rhName )
       {
        return 0;
       }

    while( nameData[ index ] != NULL_CHAR 
            && rhName.nameData[ index ] != NULL_CHAR 
                && nameData[ index ] != COMMA 
                    && rhName.nameData[ index ] != COMMA )
       {
        diff = toUpper( nameData[ index ] ) 
                              - toUpper( rhName.nameData[ index ] );

        if( diff != 0 )
           {
            return diff;
           }

        index++;
       }

    if( nameData[ index] == NULL_CHAR || rhName.nameData[ index ] == NULL_CHAR )
       {
        throw logic_error( "Attempt to compare malformed name" );
       }

    if( nameData[ index ] == COMMA && rhName.nameData[ index ] != COMMA )
       {
        return -1;
       }

    if( nameData[ index ] != COMMA && rhName.nameData[ index ] == COMMA )
       {
        return 1;
       }

    while( nameData[ index ] != NULL_CHAR 
                                 && rhName.nameData[ index ] != NULL_CHAR )
       {
        diff = toUpper( nameData[ index ] ) 
                              - toUpper( rhName.nameData[ index ] );

        if( diff != 0 )
           {
            return diff;
           }

        index++;
       }

    return getStrLen( nameData ) - getStrLen( rhName.nameData );
   }

/**
 * @brief Simple string copy
 *
 * @details Copies string from source to destination
 *          
 * @param in: source string
 * @param out: destination string
 *
 * @note None
 */
void NameType::copyString
       ( 
        char *destination,  // out: destination string
        const char *source // in: source string
       ) const
   {
    int index = 0;

    while( source[ index ] != NULL_CHAR )
       {
        destination[ index ] = source[ index ];

        index++;

        destination[ index ] = NULL_CHAR;
       }
   }

/**
 * @brief Simple string length function
 *
 * @details Finds string length
 *          
 * @param in: string
 *
 * @note None
 */
int NameType::getStrLen
       ( 
        const char *str // in: string
       ) const
   {
    int index;

    for( index = 0; str[ index ] != NULL_CHAR; index++ );

    return index;
   }

/**
 * @brief Changes lower case letter to upper
 *
 * @details Makes no other change if incomingletter is not lower case
 *          
 * @param in: char
 *
 * @note None
 */
char NameType::toUpper
       ( 
        char letter // in: test letter
       ) const
   {
    if( letter >= 'a' && letter <= 'z' )
       {
        letter = letter - 'a' + 'A';
       }

    return letter;
   }

// Free function output operator  ////////////////////////////////////////////
/**
 * @brief ostream output operator
 *
 * @details Free function outputs NameType to stream
 *          
 * @param in: ostream file object
 * @param in: NameType data item
 *
 * @note None
 */
ostream& operator << ( ostream &outStream, const NameType &name )
   {
    char tempName[ NameType::STD_NAME_LEN ];

    name.getName( tempName );

    outStream << tempName;

    return outStream;
   }


// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_NAMETYPE_CPP



