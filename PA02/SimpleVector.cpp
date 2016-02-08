#include "SimpleVector.h"
#include <iostream>
using namespace std;


template <class DataType>
SimpleVector<DataType>::SimpleVector()
{
	vectorCapacity = DEFAULT_CAPACITY;
	vectorSize = 0;
	vectorData = new DataType[vectorCapacity];
}

template <class DataType> 
SimpleVector<DataType>::SimpleVector(int newCapacity)
{
	vectorCapacity = newCapacity;
	vectorSize = 0;
	vectorData = new DataType[vectorCapacity];
}

template <class DataType> 
SimpleVector<DataType>::SimpleVector(int newCapacity, const DataType &fillValue)
{
	int indexCount;
	vectorCapacity = newCapacity;
	vectorSize = 0;
	vectorData = new DataType[vectorCapacity];
	for(indexCount = 0; indexCount < vectorCapacity; indexCount++)
	{
		vectorData[indexCount] = fillValue;
		vectorSize++;
	}
}

template <class DataType> 
SimpleVector<DataType>::SimpleVector(const SimpleVector<DataType> &copiedVector)
{
	*this = copiedVector;
}

template <class DataType>
SimpleVector<DataType>::~SimpleVector()
{
	vectorCapacity = 0;
	vectorSize = 0;
	vectorData = NULL;
}

template <class DataType>
const SimpleVector<DataType> &SimpleVector<DataType>::operator=(const SimpleVector<DataType> &rhVector)
{
	int sizeCount;
	vectorCapacity = rhVector.vectorCapacity;
	vectorData = new DataType[vectorCapacity];
	vectorSize = rhVector.vectorSize;
	for(sizeCount = 0; sizeCount < rhVector.vectorSize; sizeCount++)
	{
		vectorData[sizeCount] = rhVector.vectorData[sizeCount];
	}
	return *this;

}

template <class DataType>
int SimpleVector<DataType>::getCapacity()const
{
	return vectorCapacity;
}

template <class DataType>
int SimpleVector<DataType>::getSize()const
{
	return vectorSize;
}

template <class DataType>
DataType &SimpleVector<DataType>::operator [ ] (int index) throw (logic_error)
{
	if(index > vectorSize || index < 0)
	{
		throw logic_error("Not within the scope of the vector");
	}
	else
	{
		return vectorData[index];
	}
}

template <class DataType>
const DataType &SimpleVector<DataType>::operator [ ] (int index) const throw(logic_error)
{
	if(index > vectorSize+1 || index+1 < 0)
	{
		throw logic_error("Not within the scope of the vector");
	}
	else
	{
		return vectorData[index];
	}
}

template <class DataType>
void SimpleVector<DataType>::grow(int growBy)
{
	vectorCapacity = vectorCapacity + growBy;
}

template <class DataType>
void SimpleVector<DataType>::shrink(int shrinkBy) throw(logic_error)
{
	if(shrinkBy > vectorCapacity)
	{
		throw logic_error("Cannot shrink by that number");
	}
	else
	{
		vectorSize = vectorSize - shrinkBy;
	}
}

template <class DataType>
void SimpleVector<DataType>::incrementSize()
{
	vectorSize++;
}

template <class DataType>
void SimpleVector<DataType>::decrementSize()
{
	vectorSize--;
}

template <class DataType>
void SimpleVector<DataType>::copyVector(DataType *dest, DataType *src)
{
	int sizeCount;
	for(sizeCount = 0; sizeCount < src.vectorSize; sizeCount++)
	{
		dest.vectorData[sizeCount] = src.vectorData[sizeCount];
	}
}