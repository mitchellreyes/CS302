// Program Information ////////////////////////////////////////////////////////
/**
 * @file SolverClass.h
 *
 * @brief Definition file for class that attempts to locate smaller
 *        inside a larger container rectangle
 * 
 * @author Michael Leverington
 * 
 * @details Specifies all member methods of the Solver class
 *
 * @version 1.00 (18 October 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef SOLVERCLASS_H
#define SOLVERCLASS_H

// Header files ///////////////////////////////////////////////////////////////

#include <stdexcept>
#include <iostream> 
#include "SimpleMatrix.h"
#include "SimpleMatrix.cpp"
#include "Rectangle.h" 


using namespace std;

// Class definition  //////////////////////////////////////////////////////////

class SolverClass
   {
    public:
       // constructor
       SolverClass();

       // destructor
       ~SolverClass( );

       // modifiers
       bool findSolution(); //aka placeRectangle
       bool setContainerRectangle( int height, int width );
       bool addInsideRectangle( int height, int width );
       void setDisplayFlag( bool setFlag );
       void displayField() const;

      // void removeRectangle(Rectangle& removedRectangle); //added
       //bool findOpenArea(Rectangle& rectObject);
   private:
    bool findSolHelp(SimpleVector<Rectangle> &hand, int index);
    bool findUnused(int index, SimpleVector<Rectangle> &hand);
    bool drawRectangle(int index);
    void remove(int index);
    bool findOpenArea(int index, int &topWidth, int &topHeight);



      SimpleMatrix<char> board;
      SimpleVector<Rectangle> rectangleData; 
      bool displayFlag;
   };

// Terminating precompiler directives  ////////////////////////////////////////

#endif    // #ifndef SOLVERCLASS_H
