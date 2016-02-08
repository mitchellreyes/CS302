/**
* @file PriorityQueue.cpp
*
* @brief implementation file for Priority Queue class
*
* @details Definitions of all members
* to be used in the Priority Queue class
*
* @author Mitchell Reyes
*
* @version 1.00 (16 September 2015)
*
*
* @note Depends on Priority header file
*/



#include "PriorityQueue.h"
#include <iostream>

/**
* @brief Implementation of Priority queue default constructor
*
* @details Default constructor for PriorityQueue class
*
* @param None
*
* @note head, rear initialized
*/
template <class DataType>
PriorityQueue<DataType>::PriorityQueue()
{
	head = -1;
	rear = -1;
}

/**
* @brief Implementation of PriortiyQueue copy constructor
*
* @details Copy constructor for PriorityQueue class
*
* @param const PriorityQueue
*
* @note Queue copied to another Queue
*/
template <class DataType>
PriorityQueue<DataType>::PriorityQueue(const DataType &PriorityQueue)
{
	vector1 = PriorityQueue.vector1;
}

/**
* @brief Implementation of destructor
*
* @details destructor for PriorityQueue class
*
* @param None
*
* @note head, rear set to default value, vector is emptied
*/
template <class DataType>
PriorityQueue<DataType>::~PriorityQueue()
{
	if(!isEmpty())
	{
		while(vector1.getCapacity() != 0)
		{
			DataType garb;
			dequeue(garb);
		}
	}
	head = -1;
	rear = -1;
}

/**
* @brief Implementation of dequeue
*
* @details dequeue for PriorityQueue class
*
* @param reference output value
*
* @note none
*/
template <class DataType>
bool PriorityQueue<DataType>::dequeue(DataType &outVal)
{
	//float sizeRatio = (vector1.getSize() / vector1.getCapacity());
	//float compSize = (1.0/4.0);
	if(isEmpty())
	{
		return false;
	}
	//vector1.decrementSize();
	//decrease size if 1/4 smaller after dequeue
	outVal = vector1[head];
	if(vector1.getSize() > 0 && vector1.getSize() == vector1.getCapacity()/4)
	{
		vector1.shrink(vector1.getCapacity() / 2);
	}
	if(head == rear)
	{
		head = rear = -1;
		vector1.decrementSize();
		return true;
	}
	int index;
	for(index = 0; index < vector1.getSize()-1; index++)
	{
		vector1[index] = vector1[index + 1];
	}
	vector1.decrementSize();
	rear -= 1;
	return true;
}

/**
* @brief Implementation of empty
*
* @details empty for class
*
* @param None
*
* @note None
*/
template <class DataType>
bool PriorityQueue<DataType>::isEmpty()
{
	if(head == -1 && rear == -1)
	{
		return true;
	}
	return false;
}

/**
* @brief Implementation of class enqueue fucntion
*
* @details enqueue for LinkedList class
*
* @param Priority, newProcess
*
* @note checks priority agaisnt others, then places it at that index 
*/
template <class DataType>
bool PriorityQueue<DataType>::enqueue(int priority, char* newProcess)
{
	DataType object(priority, newProcess);

	if(isEmpty())
	{
		head += 1;
		rear += 1;
		vector1[head] = object;
		vector1.incrementSize();
		return true;
	}
	
	int index;
	int shifting;
	DataType hold;
	hold = vector1[rear];
	if(head == rear)//if theres only 1 element in the vector
	{
		if(priority >= vector1[head].priority)
		{
			rear += 1;
			vector1[rear] = object;
			vector1.incrementSize();
			return true;
		}
		else
		{
			vector1[head] = object;
			vector1[rear+1] = hold;
			vector1.incrementSize();
			rear += 1;
			return true;
		}
	}
	else
	{
		//resizing if it doesnt fit
		if(vector1.getSize() > 0 && vector1.getSize()+1 == vector1.getCapacity())
		{
			vector1.grow(vector1.getCapacity());
		}	

		for(index = 0; index < rear+1; index++)
		{
			if(priority < vector1[index].priority)
			{
				for(shifting = rear; shifting > index; shifting--)
				{
					vector1[shifting] = vector1[shifting-1];
				}
				vector1[index] = object;
				vector1[rear+1] = hold;
				vector1.incrementSize();
				rear += 1;
				return true;
			}
		}
		vector1[rear+1] = object;
		vector1.incrementSize();
		rear += 1;
		return true;
	}
	
	
}
/**
* @brief Implementation of class peek at front
*
* @details peekAtFront for class
*
* @param value to output the peeked value
*
* @note gets the data at the [0]
*/
template <class DataType>
bool PriorityQueue<DataType>::peekAtFront(DataType lookFor)
{
	if(isEmpty())
	{
		return false;
	}
	lookFor = vector1[head];
	return true;

}

/**
* @brief Implementation of showStructure
*
* @details showStructure for LinkedList class
*
* @param a list ID
*
* @note prints the elements of the structure
*/
template <class DataType>
void PriorityQueue<DataType>::showStructure(char listID)
{
	int index;

    if ( isEmpty() )
       {
        cout << "  Empty list";
        cout << endl;
       } 

    else
       {
        cout << "  List " << listID << " (" << vector1.getSize() << '/' << vector1.getCapacity() << "): ";
        for(index = 0; index < vector1.getSize(); index++)
        {
        	cout << "[" << vector1[index].priority << '/' << vector1[index].process << "] ";
        }
        cout << endl;
       }
}
