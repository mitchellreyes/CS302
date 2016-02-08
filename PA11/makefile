CC = g++
DEBUG = -g
CFLAGS = -Wall -c
LFLAGS = -Wall

PA11 : PA11.o OrderedSetClass.o GraphClass.o SimpleVector.o SimpleMatrix.o SimpleTimer.o PathType.o VertexType.o
	$(CC) $(LFLAGS) PA11.o OrderedSetClass.o GraphClass.o SimpleVector.o SimpleMatrix.o SimpleTimer.o PathType.o VertexType.o -o PA11

PA11.o : PA11.cpp OrderedSetClass.h OrderedSetClass.cpp SimpleVector.h SimpleVector.cpp SimpleTimer.h SimpleTimer.cpp PathType.h PathType.cpp VertexType.h VertexType.cpp
	$(CC) $(CFLAGS) PA11.cpp

OrderedSetClass.o : OrderedSetClass.h OrderedSetClass.cpp SimpleVector.h SimpleVector.cpp
	$(CC) $(CFLAGS) OrderedSetClass.cpp

GraphClass.o : GraphClass.h GraphClass.cpp
	$(CC) $(CFLAGS) GraphClass.cpp

SimpleVector.o : SimpleVector.h SimpleVector.cpp
	$(CC) $(CFLAGS) SimpleVector.cpp

SimpleMatrix.o : SimpleMatrix.h SimpleMatrix.cpp
	$(CC) $(CFLAGS) SimpleMatrix.cpp

SimpleTimer.o : SimpleTimer.h SimpleTimer.cpp
	$(CC) $(CFLAGS) SimpleTimer.cpp

VertexType.o : VertexType.h VertexType.cpp
	$(CC) $(CFLAGS) VertexType.cpp

PathType.o : PathType.h PathType.cpp
	$(CC) $(CFLAGS) PathType.cpp

clean:
	\rm -rf *.o PA11

