reciprocal: main.o reciprocal.o
	g++ $(CFLAGS) -o reciprocal main.o reciprocal.o

main.o:	main.c reciprocal.hpp
	gcc $(CFLAGS) -c main.c

reciprocal.o: reciprocal.cpp reciprocal.hpp
	g++ $(CFLAGS) -c reciprocal.cpp

clean:
	rm -f *.o reciprocal

# make
#	gcc -c main.c
#	g++ -c reciprocal.cpp
#	g++ -o reciprocal main.o reciprocal.o

# make CFLAGS=-02 for optimize source code

# gdb - the GNU debugger