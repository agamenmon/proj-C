/* using a signal handler */
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

sig_atomic sigusr1_count = 0;

void handler(int signal_number)
{
	++sigusr1_count;
}

int main(int argc, char const *argv[])
{
	struct sigaction sa;
	memset(&as, 0, sizeof(sa));
	sa.sa_handler = &handler;

	sigaction(SIGURS1, &sa, NULL);
	/* Do some length stuff here. */
	/* ... */

	printf("SIGURS1 was raise %d times\n", sigusr1_count);
	return 0;
}