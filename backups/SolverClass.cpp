// Program Information ////////////////////////////////////////////////////////
/**
 * @file SolverClass.cpp
 *
 * @brief Implimintation file for class that attempts to locate smaller
 *        inside a larger container rectangle
 * 
 * @author Garrett Marchese
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
	int index = 0;
	return findSolHelp(rectangleData, index);
}

bool SolverClass::findSolHelp(SimpleVector<Rectangle> &hand, int index)
{
	Rectangle insertRect;
	hand.getValueAt(index, insertRect);

	if(findUnused(index, rectangleData))
	{
		if(drawRectangle(index))
		{
			findSolHelp(rectangleData, index + 1);
		}
		remove(index);
		findSolHelp(rectangleData , index);
	}

	else if(index == hand.getSize())
	{
		return true;
	}
	else
	{
		cout << "NO SOLUTION" << endl;
		return false;
	}
	return true;
}

bool SolverClass::findUnused(int index, SimpleVector<Rectangle> &hand)
{
	Rectangle temp;
	int rectCount;
	for(rectCount = 0; rectCount < hand.getSize(); rectCount++)
	{
		hand.getValueAt(rectCount, temp);
		if(!temp.isUsed())
		{
			index = rectCount;
			return true;
		}
	}
	return false;
	
}
		
bool SolverClass::setContainerRectangle(int height, int width)	
{
	int rowIndex, colIndex;
    board.resize(height, width);
    //parameters meet constraints
	if((height > 0) && (width > 0))
	 {
	 	setDisplayFlag(true);
	 	//loop through matrix and fill with 'O'
	 	for(rowIndex = 0; rowIndex < board.getNumRows(); rowIndex++)
	 	{
	 		for(colIndex = 0; colIndex < board.getNumCols(); colIndex++)
	 		{
	 		 	board[rowIndex][colIndex] = 'O';
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

bool SolverClass::addInsideRectangle(int height, int width)
{  
	static char CHAR_ID = 'A';
	static int numRectangles = 0;
	if(rectangleData.getSize() == 25)
	{
		return false;
	}
	else
	{
		cout << CHAR_ID << endl;
		if(CHAR_ID == 'O')
		{
			CHAR_ID++;
		}
		Rectangle loader(height, width, CHAR_ID);
		rectangleData.setValueAt(numRectangles, loader);
		numRectangles++;
		CHAR_ID++;
		return true;
	}
	
	/*
	int rowIndex = 0, colIndex = 0;
	static int currentNumRectangles = 0;
   	
	Rectangle newRectangle(height, width, CHAR_ID++);

   	newRectangle.setUsedState(true);
	rectangleData.setValueAt(currentNumRectangles, newRectangle); //initially sets newRectangle data at first element of vector
	//case 1: current postion is a fill val, able to insert
	findInsertRowCol(rowIndex, colIndex, rectangleData, currentNumRectangles);
	drawRectangle(rowIndex, colIndex, rectangleData, currentNumRectangles);
	rectangleData.decrementSize();
	//currentNumRectangles += 1;
	
	return true;
	*/
}	

void SolverClass::setDisplayFlag(bool setFlag)		
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

bool SolverClass::drawRectangle(int index)
{
	Rectangle checker;
	rectangleData.getValueAt(index, checker);
	int row = 0, col = 0;
	int rowIndex, colIndex;
	if(findOpenArea(index, row, col))
	{
		cout << "row:" << row << "col:" << col << endl;
		for(rowIndex = row; rowIndex < checker.getHeight() + row; rowIndex++)
		{
			for(colIndex = col; colIndex < checker.getWidth() + col; colIndex++)
			{
				board[rowIndex][colIndex] = checker.getIDLetter();
			}
		}
		checker.setUsedState(true);
		return true;
	}
	return false;
	/*
	int rowIndex = 0, colIndex = 0;
	Rectangle tempRect;
	newRectangle.getValueAt(rectCount++, tempRect);
	char rectId = tempRect.getIDLetter();
    //draws rectangle
	for(rowIndex = row; rowIndex < tempRect.getHeight() + row; rowIndex++)
	{
		for(colIndex = col; colIndex < tempRect.getWidth() + col; colIndex++)
		{
		 	if(board[rowIndex][colIndex] != 'O')
		 	{
		 		for(int deleteRowIndex = row; deleteRowIndex < rowIndex; deleteRowIndex++)
		 		{
		 			for(int deleteRowCol = col; deleteRowCol <= colIndex; deleteRowCol++)
		 			{
		 				board[deleteRowIndex][deleteRowCol] = 'O';
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
	tempRect.setUsedState(true);
	displayField(); //shows each step of the process
	return true;
	*/
}				

void SolverClass::remove(int index)
{
	Rectangle temp;
	rectangleData.getValueAt(index, temp);
	for(int i = 0; i < board.getNumRows(); i++)
	{
		for(int j = 0; j < board.getNumRows(); j++)
		{
			if(board[i][j] == temp.getIDLetter())
			{
				board[i][j] = 'O';
			} 
		}
	}
	temp.setUsedState(false);
	/*
	int rowIndex, colIndex;
	rectangleData.incrementSize();
	for(rowIndex = row; rowIndex < output.getHeight() + row; rowIndex++)
	{
		for(colIndex = col; colIndex < output.getWidth() + col; colIndex++)
		{
			board[rowIndex][colIndex] = 'O';
		}
		cout << endl;
	}
	output.setUsedState(false);
	*/
}

bool SolverClass::findOpenArea(int index, int &topWidth, int &topHeight)
{
	Rectangle checker;
	rectangleData.getValueAt(index, checker);
	int start = 0;
	int oHeight = 0, oWidth = 0, rowStart = 0, colStart = 0;
	while(board[topHeight][topWidth] != 'O')
	{
		if(topHeight == board.getNumRows())
		{
			topHeight = 0;
			topWidth++;
		}
		else
		{
			topHeight++;
		}
	}
	rowStart = topHeight;
	colStart = topWidth;
	while((board[topHeight][topWidth] == 'O' && topHeight != board.getNumRows()) || (board[topHeight][topWidth] != 'O'))
	{
		oHeight++;
		topHeight++;
	}
	while((board[topHeight][topWidth] == 'O' && topWidth != board.getNumCols()) || (board[topHeight][topWidth] != 'O'))
	{
		oWidth++;
		topWidth++;
	}
	if(topHeight >= checker.getHeight() && topWidth >= checker.getWidth())
	{
		topWidth = colStart;
		topHeight = rowStart;
		return true;
	}
	else if(!checker.isUsed())
	{
		checker.rotate();
		checker.setUsedState(true);
		rectangleData.setValueAt(index, checker);
		findOpenArea(index, start, start);
	}
	else
	{
		checker.setUsedState(false);
		return false;
	}
	return true;
	/*
  	row = col = 0;
	while((board[row][col] != 'O'))	
	{
		row += 1;
		if(row == board.getNumRows())
		{
			col += 1;
			row = 0;
		}
	}
	*/
}



#endif		// #ifndef SOLVERCLASS_CPP
