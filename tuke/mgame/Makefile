# variables
CC = gcc
CFLAGS = -std=c11 -Wall -Werror
LDLIBS = -lm
OUTPUT = game

#targets
all: hof.o k.o main.o
	$(CC) $(CFLAGS) $(LDLIBS) hof.o k.o main.o -o $(OUTPUT)

hof.o: hof.c
	$(CC) $(CFLAGS) $(LDLIBS) -c hof.c

k.o: k.c
	$(CC) $(CFLAGS) $(LDLIBS) -c k.c

main.o: main.c
	$(CC) $(CFLAGS) $(LDLIBS) -c main.c

clean:
	$(RM) *.o $(OUTPUT)


