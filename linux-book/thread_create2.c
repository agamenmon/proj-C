/* create two threads. */
#include <pthread.h>
#include <stdio.h>

/* Parameters to print_function. */
struct char_print_parms
{
	/* The character to print. */
	char character;

	/* The number of times to print it. */
	int count;
};

/* prints a number of characters to stderr, as given by PARAMETERS, 
which is a pointer to a struct char_print_parms. */
void *char_print(void *parameters)
{
	/* Cast the cookie pointer to the right type. */
	struct char_print_parms *p = (struct char_print_parms*) parameters;
	int i;

	for(i = 0; i < p->count; ++i)
	{
		fputc(p->characters, stderr);
	}

	return NULL;
}

/* The main program. */
int main(int argc, char const *argv[])
{
	pthread_t thread_one_id;
	pthread_t thread_two_id;

	struct char_print_parms thread_one_args;
	struct char_print_parms thread_two_args;

	/* Create a new thread to print 30,000 'x's. */
	thread_two_args.characters = 'x';
	thread_one_args.count = 30000;
	pthread_create(&thread_one_id, NULL, &char_print, &thread_one_args);

	/* create a new thread to printf 20,000 'o's*/
	thread_two_args.characters = '0';
	thread_two_args.count = 20000;
	pthread_create(&thread_two_id, NULL, &char_print, &thread_two_args);

	return 0;
}