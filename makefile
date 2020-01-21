#
# Makefile for garagedoor
# File: makefile
#
CC = gcc
LINK = gcc
# '-pedantic' sorgt dafuer, dass g++ streng arbeitet
CFLAGS = -c -pedantic -Wall
LFLAGS = -pedantic -Wall
OBJS = test.o handler.o
EXE = cb

$(EXE): $(OBJS)
	$(LINK) $(LFLAGS) -o $(EXE) $(OBJS)

handler.o: handler.c handler.h
	$(CC) $(CFLAGS) handler.c

test.o: test.c handler.h
	$(CC) $(CFLAGS) handler.c

clean:
	# for UNIX
	3rm -f $(EXE) $(OBJS)
	# for WIN
	del $(EXE) $(OBJS)
