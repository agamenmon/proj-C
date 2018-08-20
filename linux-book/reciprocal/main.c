#include <stdio.h>
#include "reciprocal.hpp"

int main (int argc, char **argv)
{
    int i;

    i = strtol(argv[1], NULL, 0); /* strtol for more flexible */
    printf ("The reciprocal of %d is %g\n", i, reciprocal (i));
    return 0;
}

/*
Note: 

1. Compiling a single file
    % gcc -c main.c
  the resulting object file is named main.o
    % g++ -c reciprocal.cpp

2. Add define (add NDEBUG)
    % g++ -c -D NDEBUG reciprocal.cpp
  or 
    % g++ -c -D NDEBUG=3 reciprocal.cpp

3. Optimize source code compiling (add -02)
    % g++ -c -O2 reciprocal.cpp

4. Linking the ouput file
    % g++ -o reciprocal main.o reciprocal.o

5. Link the library (add -l..)
    % g++ -o reciprocal main.o reciprocal.o -lpam
  Pluggable Authentication Module (PAM) library is called libpam.a
  or
    % g++ -o reciprocal main.o reciprocal.o -L/usr/local/lib/pam -lpam
*/