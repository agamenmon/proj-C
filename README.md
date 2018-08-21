# proj-C
 - I relly like this project beccause the program has already comment so detail, and optimized. 
 	Its easy to understatnd and remember. 

## strtol and atoi
 - strtol provides you with more flexibility, as it can actually tell you if the whole string was converted to an integer or not
 - atoi, atol, atoll when unable to convert the string to a number (like in atoi("help")), returns 0, which is indistinguishable from atoi("0")

# The environment
 - USER contains your username.
 - HOME constains the path to your home directory.
 - PATH contains a colon-separted list of directories through which Linux searches for commands you invoke.
 - DISPLAY contains the name and display number of the X Window server on which windows from graphical X Window will appear.

#assert
 - Dont hold back, use assert liberally throughout your programs.
 - allows diagnostic information to be written to the standard error file. In other words, it can be used to add diagnostics in your C program.

## Error Codes from System Calls
 - A majority of system calls return zero if the operation succeeds, or a nonzero value if the operation fails.

## Create an archive
 - ar cr libtest.a test1.o test2.o
 - The cr flags tell ar to create the archive. Now you can link this archive using the -ltest option with gcc or g++.
```
 Note:
  - gcc -o app -L. -ltest app.o : This command line will not work. 
  	app.o: In function ‘main’:
	app.o(.text+0x4): undefined reference to ‘f’
	collect2: ld returned 1 exit status

  - gcc -o app app.o -L. –ltest. This command line will work
  - The reason is that the reference to f in app.o causes the linker to include the test.o pbject file from the libtest.a archive
```

## Position-Independent Code (PIC)
 - The function in a share library may be loaded at different addresses in different programs, so the code in the shared object must not depend on the address( or position) at which it is loaded. this consideration has no impact on you, as the programmer, except that you muse remember to use the -fPIC flag when compiling code that will be used in a share library.
 You can compile the object files into a shared library, like this:
```
 	gcc -shared -fPIC -o libtest.so test1.o test2.o
```