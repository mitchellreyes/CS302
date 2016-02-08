// Program Information ////////////////////////////////////////////////////////
/**
 * @file Rectangle.cpp
 *
 * @brief Implementation file for Rectangle class
 * 
 * @author Michael Leverington
 * 
 * @details Implements all member methods of the Rectangle class
 *
 * @version 1.00 (18 October 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_RECTANGLE_CPP
#define CLASS_RECTANGLE_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "Rectangle.h"
#include <stdexcept>

using namespace std;

// Class implementation  //////////////////////////////////////////////////////

/**
 * @brief Default constructor
 *
 * @details Constructs empty rectangle with unused state
 *          
 * @param None
 *
 * @note None
 */
Rectangle::Rectangle
       (
        // data loaded via initializers
       )
     : rectWidth( 0 ), rectHeight( 0 ), rectIdLetter( 'O' ), 
       rectUsedState( false )
   {
    // data loaded via initializers
   }

/**
 * @brief Initialization constructor
 *
 * @details Constructs rectangle with given conditions
 *          
 * @param in: width of rectangle
 * @param in: height of rectangle
 * @param in: ID letter of rectangle
 *
 * @note None
 */
Rectangle::Rectangle 
       ( 
        int height,    // in: height of rectangle
        int width,     // in: width of rectangle
        char IdLetter  // in: ID letter of rectangle
       )
     : rectWidth( width ), rectHeight( height ), rectIdLetter( IdLetter ),
       rectUsedState( false )
   {
    // data loaded via initializers
   }

/**
 * @brief Copy constructor
 *
 * @details Constructs rectangle from copy of other rectangle
 *          
 * @param in: other rectangle object
 *
 * @note None
 */
Rectangle::Rectangle
       ( 
        const Rectangle &copiedRect // in: copy of rectangle object
       )
     : rectWidth( copiedRect.rectWidth ), rectHeight( copiedRect.rectHeight ),
       rectIdLetter( copiedRect.rectIdLetter ), 
       rectUsedState( copiedRect.rectUsedState )
   {
    // data loaded via initializers
   }

/**
 * @brief Destructor
 *
 * @details No dynamic quantities to resolve
 *          
 * @param in: None
 *
 * @note None
 */
Rectangle::~Rectangle
       (
        // no parameters
       )
   {
    // no action in destructor
   }


/**
 * @brief Overloaded assignment operator
 *
 * @details assigns rectangle object to this
 *          
 * @param in: assigned rectangle object
 *
 * @note None
 */
const Rectangle &Rectangle::operator = 
       ( 
        const Rectangle &rhRectangle    // in: assigned rectangle
       )
   {
    // to verify shallow copy
    rectWidth = rhRectangle.rectWidth;
    rectHeight = rhRectangle.rectHeight;
    rectIdLetter = rhRectangle.rectIdLetter;
    rectUsedState = rhRectangle.rectUsedState;

    return *this;
   }

/**
 * @brief Rectangle rotate operation
 *
 * @details Rotates rectangle, exchanges height and width
 *          
 * @param in: None
 *
 * @note None
 */
void Rectangle::rotate
       (
        // no parameters
       )
   {
    int tempHeight = rectHeight;

    rectHeight = rectWidth;
    rectWidth = tempHeight;
   }

/**
 * @brief Width accessor
 *
 * @details Returns rectangle width
 *          
 * @param in: None
 *
 * @note None
 */
int Rectangle::getWidth
       (
        // no parameters
       ) const
   {
    return rectWidth;
   }

/**
 * @brief Height accessor
 *
 * @details Returns rectangle height
 *          
 * @param in: None
 *
 * @note None
 */
int Rectangle::getHeight
       (
        // no parameters
       ) const
   {
    return rectHeight;
   }

/**
 * @brief Rectangle ID letter accessor
 *
 * @details Returns rectangle ID letter
 *          
 * @param in: None
 *
 * @note None
 */
char Rectangle::getIDLetter
       (
        // no parameters
       ) const
   {
    return rectIdLetter;
   }

/**
 * @brief Used state accessor
 *
 * @details Returns rectangle used state
 *          
 * @param in: None
 *
 * @note None
 */
bool Rectangle::isUsed
       (
        // no parameters
       ) const
   {
    return rectUsedState;
   }

/**
 * @brief Width modifier
 *
 * @details Sets rectangle width
 *          
 * @param in: new rectangle width
 *
 * @note None
 */
void Rectangle::setWidth
       (
        int newWidth   // in: new rectangle width
       )
   {
    rectWidth = newWidth;
   }

/**
 * @brief Height modifier
 *
 * @details Sets rectangle height
 *          
 * @param in: new rectangle height
 *
 * @note None
 */
void Rectangle::setHeight
       (
        int newHeight   // in: new rectangle height
       )
   {
    rectHeight = newHeight;
   }

/**
 * @brief ID letter modifier
 *
 * @details Sets rectangle ID letter
 *          
 * @param in: new rectangle Id letter
 *
 * @note None
 */
void Rectangle::setIDLetter
       (
        char newIdLetter   // in: new rectangle ID letter
       )
   {
    rectIdLetter = newIdLetter;
   }

/**
 * @brief Used state modifier
 *
 * @details Sets rectangle used state
 *          
 * @param in: new rectangle used state
 *
 * @note None
 */
void Rectangle::setUsedState
       (
        bool newUsedState   // in: new rectangle used state
       )
   {
    rectUsedState = newUsedState;
   }

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_RECTANGLE_CPP


