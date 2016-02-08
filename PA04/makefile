CC = g++
DEBUG = -g
CFLAGS = -Wall -c
LFLAGS = -Wall

PA04 : PA04.o TestSorter.o SorterClass.o SimpleVector.o SimpleTimer.o DateType.o
	$(CC) $(LFLAGS) PA04.o TestSorter.o SorterClass.o SimpleVector.o SimpleTimer.o DateType.o -o PA04

PA04.o : PA04.cpp DateType.h DateType.cpp SimpleTimer.h SimpleTimer.cpp SimpleVector.h SimpleVector.cpp SorterClass.h SorterClass.cpp TestSorter.h TestSorter.cpp
	$(CC) $(CFLAGS) PA04.cpp

TestSorter.o : TestSorter.h TestSorter.cpp SorterClass.h SorterClass.cpp SimpleVector.h SimpleVector.cpp
	$(CC) $(CFLAGS) TestSorter.cpp

SorterClass.o : SimpleVector.h SimpleVector.cpp SorterClass.h SorterClass.cpp
	$(CC) $(CFLAGS) SorterClass.cpp

SimpleVector.o : SimpleVector.h SimpleVector.cpp
	$(CC) $(CFLAGS) SimpleVector.cpp

SimpleTimer.o : SimpleTimer.h SimpleTimer.cpp
	$(CC) $(CFLAGS) SimpleTimer.cpp

DateType.o : DateType.h DateType.cpp
	$(CC) $(CFLAGS) DateType.cpp

clean:
	\rm *.o PA04

