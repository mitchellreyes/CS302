CC = g++
DEBUG = -g
CFLAGS = -Wall -c
LFLAGS = -Wall

PA06 : PA06.o NameType.o SimpleTimer.o
	$(CC) $(LFLAGS) PA06.o NameType.o SimpleTimer.o -o PA06

PA06.o : PA06.cpp BSTClass.h BSTClass.cpp NameType.h NameType.cpp SimpleTimer.h SimpleTimer.cpp
	$(CC) $(CFLAGS) PA06.cpp

BSTClass.o : BSTClass.h BSTClass.cpp
	$(CC) $(CFLAGS) BSTClass.cpp

SimpleTimer.o : SimpleTimer.h SimpleTimer.cpp
	$(CC) $(CFLAGS) SimpleTimer.cpp

NameType.o : NameType.h NameType.cpp
	$(CC) $(CFLAGS) NameType.cpp

clean:
	\rm -rf *.o PA06

