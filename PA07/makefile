CC = g++
DEBUG = -g
CFLAGS = -Wall -c
LFLAGS = -Wall

PA07 : PA07.o AcctType.o SimpleTimer.o
	$(CC) $(LFLAGS) PA07.o AcctType.o SimpleTimer.o -o PA07

PA07.o : PA07.cpp BSTClass.h BSTClass.cpp AcctType.h AcctType.cpp SimpleTimer.h SimpleTimer.cpp
	$(CC) $(CFLAGS) PA07.cpp

BSTClass.o : BSTClass.h BSTClass.cpp
	$(CC) $(CFLAGS) BSTClass.cpp

SimpleTimer.o : SimpleTimer.h SimpleTimer.cpp
	$(CC) $(CFLAGS) SimpleTimer.cpp

AcctType.o : AcctType.h AcctType.cpp
	$(CC) $(CFLAGS) AcctType.cpp

clean:
	\rm -rf *.o PA07

