#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList(int maxSize){
	size = 0;
	capacity = maxSize;
	head = cursor = NULL;
}

LinkedList::LinkedList(const LinkedList&rhs){
	this->capacity = rhs.capacity;
	*this = rhs;
}

LinkedList::~LinkedList()
{
	size = 0;
	while(!isEmpty())
	{
		clear();
	}
	head = cursor = NULL;
}

bool LinkedList::insertBeforeCursor(int inputData)
{
	if(isFull()|| head ==cursor)
	{
		return false;
	}
	if(isEmpty()){
		head = cursor = new ListNode(inputData, NULL);
		size += 1;
		return true;
	}
	ListNode* cursorCpy = cursor;
	goToPrior();
	cursor->next = new ListNode(inputData, cursor->next);
	cursor = cursorCpy;
	delete cursorCpy;
	size += 1;
	return true;
}

bool LinkedList::insertAfterCursor(int inputData)
{
	if(isFull())
	{
		return false;
	}
	if(isEmpty()){
		head = cursor = new ListNode(inputData, NULL);
		size += 1;
		return true;
	}
	cursor = cursor->next = new ListNode(inputData, cursor->next);
	size += 1;
	return true;
}

bool LinkedList::replaceBeforeCursor(int inputData)
{
	if(isEmpty()||size == 1)
	{
		return false;
	}
	ListNode* cursorCpy = cursor;
	goToPrior();
	cursor->dataItem = inputData;
	cursor = cursorCpy;
	delete cursorCpy;
	return true;
}

bool LinkedList::replaceAtCursor(int inputData)
{
	if(isEmpty())
	{
		return false;
	}
	cursor->dataItem = inputData;
	return true;
}

bool LinkedList::replaceAfterCursor(int inputData)
{
	if(isEmpty()|| (cursor->next == NULL))
	{
		return false;
	}
	ListNode* cursorCpy = cursor;
	goToNext();
	cursor->dataItem = inputData;
	cursor = cursorCpy;
	delete cursorCpy;
	return true;
}

bool LinkedList::removeAtCursor(int &outVal)
{
	if(isEmpty()||size == 0)
	{
		return false;
	}
	if(size == 1)
	{
		outVal = cursor->dataItem;
		delete cursor;
		head = cursor = NULL;
		size -= 1;
		return true;
	}
	if(cursor->next == NULL)
	{
		delete cursor;
		cursor = head;
		size -= 1;
		return true;
	}
	if(head == cursor)
	{
		head = head->next;
		delete cursor;
		cursor = head;
		size -= 1;
		return true;
	}

	outVal = cursor->dataItem;
	ListNode* cursorCpy = cursor;
	goToPrior();
	cursor->next = cursorCpy->next;
	cursor = cursor->next;
	delete cursorCpy;
	size -= 1;
	return true;
}

void LinkedList::clear()
{
	int garbage;
	while(removeAtCursor(garbage));
}

LinkedList& LinkedList::isAssigned(const LinkedList& rhsList)
{
	ListNode*rhsPtr = rhsList.head;
	if(head != NULL && cursor != NULL){
		clear();
	}
	if(rhsList.head == NULL && rhsList.cursor == NULL){
		return *this;
	}
	head = new ListNode(rhsPtr->dataItem, NULL);
	ListNode* cpyListPtr = head;
	//the while loop takes care if there is only 1 node
	while(rhsPtr->next != NULL)
	{
		rhsPtr = rhsPtr->next;
		cpyListPtr = cpyListPtr->next = new ListNode(rhsPtr->dataItem, NULL);
		if(rhsPtr == rhsList.cursor)
		{
			cursor = cpyListPtr;
		}
	}
	return *this;
}

LinkedList& LinkedList::operator=(const LinkedList& rhsList)
{
	ListNode*rhsPtr = rhsList.head;
	if(head != NULL && cursor != NULL){
		clear();
	}
	if(rhsList.head == NULL && rhsList.cursor == NULL){
		return *this;
	}
	head = new ListNode(rhsPtr->dataItem, NULL);
	ListNode* cpyListPtr = head;
	//the while loop takes care if there is only 1 node
	while(rhsPtr->next != NULL)
	{
		rhsPtr = rhsPtr->next;
		cpyListPtr = cpyListPtr->next = new ListNode(rhsPtr->dataItem, NULL);
		if(rhsPtr == rhsList.cursor)
		{
			cursor = cpyListPtr;
		}
	}
	size = rhsList.size;
	return *this;
}

bool LinkedList::getDataAtCursor(int &outVal) const
{
	if(isEmpty())
	{
		return false;
	}
	outVal = cursor->dataItem;
	return true;
}

void LinkedList::showStructure(char whichList) const
{	
	if(isEmpty())
	{
		cout << "Empty List" << endl;
	}
	else if(size == 1)
	{
		cout << "List " << whichList << " (" << size << "/"
		<< capacity << "): " << "[" << head->dataItem << "] ";
	}
	else
	{
		ListNode* listPtr = head;
		cout << "List " << whichList << " (" << size << "/"
			<< capacity << "): " << "[" << head->dataItem << "] ";
		while(listPtr->next != NULL)
		{
			listPtr = listPtr->next;
			cout << listPtr->dataItem << " ";
		}
		delete listPtr;
	}
	cout << endl;
}

bool LinkedList::isEmpty()const
{
	if(head == NULL){
		return true;
	}else{
		return false;
	}
}

bool LinkedList::isFull()const
{
	if(size == capacity){
		return true;
	}else{
		return false;
	}
}

bool LinkedList::goToBeginning()
{
	if(isEmpty())
	{
		return false;
	}
	cursor = head;
	return true;
}

bool LinkedList::goToEnd()
{
	if(isEmpty()){
		return false;
	}
	while(cursor->next != NULL)
	{
		goToNext();
	}
	return true;
}

bool LinkedList::goToNext()
{
	if(isEmpty()||cursor->next == NULL)
	{
		return false;
	}
	cursor = cursor->next;
	return true;
}

bool LinkedList::goToPrior()
{
	if(cursor == head || isEmpty())
	{
		return false;
	}
	ListNode* cursorCpy = cursor;
	cursor = head;
	while(cursor->next != cursorCpy)
	{
		cursor = cursor->next;
	}
	return true;

}

