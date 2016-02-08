// Program Information ////////////////////////////////////////////////////////
/**
 * @file SelSorter.cpp
 * 
 * @brief Implementation file for SelSorter using insertion sort,
 *        derived from SorterClass
 * 
 * @author Michael Leverington
 *
 * @details Implements virtual member methods of the SelSorter
 *
 * @version 1.00 (11 September 2015)
 *
 * @Note Requires SelSorter.h, SorterClass.cpp, SimpleVector.cpp,
 * 
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef SELSORTER_CPP
#define SELSORTER_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "SelSorter.h"
#include "SorterClass.cpp"
#include "SimpleVector.cpp"

/**
 * @brief Default constructor
 *
 * @details Constructs sorter class with default vector class initialization
 *          
 * @param None
 *
 * @note None
 */
SelSorter::SelSorter 
     (
      // no parameters
     )
       : SorterClass<DateType>()
   {
    // construct parent
   }

/**
 * @brief Initialization constructor
 *
 * @details Constructs sorter class with specified vector class initialization
 *          
 * @param in: initial capacity
 *
 * @note None
 */
SelSorter::SelSorter 
     (
      int initialCapacity // in: initial capacity for vector
     )
       : SorterClass<DateType>( initialCapacity )
   {
    // construct parent
   }

/**
 * @brief Copy constructor
 *
 * @details Constructs sorter class with copied object
 *          
 * @param in: other SorterClass object
 *
 * @note None
 */
SelSorter::SelSorter
     (
      const SorterClass<DateType> &copiedSorter // in: other sorter class object
     )
       : SorterClass<DateType>( copiedSorter )
   {
    // construct parent
   }

/**
 * @brief Class destructor
 *
 * @details Destructs test sorter class
 *          
 * @param in: None
 *
 * @note Implements SorterClass -> SimpleVector destructor
 */
SelSorter::~SelSorter
     (
      // no parameters
     )
   {
    // parent class (SorterClass) destructs
   }

/**
 * @brief Object comparison, necessary for sorting
 *
 * @details Compares objects mathematically, 
 *          returns value < 0 if lhO < rhO
 *          returns  0 if lhO = rhO
 *          returns value > 0 if lhO > rhO
 *          
 * @param in: Left hand object, right hand object
 *
 * @note Simple mathematical base operation; assumed to be overridden
 */
int SelSorter::compareTo 
     (
      const DateType &lhObject, // in: leftHandObject
      const DateType &rhObject  // in: rightHandObject
     )
   {
    int diff = makeYear( lhObject.date ) - makeYear( rhObject.date );

    if( diff != 0 )
       {
        return diff;
       }

    diff = makeMonth( lhObject.date ) - makeMonth( rhObject.date );

    if( diff != 0 )
       {
        return diff;
       }

    return makeDate( lhObject.date ) - makeDate( rhObject.date );
   }

/**
 * @brief Sorting operation
 *
 * @details Virtual sort method that is overridden
 *          to use various sorting strategies
 *          
 * @param in: None
 *
 * @note Derived methods use specific strategy to sort objects
 * @note Sets sort success flag to true at start;
 *       supporting operations used to create dates, months, years
 *       will set the flag to false if there is an incorrect date;
 *       method returns success flag
 */
bool SelSorter::sort
       (
        // no parameters
       )
   {
    int lowestIndex, innerIndex, outerIndex = 0;
    DateType innerDate, outerDate, lowestDate;

    sortSuccess = true;

    while( outerIndex < getSize() - 1 && sortSuccess )
       {
        lowestIndex = outerIndex;
        innerIndex = outerIndex + 1;

        while( innerIndex < getSize() && sortSuccess )
           {
            getValueAt( innerIndex, innerDate );
            getValueAt( lowestIndex, lowestDate );

            if( compareTo( innerDate, lowestDate ) < 0 )
               {
                lowestIndex = innerIndex;
               }

            innerIndex++;
           }

        swap( outerIndex, lowestIndex );

        outerIndex++;
       }

    return sortSuccess;
   }

/**
 * @brief Swaps date types
 *
 * @details Swaps date types for use with some sorting algorithms
 *          
 * @param in: None
 *
 * @note Requires access of vector data, swapping of strings,
 *       and resetting vector data at locations
 */
void SelSorter::swap
       ( 
        int one,   // in: index of one of two to be swapped
        int other  // in: index other of two to be swapped
       )
   {
    DateType temp, oneDate, otherDate;

    getValueAt( one, oneDate );
    getValueAt( other, otherDate );

    setValueAt( other, oneDate );
    setValueAt( one, otherDate );
   }

/**
 * @brief Makes an integer date
 *
 * @details Creates integer date from the text at the first part of the string
 *          
 * @param in: String data
 *
 * @note Checks for legitimate dates, sets sort success flag to false
 *       if date not possible
 */
int SelSorter::makeDate
       ( 
        const char *str  // in: date string
       )
   {
    int startIndex = 0;
    int maxDate, date = strToInt( startIndex, str );

    switch( makeMonth( str ) )
       {
        case 4: case 6: case 9: case 11:
           maxDate = 30;
           break;

        case 2:
           if( isLeapYear( makeYear( str ) ) )
              {
               maxDate = 29;
              }
           else
              {
               maxDate = 28;
              }
           break;

        default:
           maxDate = 31;
           break;
       }

    if( date > 0 && date <= maxDate )
       {
        return date;
       }

    sortSuccess = false;

    return 0;
   }

/**
 * @brief Makes an integer month
 *
 * @details Creates integer month from the text in the middle of the string
 *          
 * @param in: String data
 *
 * @note Checks for legitimate months, sets sort success flag to false
 *       if date not possible
 */
int SelSorter::makeMonth
       ( 
        const char *str  // in: date string
       )
   {
    int startIndex = 0;

    startIndex = findSpace( startIndex, str ) + 1;

    if( compMonth( str, startIndex, "APR" ) )
       {
        return 4;
       }

    else if( compMonth( str, startIndex, "AUG" ) )
       {
        return 8;
       }

    else if( compMonth( str, startIndex, "DEC" ) )
       {
        return 12;
       }

    else if( compMonth( str, startIndex, "FEB" ) )
       {
        return 2;
       }

    else if( compMonth( str, startIndex, "MAR" ) )
       {
        return 3;
       }

    else if( compMonth( str, startIndex, "MAY" ) )
       {
        return 5;
       }

    else if( compMonth( str, startIndex, "JAN" ) )
       {
        return 1;
       }

    else if( compMonth( str, startIndex, "JUL" ) )
       {
        return 7;
       }

    else if( compMonth( str, startIndex, "JUN" ) )
       {
        return 6;
       }

    else if( compMonth( str, startIndex, "NOV" ) )
       {
        return 11;
       }

    else if( compMonth( str, startIndex, "OCT" ) )
       {
        return 10;
       }

    else if( compMonth( str, startIndex, "SEP" ) )
       {
        return 9;
       }

    sortSuccess = false;

    return 0;
   }

/**
 * @brief Makes an integer year
 *
 * @details Creates integer year from the text at the end of the string
 *          
 * @param in: String data
 *
 * @note Checks for legitimate years, sets sort success flag to false
 *       if year is below zero or above arbitrarily set limit
 *       in .h file
 */
int SelSorter::makeYear
       ( 
        const char *str  // in: date string 
       )
   {
    int startIndex = 0;
    int year;

    startIndex = findSpace( startIndex, str ) + 1;
    startIndex = findSpace( startIndex, str ) + 1;

    year = strToInt( startIndex, str );

    if( year < 0 || year > MAX_YEAR_ALLOWED )
       {
        sortSuccess = false;

        return 0;
       }

    return year;
   }

/**
 * @brief Converts substring segment to integer
 *
 * @details Given index starting location, acquires all contiquous digits,
 *          converts them to an integer value
 *          
 * @param in: starting index
 * @param in: String data
 *
 * @note None
 */
int SelSorter::strToInt
       ( 
        int startIndex,  // in: start index through string
        const char *str  // in: string
       )
   {
    int val, leftShiftFactor = 10;

    val = int( str[ startIndex ] - '0' );

    startIndex++;

    while( isDigit( str[ startIndex ] ) )
       {
        val *= leftShiftFactor;

        val += int( str[ startIndex ] - '0' );

        startIndex++;
       }

    return val;
   }

/**
 * @brief Finds the next space in a string
 *
 * @details Given a starting index, finds the next space in a string
 *          in order to find the next date component
 *          
 * @param in: starting index
 * @param in: String data
 *
 * @note None
 */
int SelSorter::findSpace
       ( 
        int startIndex,   // in: start index through string
        const char *str   // in: string
       )
   {
    while( str[ startIndex ] != SPACE && str[ startIndex ] != NULL_CHAR )
       {
        startIndex++;      
       }

    return startIndex;
   }

/**
 * @brief Compares a test name to a specified month name
 *
 * @details The first three letters of a test string are compared to
 *          a given three letter month name
 *          
 * @param in: test-month string
 * @param in: starting index
 * @param in: given month string
 *
 * @note Sets all letters to upper case, and is tested against
 *       an upper case three-letter month
 * @note Month name is allowed to be longer, but first three letters
 *       must be correct
 */
bool SelSorter::compMonth
       ( 
        const char *testStr,  // in: string tested for month
        int startIndex,  // in: index to start month test
        const char *testMonth // in: month string to compare to
       )
   {
    int endIndex = startIndex + MONTH_NAME_WIDTH;
    int testIndex = 0;

    while( startIndex < endIndex )
       {
        if( toUpper( testStr[ startIndex ] ) != testMonth[ testIndex ] )
           {
            return false;
           }

        startIndex++; testIndex++;
       }

    return true;
   }

/**
 * @brief Sets lower case to upper case letter
 *
 * @details Only operates on lower case letters; all other letters
 *          are returned unchanged
 *          
 * @param in: test character/letter
 *
 * @note None
 */
char SelSorter::toUpper
       ( 
        char testChar
       )
   {
    if( testChar >= 'a' && testChar <= 'z' )
       {
        testChar = int( testChar - 'a' + 'A' );
       }

    return testChar;
   }

/**
 * @brief Verifies character as digit
 *
 * @details Checks for character digit between '0' and '9'
 *          
 * @param in: test character/letter
 *
 * @note None
 */
bool SelSorter::isDigit
       ( 
        char testDigit  // in: test character/digit
       )
   {
    return ( testDigit >= '0' && testDigit <= '9' );
   }

/**
 * @brief Verifies leap year
 *
 * @details Checks for leap year using standard algorithm
 *          
 * @param in: year value
 *
 * @note None
 */
bool SelSorter::isLeapYear( int year )
   {
    return ( year % 4 == 0 && year % 100 != 0 ) || ( year % 400 == 0 );
   }


#endif // ifndef SELSORTER_CPP








