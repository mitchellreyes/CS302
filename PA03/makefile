CC = g++
DEBUG = -g
CFLAGS = -Wall -c
LFLAGS = -Wall

PA03 : PA03.o PriorityQueue.o SimpleVector.o DataType.o
	$(CC) $(LFLAGS) PA03.o PriorityQueue.o SimpleVector.o DataType.o -o PA03

PA03.o : PA03.cpp PriorityQueue.h PriorityQueue.cpp SimpleVector.h SimpleVector.cpp
	$(CC) $(CFLAGS) PA03.cpp

PriorityQueue.o : PriorityQueue.h SimpleVector.h DataType.h
	$(CC) $(CFLAGS) PriorityQueue.cpp

SimpleVector.o : SimpleVector.h SimpleVector.cpp
	$(CC) $(CFLAGS) SimpleVector.cpp

DataType.o : DataType.h DataType.cpp
	$(CC) $(CFLAGS) DataType.cpp

clean:
	\rm *.o PA03

