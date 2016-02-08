CC = g++
DEBUG = -g
CFLAGS = -Wall -c
LFLAGS = -Wall

PA09 : PA09.o MedType.o SimpleTimer.o
	$(CC) $(LFLAGS) PA09.o MedType.o SimpleTimer.o -o PA09

PA09.o : PA09.cpp HeapClass.h HeapClass.cpp MedType.h MedType.cpp SimpleTimer.h SimpleTimer.cpp
	$(CC) $(CFLAGS) PA09.cpp

BSTClass.o : HeapClass.h HeapClass.cpp
	$(CC) $(CFLAGS) HeapClass.cpp

SimpleTimer.o : SimpleTimer.h SimpleTimer.cpp
	$(CC) $(CFLAGS) SimpleTimer.cpp

MedType.o : MedType.h MedType.cpp
	$(CC) $(CFLAGS) MedType.cpp

clean:
	\rm -rf *.o PA09

