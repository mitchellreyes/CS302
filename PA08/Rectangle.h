// Program Information ////////////////////////////////////////////////////////
/**
 * @file Rectangle.h
 *
 * @brief Definition file for Rectangle class
 * 
 * @author Michael Leverington
 * 
 * @details Specifies all member methods of the Rectangle class
 *
 * @version 1.00 (18 October 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_RECTANGLE_H
#define CLASS_RECTANGLE_H

// Header files ///////////////////////////////////////////////////////////////

#include <stdexcept>

using namespace std;

// Class definition  //////////////////////////////////////////////////////////

class Rectangle
   {

    public:

       // constructors
       Rectangle();
       Rectangle ( int height, int width, char IdLetter );
       Rectangle( const Rectangle &copiedRect ); 

       // destructor
       ~Rectangle( );

       // assignment
       const Rectangle &operator = ( const Rectangle &rhRectangle );

       // mutator
       void rotate();

       // accessors
       int getWidth() const;
       int getHeight() const;
       char getIDLetter() const;
       bool isUsed() const;

       // modifiers
       void setWidth( int newWidth );
       void setHeight( int newHeight );
       void setIDLetter( char newIdLetter );
       void setUsedState( bool newUsedState );

    private:

       int rectWidth, rectHeight;
       char rectIdLetter;
       bool rectUsedState;
   };

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_RECTANGLE_H


