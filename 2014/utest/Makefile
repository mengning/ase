
all:
	gcc -c test.c -o test.o
	gcc -c linktable.c -o linktable.o
	gcc linktable.o test.o -o test

clean:
	rm -rf *.o test
