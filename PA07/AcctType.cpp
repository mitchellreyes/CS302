// Program Information ////////////////////////////////////////////////////////
/**
 * @file AcctType.cpp
 *
 * @brief Implementation file for AcctType class
 * 
 * @details Implements the constructor method of the AcctType class
 *
 * @author Michael Leverington
 *
 * @version 1.00 (03 October 2015)
 *
 * @Note Requires AcctType.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_ACCTTYPE_CPP
#define CLASS_ACCTTYPE_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "AcctType.h"

/**
 * @brief Default constructor
 *
 * @details Constructs empty AcctType
 *          
 * @param None
 *
 * @note None
 */
AcctType::AcctType
       ( 
        // no parameters
       )
     : nameData( NULL ), accountNumber( 0 ), accountType( NULL )
   {
    // assignment in initializers
   }

/**
 * @brief Initialization constructor
 *
 * @details Places name, account number, & account type data into object
 *          
 * @param in: New string name
 * @param in: New account number
 * @param in: New account type
 *
 * @note None
 */
AcctType::AcctType
       ( 
        const char *newName, // in: new c-string name
        int newAcctNum,     // in: new account number
        const char *newAcctType // in: new account type
       )
     : nameData( NULL )
   {
    setAccount( newName, newAcctNum, newAcctType );    
   }

/**
 * @brief Copy constructor
 *
 * @details Places account data into object
 *          
 * @param in: New AcctType object
 *
 * @note None
 */
AcctType::AcctType
       ( 
        const AcctType &newAcctObject    // in: copied account object
       )
     : nameData( NULL )
   {
    setAccount( newAcctObject.nameData, newAcctObject.accountNumber, 
                                               newAcctObject.accountType );    
   }

/**
 * @brief Destructor
 *
 * @details Desctructor for name and account type data
 *          
 * @param None
 *
 * @note None
 */
AcctType::~AcctType
       ( 
       )
   {
    if( nameData != NULL )
       {
        delete nameData;

        nameData = NULL;
       }

    if( accountType != NULL )
       {
        delete accountType;

        accountType = NULL;
       }
   }

/**
 * @brief Overloaded assignment operator
 *
 * @details Assign data to other AcctType
 *          
 * @param in: Assigned name
 *
 * @note None
 */
const AcctType &AcctType::operator =
       (
        const AcctType &rhAcct // in: assigned name
       )
   {
    if( this != &rhAcct )
       {
        setAccount( rhAcct.nameData, rhAcct.accountNumber, rhAcct.accountType );
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
bool AcctType::setAccount
       (
        const char *acctName,     // in: assigned account name
        int acctNum,              // in: assigned account number
        const char *acctType      // in: assigned account type
       )
   {
    int sourceIndex = 0, destIndex = 0;
    bool lastNameFound = false, firstNameFound = false;

    // make room for new name
    if( nameData != NULL )
       {
        delete nameData;
       }

    nameData = new char[ getStrLen( acctName ) + 1 ];

    while( acctName[ sourceIndex ] != NULL_CHAR 
                                          && acctName[ sourceIndex ] == SPACE )
       {
        sourceIndex++;
       }

    while( acctName[ sourceIndex ] != NULL_CHAR )
       {
        if( acctName[ sourceIndex ] == SPACE 
              && ( acctName[ sourceIndex + 1 ] == SPACE
                     || acctName[ sourceIndex + 1 ] == COMMA
                             || acctName[ sourceIndex + 1 ] == NULL_CHAR ) )
           {
            sourceIndex++;
           }

        else if( acctName[ sourceIndex ] == COMMA )
           {
            if( destIndex > 0 && !lastNameFound )
               {
                nameData[ destIndex ] = COMMA;
                destIndex++;

                if( acctName[ sourceIndex + 1 ] != SPACE )
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
            nameData[ destIndex ] = acctName[ sourceIndex ];

            destIndex++; sourceIndex++;

            nameData[ destIndex ] = NULL_CHAR;

            if( lastNameFound )
               {
                firstNameFound = true;
               }
           }
       }

    accountNumber = acctNum;

    accountType = new char[ getStrLen( acctType ) + 1 ];

    copyString( accountType, acctType );

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
void AcctType::getAccount
       (
        char *acctName,    // out: account name returned
        int &acctNum,      // out: account number returned
        char *acctType     // out: account type returned
       ) const
   {
    copyString( acctName, nameData );

    acctNum = accountNumber;

    copyString( acctType, accountType );
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
int AcctType::compareTo
       (
        const AcctType &rhAcct
       )
     const throw ( logic_error )
   {
    int diff, index = 0;

    if( this == &rhAcct )
       {
        return 0;
       }

    while( nameData[ index ] != NULL_CHAR 
            && rhAcct.nameData[ index ] != NULL_CHAR 
                && nameData[ index ] != COMMA 
                    && rhAcct.nameData[ index ] != COMMA )
       {
        diff = toUpper( nameData[ index ] ) 
                              - toUpper( rhAcct.nameData[ index ] );

        if( diff != 0 )
           {
            return diff;
           }

        index++;
       }

    if( nameData[ index] == NULL_CHAR || rhAcct.nameData[ index ] == NULL_CHAR )
       {
        throw logic_error( "Attempt to compare malformed name" );
       }

    if( nameData[ index ] == COMMA && rhAcct.nameData[ index ] != COMMA )
       {
        return -1;
       }

    if( nameData[ index ] != COMMA && rhAcct.nameData[ index ] == COMMA )
       {
        return 1;
       }

    while( nameData[ index ] != NULL_CHAR 
                                 && rhAcct.nameData[ index ] != NULL_CHAR )
       {
        diff = toUpper( nameData[ index ] ) 
                              - toUpper( rhAcct.nameData[ index ] );

        if( diff != 0 )
           {
            return diff;
           }

        index++;
       }

    return getStrLen( nameData ) - getStrLen( rhAcct.nameData );
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
void AcctType::copyString
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
int AcctType::getStrLen
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
char AcctType::toUpper
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

   // none

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_ACCTTYPE_CPP



