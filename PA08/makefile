CC = g++
DEBUG = -g
CFLAGS = -Wall -c
LFLAGS = -Wall

PA08 : PA08.o SolverClass.o Rectangle.o SimpleMatrix.o SimpleVector.o SimpleTimer.o
	$(CC) $(LFLAGS) PA08.o SolverClass.o Rectangle.o SimpleTimer.o -o PA08

PA08.o : PA08.cpp SolverClass.h SolverClass.cpp Rectangle.h Rectangle.cpp SimpleMatrix.cpp SimpleVector.cpp SimpleTimer.h SimpleTimer.cpp 
	$(CC) $(CFLAGS) PA08.cpp

SolverClass.o : SolverClass.h SolverClass.cpp
	$(CC) $(CFLAGS) SolverClass.cpp

Rectangle.o : Rectangle.h Rectangle.cpp
	$(CC) $(CFLAGS) Rectangle.cpp

SimpleMatrix.o : SimpleMatrix.h SimpleMatrix.cpp
	$(CC) $(CFLAGS) SimpleMatrix.cpp

SimpleVector.o : SimpleVector.h SimpleVector.cpp
	$(CC) $(CFLAGS) SimpleVector.cpp

SimpleTimer.o : SimpleTimer.h SimpleTimer.cpp
	$(CC) $(CFLAGS) SimpleTimer.cpp

clean:
	\rm -rf *.o PA08

