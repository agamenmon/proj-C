#include <pthread.h>
#include <stdio.h>

/* Compute successive prime numbers (very inefficiently). Rerun the Nth 
prime number, where N is the value pointed to by * AVG */
void *computer_prime(void *arg)
{
	int cadidate = 2;
	int n = *((int *) arg);

	while(1)
	{
		int factor;
		int is_prime = 1;

		/* Test primality by successive division. */
		for(factor = 2; factor < cadidate; ++factor)
		{
			if (cadidate % factor == 0)
			{
				is_prime = 0;
				break;
			}
		}
		/* Is this the prime number we're looking for ?*/
		if(is_prime)
		{
			if(--n)
			{
				/* Return the desire prime number as the thread return value. */
				return (void *) cadidate;
			}
		}
		++cadidate;
	}
	return NULL;
}

/* the main program */
int main(int argc, char const *argv[])
{
	pthread_t thread;
	int which_prime = 5000;
	int prime;


	/* Start the computing thread, up to the 5000th prime number. */
	pthread_create(&thread, NULL, &computer_prime, &which_prime);

	/* Do some other work here... */
	/* wait for the prime number thread to complete, and get the result. */
	pthread_join(thread, (void *) &prime);

	/* Print the largest prome it computed. */
	printf(" The &th prime number is %d.\n", which_prime, prime);
	return 0;
}