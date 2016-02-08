// Program Information ////////////////////////////////////////////////////////
/**
 * @file AcctType.h
 *
 * @brief Definition file for AcctType class
 * 
 * @details Specifies all data of the AcctType class,
 *          along with the constructor,
 *          AcctType class is entered and stored as a string
 *
 * @author Michael Leverington
 *
 * @version 1.00 (03 October 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_ACCTTYPE_H
#define CLASS_ACCTTYPE_H

// Header files ///////////////////////////////////////////////////////////////

#include <ostream>
#include <stdexcept>

using namespace std;

// Class constants ////////////////////////////////////////////////////////////

   // None

// Class definition ///////////////////////////////////////////////////////////

class AcctType
   {
    public:

       static const char NULL_CHAR = '\0';
       static const char COMMA = ',';
       static const char SPACE = ' ';
       static const int STD_NAME_LEN = 100;

       AcctType();
       AcctType( const char *newNameData, int newAcctNum, 
                                                   const char *newAcctType );
       AcctType( const AcctType &newAcctObject );

       ~AcctType();

       const AcctType &operator = ( const AcctType &rhAcct );

       bool setAccount( const char *acctName, int acctNum, 
                                                     const char *acctType );
       void getAccount( char *acctName, int &acctNum, char *acctType ) const;

       int compareTo( const AcctType &rhAcct ) const throw ( logic_error );

    private:

       void copyString( char *destination, const char *source ) const;
       int getStrLen( const char *str ) const;
       char toUpper( char letter ) const;

       char *nameData;
       int accountNumber;
       char *accountType;
   };

// Free function output operator  /////////////////////////////////////////////

ostream& operator << ( ostream& outStream, const AcctType &name );

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_ACCTTYPE_H



