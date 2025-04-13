CC=gcc
OUTPUT=ps2
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=-lm

all: ps2

ps2: playfair.o bmp.o main.c
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 main.c
	$(CC) $(CFLAGS) $(LDLIBS) *.o -o $(OUTPUT)

bmp.o: bmp.c
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 bmp.c
	$(CC) $(CFLAGS) $(LDLIBS) bmp.c -c -o bmp.o

playfair.o: playfair.c
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 k.c
	$(CC) $(CFLAGS) $(LDLIBS) playfair.c -c -o playfair.o

clean:
	rm *.o ps2
