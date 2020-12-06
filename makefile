CC=gcc
AR=ar
FLAGS= -Wall -g

all: libmyBank.so libmyBank.a mains maind

mybanks: libmyBank.a

mybankd: libmyBank.so

mains: main.o libmyBank.a
	$(CC) $(FLAGS) -o mains main.o myBank.o libmyBank.a -lm

maind: main.o libmyBank.so
	$(CC) $(FLAGS) -o maind main.o myBank.o ./libmyBank.so -lm

libmyBank.a: myBank.o
			$(AR) -rcs libmyBank.a myBank.o

libmyBank.so: myBank.o
			$(CC) -shared -o libmyBank.so myBank.o

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

myBank.o: myBank.c myBank.h
			$(CC) $(FLAGS) -c myBank.c

.PHONY: clean all mybanks mybankd

clean:
	rm -f *.o *.a *.so mains maind