CC = g++
DEBUG = -g
CFLAGS = -Wall -c
LFLAGS = -Wall

PA05 : PA05.o QkSorter.o MrgSorter.o SelSorter.o SorterClass.o SimpleVector.o SimpleTimer.o DateType.o
	$(CC) $(LFLAGS) PA05.o QkSorter.o MrgSorter.o SelSorter.o SorterClass.o SimpleVector.o SimpleTimer.o DateType.o -o PA05

PA05.o : PA05.cpp DateType.h DateType.cpp SimpleTimer.h SimpleTimer.cpp SimpleVector.h SimpleVector.cpp SorterClass.h SorterClass.cpp SelSorter.h SelSorter.cpp MrgSorter.h MrgSorter.cpp QkSorter.h QkSorter.cpp
	$(CC) $(CFLAGS) PA05.cpp

SelSorter.o : SelSorter.h SelSorter.cpp SorterClass.h SorterClass.cpp SimpleVector.h SimpleVector.cpp
	$(CC) $(CFLAGS) SelSorter.cpp

MrgSorter.o : MrgSorter.h MrgSorter.cpp SorterClass.h SorterClass.cpp SimpleVector.h SimpleVector.cpp
	$(CC) $(CFLAGS) MrgSorter.cpp

QkSorter.o : QkSorter.h QkSorter.cpp SorterClass.h SorterClass.cpp SimpleVector.h SimpleVector.cpp
	$(CC) $(CFLAGS) QkSorter.cpp

SorterClass.o : SimpleVector.h SimpleVector.cpp SorterClass.h SorterClass.cpp
	$(CC) $(CFLAGS) SorterClass.cpp

SimpleVector.o : SimpleVector.h SimpleVector.cpp
	$(CC) $(CFLAGS) SimpleVector.cpp

SimpleTimer.o : SimpleTimer.h SimpleTimer.cpp
	$(CC) $(CFLAGS) SimpleTimer.cpp

DateType.o : DateType.h DateType.cpp
	$(CC) $(CFLAGS) DateType.cpp

clean:
	\rm *.o PA05

