// Program Information ////////////////////////////////////////////////////////
/**
 * @file HashClass.cpp
 *
 * @brief Implementation file for HashClass class
 * 
 * @details Implements the constructor method of the HashClass class
 *
 * @author Mitchell Reyes
 *
 * @version 1.00 (18 November 2015)
 *
 * @Note Requires HashClass.h, SimpleVector.cpp
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef HASH_CLASS_CPP
#define HASH_CLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "HashClass.h"
#include "SimpleVector.cpp"
#include <new>
#include <iostream>

using namespace std;

// Class Implementation  //////////////////////////////////////////////////////

template<typename DataType>
HashNode<DataType>::HashNode( const DataType &newData, HashNode *next ): data( newData ), nextPtr( next )
{

}

template<typename DataType>
HashClass<DataType>::HashClass(): tableLength( 0 ), hashLetterCount( DEFAULT_HASH_LETTER_COUNT ), list()
{

}

//////////////////////to be implemented//////////////////////////////////////////////////////// 
/**
 * @brief Implementation of the copy constructor
 *
 * @details Uses the overloaded assignment operator
 *          
 * @param another HashClass to be copied
 *
 * @note None
 */          
template<typename DataType>
HashClass<DataType>::HashClass( const HashClass<DataType> &copied ): tableLength( copied.tableLength ), hashLetterCount( copied.hashLetterCount ), list( copied.tableLength )
{
    *this = copied;
}

/**
 * @brief Implementation of the deconstructor
 *
 * @details clears the list
 *          
 * @param None
 *
 * @note None
 */
template<typename DataType>
HashClass<DataType>::~HashClass()
{
  //deconstructor
    if(!isEmpty())
    {
        clearList();
    }
    tableLength = 0;
    hashLetterCount = 0;
}

/**
 * @brief Implementation of the clearList
 *
 * @details deletes all the nodes in the list
 *          
 * @param None
 *
 * @note None
 */
template<typename DataType>
void HashClass<DataType>::clearList()
{
    if(!isEmpty())
    {
        HashNode<DataType> *cursor;
        HashNode<DataType> *temp;
        for(int i = 0; i < tableLength; i++)
        {
            cursor = list[i];
            if(cursor != NULL)
            {
                while(cursor->nextPtr != NULL)
                {
                    temp = cursor;
                    cursor = cursor->nextPtr;
                    delete temp;
                }
                delete cursor;
                list[i] = NULL;
                temp = NULL;
                cursor = NULL;
            }

        }
    }
}

/**
 * @brief Implementation of the overloaded assignment operator
 *
 * @details clears the lhs, then makes new nodes according to the rh list
 *          
 * @param HashClass that wants to be copied
 *
 * @note returns the HashClass back
 */
template <typename DataType>
const HashClass<DataType>& HashClass<DataType>:: operator = ( const HashClass &rhHashTable )
{
    if(!isEmpty())
    {
        clearList();
    }
    setTableLength(rhHashTable.tableLength);
    list.grow(tableLength);
    HashNode<DataType> *cursor;
    HashNode<DataType> *cursorCpy;
    for(int i = 0; i < rhHashTable.tableLength; i++)
    {
        //cursor pointing to the beginning of the rhList
        cursor = rhHashTable.list[i];
        if(cursor != NULL)
        {
            list[i] = new HashNode<DataType>(cursor->data, NULL);
            if(cursor->nextPtr != NULL)
            {
                cursorCpy = list[i];
                cursor = cursor->nextPtr;
                while(cursor->nextPtr != NULL)
                {
                    cursorCpy->nextPtr = new HashNode<DataType>(cursor->data, NULL);
                    cursorCpy = cursorCpy->nextPtr;
                    cursor = cursor->nextPtr;
                }
                cursorCpy->nextPtr = new HashNode<DataType>(cursor->data, NULL);
            }
        }
        else
        {
            list[i] = NULL;
        }
    }
    return *this;
}

/**
 * @brief Implementation of setting the table length
 *
 * @details sets the table length if its a non negative number
 *          
 * @param table length
 *
 * @note None
 */
template <typename DataType>
void HashClass<DataType>::setTableLength( int newTableLength )
{
    //dont want a negative table length
    if(newTableLength >= 0) 
    {
        tableLength = newTableLength;
    }
}

/**
 * @brief Implementation of setting the Hash letter count
 *
 * @details sets Hash letter count if its a non negative number
 *          
 * @param letter count
 *
 * @note None
 */
template <typename DataType>
void HashClass<DataType>::setHashLetterCount( int newHashLetterCount )
{
    //dont want a negative letter count or else a segfault can occur
    if(newHashLetterCount >= 0) 
    {
        hashLetterCount = newHashLetterCount;
    } 
}


/**
 * @brief Implementation of adding an item to the HashClass
 *
 * @details hashs the param, if the index is greater than the size of the table, grow the vector. Traverse that list[index] to find an open pointer to create the node
 *          
 * @param DataType
 *
 * @note None
 */
template <typename DataType>
bool HashClass<DataType>::addItem( const DataType &newData )
{
    //find the index
    int i = hash(newData);
    //if the index is greater than the size of the vector
    if(i > list.getCapacity())
    {
        //grow it by the default size (doubling the size of the vector)
        list.grow(10);
    }
    //start a cursor at the beginning of the linked list
    HashNode<DataType> *cursor = list[i];
    if(cursor != NULL)
    {
        while(cursor->nextPtr != NULL ) 
        {
            //keep traversing the list until you find an open position
            cursor = cursor->nextPtr; 
        }
        //then that position that is open, gets the new node with the data
        cursor->nextPtr = new HashNode<DataType>(newData, NULL);
    }
    else
    {
        list[i] = new HashNode<DataType>(newData, NULL);
    }
    return true;
}

/**
 * @brief Implementation of find item
 *
 * @details hashs the data, then tries to find the item in that position
 *          
 * @param DataType
 *
 * @note returns false if the index is not in bounds of the list, or if there is nothing in that array spot
 */
template <typename DataType>
bool HashClass<DataType>::findItem( const DataType &dataItem )
{
    //find the index
    int i = hash(dataItem);
    //if the index is greater than the size of the vector
    if(i > tableLength)
    {
        //it's not in the list at all
        return false;
    }
    //start a cursor at the beginning of the linked list
    HashNode<DataType> *cursor = list[i];
    if(cursor != NULL)
    {
        while(cursor->nextPtr != NULL) 
        {
            if(dataItem.compareTo(cursor->data) == 0)
            {
                return true;
            }
            //keep traversing the list until you find it
            cursor = cursor->nextPtr; 
        }
        if(dataItem.compareTo(cursor->nextPtr->data) == 0)
        {
            return true;
        }
        return false;
    }
    else
    {
        //because theres nothing in that spot for it to find
        return false;
    }
}


/**
 * @brief Implementation of removing an item
 *
 * @details makes sure the item is in the array, finds it, then removes and changes links 
 *          
 * @param DataType
 *
 * @note returns false if it cant find that item in the array
 */
template <typename DataType>
bool HashClass<DataType>::removeItem( const DataType &dataItem )
{

    //if you find the item that needs to be removed
    if(findItem(dataItem))
    {
        int i = hash(dataItem);
        HashNode<DataType> *cursor = list[i];
        HashNode<DataType> *temp = list[i];
        //if its not at the beginning
        while(dataItem.compareTo(cursor->data) != 0)
        {
            //move the cursor until you find it
            cursor=cursor->nextPtr;
        }
        //middle
        if(cursor->nextPtr != NULL && temp != cursor)
        {
            while(temp->nextPtr != cursor )
            {
                temp = temp->nextPtr;
            }
            temp->nextPtr = cursor->nextPtr;
            delete cursor;
            cursor = NULL;
            return true;
        }
        //beginning
        if(cursor->nextPtr != NULL && temp == cursor)
        {
            delete cursor;
            cursor = NULL;
            return true;
        }
        //one node
        delete cursor;
        list[i] = NULL;
        cursor = NULL;
        return true;
    }
    return false;
}

/**
 * @brief Implementation of empty
 *
 * @details checks the list if theres a node in it
 *          
 * @param None
 *
 * @note None
 */
template<typename DataType>
bool HashClass<DataType>::isEmpty() const
{
    for(int i = 0; i < tableLength; i++)
    {
        if(list[i] != NULL)
        {
            return false;
        }
    }
    return true;
}


/**
 * @brief Implementation of getting the mean of the list
 *
 * @details counts the nodes, then divides it by the table length
 *          
 * @param None
 *
 * @note returns the mean
 */
template<typename DataType>
double HashClass<DataType>::getChainLengthMean() const
{
    if(!isEmpty())
    {
        HashNode<DataType> *cursor;
        int numNodes = 0;
        for(int i = 0; i < tableLength; i++)
        {
            cursor = list[i];
            if(cursor != NULL)
            {
                while(cursor->nextPtr != NULL)
                {
                    numNodes++;
                    cursor = cursor->nextPtr;
                }
                numNodes++;
            }
        }
        return numNodes/tableLength;
    }
    return 0.0;
}

/**
 * @brief Implementation of getting the median of the biggest list
 *
 * @details counts the nodes of each list then finds the biggest list
 *          
 * @param None
 *
 * @note returns the max list size divided by 2 to get the middle
 */
template<typename DataType>
double HashClass<DataType>::getChainLengthMedian() const
{
    HashNode<DataType> *cursor;
        int numNodes;
        int max = 0;
        for(int i = 0; i < tableLength; i++)
        {
            numNodes = 0;
            cursor = list[i];
            if(cursor != NULL)
            {
                while(cursor->nextPtr != NULL)
                {
                    numNodes++;
                    cursor = cursor->nextPtr;
                }
                numNodes++;
            }
            if(numNodes > max)
            {
                max = numNodes;
            }
        }
        return max/2;
  return 0.0;
}

/**
 * @brief Implementation of show Structure
 *
 * @details prints everything in the HashClass
 *          
 * @param None
 *
 * @note None
 */
template<typename DataType>
void HashClass<DataType>::showStructure() const
{
    if(!isEmpty())
    {
        HashNode<DataType> *cursor;
        char* patientName = new char[hashLetterCount];
        char* medicalCode = new char[hashLetterCount];
        char genders;
        for(int i = 0; i < tableLength; i++)
        {
            cursor = list[i];
            if(cursor != NULL)
            {
                if(cursor->nextPtr != NULL)
                {
                    while(cursor->nextPtr != NULL ) 
                    {   
                        cursor->data.getAccount(patientName, medicalCode, genders);
                        cout << "[ " << patientName << " ] ";
                        cursor = cursor->nextPtr; //keep traversing the list until you find an open position
                    }
                    cursor->data.getAccount(patientName, medicalCode, genders);
                    cout << "[ " << patientName << " ] ";
                }
                else
                {
                    cursor->data.getAccount(patientName, medicalCode, genders);
                    cout << "[ " << patientName << " ] ";
                    //cout << "item: "; //this will just output the name
                }
            }
            else
            {
                cout << "NULL";
            }
            cout << endl;
        }
    }
    else
    {
        for(int i = 0; i < tableLength; i++)
        {
            cout << "NULL" << endl;
        }
    }
}

template<typename DataType>
int HashClass<DataType>::hash(const DataType &dataItem)
{
    DataType tempData( dataItem );

    return tempData.hash( hashLetterCount, tableLength );
}

#endif	// define HASH_CLASS_CPP





