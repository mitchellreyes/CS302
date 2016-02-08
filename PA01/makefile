CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

PA01 : PA01.o LinkedList.o ListNode.o
	$(CC) $(LFLAGS) PA01.o LinkedList.o ListNode.o -o PA01

PA01.o : LinkedList.cpp
	$(CC) $(CFLAGS) PA01.cpp

LinkedList.o : LinkedList.cpp
	$(CC) $(CFLAGS) LinkedList.cpp

ListNode.o : ListNode.cpp
	$(CC) $(CFLAGS) ListNode.cpp

clean:
	\rm *.o PA01
