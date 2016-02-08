//dequeue
//isEmpty
//enqueue
//peekAtFront
//copy constructor
//showStructure
/**
* @file PriorityQueue.h
*
* @brief Header file for Priority Queue implementation
*
* @details Definitions of all members
* to be used in the Priority Queue class
*
* @author Mitchell Reyes
*
* @version 1.00 (16 September 2015)
*
* @note Depends on DataType and Vector header file
*/



#include "SimpleVector.h"
#include "DataType.h"
template <class DataType>
class PriorityQueue
{
	public:
	PriorityQueue();
	PriorityQueue( const DataType &PriorityQueue);
	~PriorityQueue();
	bool dequeue( DataType &outVal);
	bool isEmpty();
	bool enqueue( int priority, char* newProcess);
	bool peekAtFront(DataType lookFor);
	void showStructure( char listID );


private:
	int head;
	int rear;
	SimpleVector<DataType> vector1;
};

