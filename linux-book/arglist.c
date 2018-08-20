#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("the name of this program is '%s'.\n", argv[0]);
	printf("this program was invoked with %d arguments.\n", argc - 1);

	/* Were any command-line argument specified ?*/
	if(argc - 1)
	{
		/* yes, print them */
		int i;
		printf("The argument are: \n");
		for(i = 0; i < argc; i++)
		{
			printf(" %s\n", argv[i]);
		}
	}

	return 0;
}