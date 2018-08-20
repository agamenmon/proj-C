#include <stdio.h>

/* The ENVRION variable contains the enviorment. */
extern char** environ;

int main()
{
	char **var;
	for(var = environ; *var != NULL; ++var) {
		printf("%s\n", *var);
	}

	return 0;
}
/*
* Note:
* Dont modify environ yourself, use the setenv and unsetenv function instead.
*/