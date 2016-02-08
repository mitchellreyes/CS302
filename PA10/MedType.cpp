// Program Information ////////////////////////////////////////////////////////
/**
 * @file MedType.cpp
 *
 * @brief Implementation file for MedType class
 * 
 * @details Implements member actions of the MedType class
 *
 * @author Michael Leverington
 *
 * @version 1.00 (30 October 2015)
 *
 * @Note Requires MedType.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_MEDTYPE_CPP
#define CLASS_MEDTYPE_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "MedType.h"

/**
 * @brief Default constructor
 *
 * @details Constructs empty MedType
 *          
 * @param None
 *
 * @note None
 */
MedType::MedType
       ( 
        // no parameters
       )
     : name( NULL ), medCodeNum( NULL ), gender( 'O' )
   {
    // assignment in initializers
   }

/**
 * @brief Initialization constructor
 *
 * @details Places name, medical code number, & gender data into object
 *          
 * @param in: New patient name
 * @param in: New medical code number
 * @param in: New gender
 *
 * @note None
 */
MedType::MedType
       ( 
        const char *patientName, // in: new c-string name
        const char *medCodeNum,  // in: new c-string code number
        char patientGender       // in: new char gender
       )
     : name( NULL ), medCodeNum( NULL )
   {
    setAccount( patientName, medCodeNum, patientGender );    
   }

/**
 * @brief Copy constructor
 *
 * @details Places account data into object
 *          
 * @param in: New MedType object
 *
 * @note None
 */
MedType::MedType
       ( 
        const MedType &newAcctObject    // in: copied account object
       )
     : name( NULL ), medCodeNum( NULL )
   {
    setAccount( newAcctObject.name, newAcctObject.medCodeNum, 
                                                       newAcctObject.gender );    
   }

/**
 * @brief Destructor
 *
 * @details Desctructor for name and medical data
 *          
 * @param None
 *
 * @note None
 */
MedType::~MedType
       ( 
        // no parameters
       )
   {
    if( name != NULL )
       {
        delete name;

        name = NULL;
       }

    if( medCodeNum != NULL )
       {
        delete medCodeNum;

        medCodeNum = NULL;
       }
   }

/**
 * @brief Overloaded assignment operator
 *
 * @details Assign data to other MedType
 *          
 * @param in: Assigned name
 *
 * @note None
 */
const MedType &MedType::operator =
       (
        const MedType &rhMed // in: assigned medical data
       )
   {
    if( this != &rhMed )
       {
        setAccount( rhMed.name, rhMed.medCodeNum, rhMed.gender );
       }

    return *this;
   }

/**
 * @brief Sets account data
 *
 * @details Assigns and qualifies name, assigns account number, 
 *          assigns account type
 *          
 * @param in: Account object
 *
 * @note Attempts to standardize name (LastName, FirstName)
 */
bool MedType::setAccount
       (
        const char *patientName,     // in: assigned patient name
        const char *medicalCodeNum,  // in: assigned medical code number
        char patientGender           // in: assigned gender
       )
   {
    int sourceIndex = 0, destIndex = 0;
    bool lastNameFound = false, firstNameFound = false;

    // make room for new name
    if( name != NULL )
       {
        delete name;
       }

    name = new char[ getStrLen( patientName ) + 1 ];

    while( patientName[ sourceIndex ] != NULL_CHAR 
                                       && patientName[ sourceIndex ] == SPACE )
       {
        sourceIndex++;
       }

    while( patientName[ sourceIndex ] != NULL_CHAR )
       {
        if( patientName[ sourceIndex ] == SPACE 
              && ( patientName[ sourceIndex + 1 ] == SPACE
                     || patientName[ sourceIndex + 1 ] == COMMA
                             || patientName[ sourceIndex + 1 ] == NULL_CHAR ) )
           {
            sourceIndex++;
           }

        else if( patientName[ sourceIndex ] == COMMA )
           {
            if( destIndex > 0 && !lastNameFound )
               {
                name[ destIndex ] = COMMA;
                destIndex++;

                if( patientName[ sourceIndex + 1 ] != SPACE )
                   {
                    name[ destIndex ] = SPACE;
                    destIndex++;
                   }

                lastNameFound = true;
               }
        
            sourceIndex++;
           }

        else
           {
            name[ destIndex ] = patientName[ sourceIndex ];

            destIndex++; sourceIndex++;

            name[ destIndex ] = NULL_CHAR;

            if( lastNameFound )
               {
                firstNameFound = true;
               }
           }
       }

    if( medCodeNum != NULL )
       {
        delete medCodeNum;
       }

    medCodeNum = new char[ getStrLen( medicalCodeNum ) + 1 ];

    copyString( medCodeNum, medicalCodeNum );

    gender = patientGender;

    return lastNameFound && firstNameFound;
   }

/**
 * @brief Gets information from data type
 *
 * @details Returns data to calling method
 *          
 * @param out: patient name
 * @param out: medical code number
 * @param out: patient gender
 *
 * @note None
 */
void MedType::getAccount
       (
        char *patientName,    // out: patient name returned
        char *medicalCodeNum, // out: medical code number returned
        char &patientGender    // out: gender returned
       ) const
   {
    copyString( patientName, name );

    copyString( medicalCodeNum, medCodeNum );

    patientGender = gender;
   }

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
int MedType::compareTo
       (
        const MedType &rhMed
       )
     const throw ( logic_error )
   {
    int diff, index = 0;

    if( this == &rhMed )
       {
        return 0;
       }

    while( name[ index ] != NULL_CHAR 
            && rhMed.name[ index ] != NULL_CHAR 
                && name[ index ] != COMMA 
                    && rhMed.name[ index ] != COMMA )
       {
        diff = toUpper( name[ index ] ) 
                              - toUpper( rhMed.name[ index ] );

        if( diff != 0 )
           {
            return diff;
           }

        index++;
       }

    if( name[ index] == NULL_CHAR || rhMed.name[ index ] == NULL_CHAR )
       {
        throw logic_error( "Attempt to compare malformed name" );
       }

    if( name[ index ] == COMMA && rhMed.name[ index ] != COMMA )
       {
        return -1;
       }

    if( name[ index ] != COMMA && rhMed.name[ index ] == COMMA )
       {
        return 1;
       }

    while( name[ index ] != NULL_CHAR 
                                 && rhMed.name[ index ] != NULL_CHAR )
       {
        diff = toUpper( name[ index ] ) 
                              - toUpper( rhMed.name[ index ] );

        if( diff != 0 )
           {
            return diff;
           }

        index++;
       }

    return getStrLen( name ) - getStrLen( rhMed.name );
   }

/**
 * @brief Creates hash value, given number of letters in name to use,
 *        and number of bins in hash table
 *
 * @details Sums first given number of letters in name,
 *          then implements modulo math with hash table size
 *          
 * @param out: returned name
 *
 * @note None
 */
int MedType::hash
       (
        int numLetters,
        int hashTableLength
       )
   {
    int index = 0, sum = 0;

    while( name[ index ] != NULL_CHAR && index < numLetters )
       {
        sum += int( name[ index ] );

        index++;
       }

    return sum % hashTableLength;
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
void MedType::copyString
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
int MedType::getStrLen
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
char MedType::toUpper
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

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_MEDTYPE_CPP



