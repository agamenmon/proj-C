/* Create a thread */
#include <pthread.h>
#include <stdio.h>

/* Prints x's to stderr. The parameter is unused. Does not return. */
void *print_xs(void *unused)
{
	while(1)
	{
		fputc('x', stderr);
	}

	return NULL;
}

/* The main program */
int main(int argc, char const *argv[])
{
	pthread_t thread_id;

	/* Create a new thread. The new thread will run the print_xs function. */
	pthread_create(&thread_id, NULL, &print_xs, NULL);

	/* Print o's continously to stderr. */
	while(1)
	{
		fputc('o', stderr);
	}
	return 0;
}
/* Compile */
/*
	gcc -o thread-create thread-create.c -lpthread
*/