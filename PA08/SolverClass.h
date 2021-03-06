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
 
       static const char FILL_VALUE = 'O'; //"oh"
       static const int MAX_LETTERS = 25;
 
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
       void findInsertRowCol(int &row, int &col); //added
       void removeRectangle(  int &row,int &col,Rectangle &deleteRect,int &rectCount); //added
       bool findNextUnusedRectangle(Rectangle& unusedRect, int& index, int numRectangles); //added
 
   private:
 
       bool drawRectangle( int &row, int &col,int &rectCount); //added
       bool findSolutionHelper(Rectangle &checkRectangle, int &row, int &col, int &rectIndex); //added
 
       SimpleMatrix<char> board;
       SimpleVector<Rectangle> rectangleData;
       bool displayFlag;
   };
 
// Terminating precompiler directives  ////////////////////////////////////////
 
#endif          // #ifndef SOLVERCLASS_H