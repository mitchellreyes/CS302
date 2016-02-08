// Program Information ////////////////////////////////////////////////////////
/**
 * @file SolverClass.cpp
 *
 * @brief Implimintation file for class that attempts to locate smaller
 *        inside a larger container rectangle
 *
 * @author Mitchell Reyes

 * @worked with: Franky Solano, Garrett Marchese
 *
 * @details Specifies all member methods of the Solver class
 *
 * @version 1.00 (30 October 2015)
 *
 * @Note None
 */
 
// Precompiler directives /////////////////////////////////////////////////////
 
#ifndef SOLVERCLASS_CPP
#define SOLVERCLASS_CPP
 
// Header files ///////////////////////////////////////////////////////////////
 
#include "SolverClass.h"
 
 
using namespace std;
 
/**
 * @brief Default Constructor
 *
 * @details Constructs vector capacity to default and vector size to zero
 *          creates default size data array
 *          
 * @param None
 *
 * @note None
 */
SolverClass::SolverClass(){}              
 
/**
 * @brief Default Destructor
 *
 * @details Constructs vector capacity to default and vector size to zero
 *          creates default size data array
 *          
 * @param None
 *
 * @note None
 */
SolverClass::~SolverClass(){}                      
 
bool SolverClass::findSolution()
{
    int initialRow = 0, initialCol = 0, intialRectIndex = 0, index = 0;
    for(intialRectIndex  = 0; intialRectIndex <= rectangleData.getCapacity() - intialRectIndex - 1; intialRectIndex ++)
 	{
        Rectangle checkRect;
        rectangleData.getValueAt(intialRectIndex, checkRect);
        if(checkRect.isUsed() == false)
        {
            findSolutionHelper(checkRect, initialRow, initialCol, intialRectIndex);
 
        }
    }
   
    while(rectangleData[index].isUsed())
    {
            index++;                       
    }
    if (index == MAX_LETTERS)
    {
            return true;
    }
    return false;  
}
 
bool SolverClass::setContainerRectangle(int height, int width)      
{
	int rowIndex, colIndex;
    board.resize(height, width);
    if((height > 0) && (width > 0))
     {
                    setDisplayFlag(true);
                    //loop through matrix and fill with 'O'
                    for(rowIndex = 0; rowIndex < board.getNumRows(); rowIndex++)
                     {
                                    for(colIndex = 0; colIndex < board.getNumCols(); colIndex++)
                                            {
                                                    board[rowIndex][colIndex] = FILL_VALUE;
                                            }
                     }

             return true;
     }
    else
            {
                    setDisplayFlag(false);
                    return false;
            }
        }                      
 
bool SolverClass::addInsideRectangle
                                (
                                        int height,
                                        int width
                                )
        {  
         static char charID = 'A';
   static int currentRectangleIndex = 0;
 
     if (rectangleData.getSize() == MAX_LETTERS)
     {
            return false;
     }
 
     else
     {
        if ( charID == FILL_VALUE)
        {
                charID += 1;
        }
 
         Rectangle loadRect(height, width, charID);
                     rectangleData.setValueAt(currentRectangleIndex, loadRect);
         rectangleData[currentRectangleIndex].setUsedState(false);
         charID += 1;
         currentRectangleIndex += 1;
         return true;
     }
   
    return true;
        }      
 
void SolverClass::setDisplayFlag
                                (
                                        bool setFlag
                                )              
        {
                displayFlag = setFlag;
        }                      
 
void SolverClass::displayField()const
        {
                int rowIndex, colIndex;
                 for(rowIndex = 0; rowIndex < board.getNumRows(); rowIndex++)
                        {
                                 for(colIndex = 0; colIndex < board.getNumCols(); colIndex++)
                                        {
                                                cout << board[rowIndex][colIndex];
                                        }
                                        cout << endl;
                        }
        }                      
 
bool SolverClass::drawRectangle(int &row, int &col, int &rectCount)
        {
                 int rowIndex, colIndex;
                 int deleteRowIndex, deleteColIndex;
 
     Rectangle tempRect;
     rectangleData.getValueAt(rectCount, tempRect);
     char rectId = tempRect.getIDLetter();
      //draws rectangle
               
                   for(rowIndex = row; rowIndex < tempRect.getHeight() + row ; rowIndex++)
                                {
                                        for(colIndex = col; colIndex < tempRect.getWidth() + col; colIndex++)
                              {
                                if(board[rowIndex][colIndex] != FILL_VALUE || rowIndex > board.getNumRows() ||  colIndex > board.getNumCols())
                                 {
                                         for(deleteRowIndex = row ; deleteRowIndex < rowIndex; deleteRowIndex++)
                                                {
                                                 for(deleteColIndex = col; deleteColIndex < colIndex + tempRect.getWidth() ; deleteColIndex++)
                                                        {
                                                                                board[deleteRowIndex][deleteColIndex] = FILL_VALUE;
                                                        }
                                                }
                                         displayField();
                                         return false;
                                 }     
                                else
                                 {
                                        board[rowIndex][colIndex] = rectId;
 
                                 }
                               
                                    }
                                    cout << endl;
                                 }      
                                 cout << rectCount << endl;
                         tempRect.setUsedState(true);       
                         displayField();
                       
                return true; //temp stub
        }                              
 
void SolverClass::findInsertRowCol
                        (
                                int &row,
                                int &col
                        )
  {
        int rowIndex = 0, colIndex = 0;
          while((board[rowIndex][colIndex] != FILL_VALUE))     
                        {
                                rowIndex += 1;
                                if(rowIndex == board.getNumRows())
                                {
                                        colIndex += 1;
                                        rowIndex = 0;
                                }
                        }      
                        row = rowIndex;
                        col = colIndex;
 
  }
 
void SolverClass::removeRectangle
                                (
                                        int &row,
                                        int &col,
                                        Rectangle &deleteRect,
                                        int &rectCount
                                )
        {
                int rowIndex = 0, colIndex = 0;
    rectCount -= 1;
                rectangleData.incrementSize();
 
                        for(rowIndex = row; rowIndex < deleteRect.getHeight(); rowIndex++)
                        {
                                for(colIndex = col; colIndex < deleteRect.getWidth(); colIndex++)
                                {
                                        board[rowIndex][colIndex] = FILL_VALUE;
                                }
                }
        }                        
 
bool SolverClass::findNextUnusedRectangle
                                        (
                                                Rectangle& unusedRect,
                                                int& index,
                                                int numRectangles
                                        )
                {
 
                        if (index > numRectangles)
                                {
                                        return false;
                                }
 
                        while(index < numRectangles && rectangleData[index].isUsed())
                                {
                                        index++;
                                }
 
                                unusedRect = rectangleData[index];
                                return true;
        }                      
 
 
bool SolverClass::findSolutionHelper(Rectangle &checkRectangle,int &row,int &col, int &rectIndex)
{
        if(!findNextUnusedRectangle(checkRectangle, rectIndex, MAX_LETTERS))
        {
                return true;
        }
        findInsertRowCol(row, col);
         if(!drawRectangle(row, col, rectIndex) && !checkRectangle.isUsed()) //if you cant draw it
         {
                //rotate it
                checkRectangle.rotate();
                //set the dimensions of that rect to our vetor
                rectangleData.setValueAt(rectIndex, checkRectangle);
                checkRectangle.setUsedState(true);
                //set the used flag to true
                //then findSolution of that rectangle again with the new dimensions
                rectIndex += 1;
                findSolutionHelper(checkRectangle, row, col, rectIndex);
         }
 
        else if(!drawRectangle(row, col, rectIndex) && checkRectangle.isUsed())
        {
                //set the used flag back to false
                checkRectangle.setUsedState(false);
                rectIndex++;
                findSolutionHelper(checkRectangle, row, col, rectIndex);
                rectIndex--;
                removeRectangle(row, col, checkRectangle, rectIndex);
        }
 
        return false;
 
}			             
 
 
#endif          // #ifndef SOLVERCLASS_CPP