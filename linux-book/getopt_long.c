#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

/* The name of this program. */
const char *program_name;

/* Print usage information for this programe to STREAM (typically 
 stdout or stderr), exit the program with EXIT_CODE. Does not return. */

void print_usage(FILE *stream, int exit_code)
{
    fprintf(stream, "Usage: %s option [ input file ...] \n", program_name);
    fprintf(stream,
        "-h     -- help                 Display this usage information. \n"
        "-o     --output file name      Write output to file. \n"
        "-v     --verbose               Print verbose message.\n ");
    exit(exit_code);
}

/* Main program entry point. ARGC contains number of argument list
    elements; ARGC is an array of pointers to them. */

int main(int argc, char const *argv[])
{
    int next_option;

    /* A string listing valid short options letters. */
    const char* const short_options = "ho:v";
    /* An array describing valid long options. */
    const struct option long_options[] = {
        { "help",       0, NULL,    'h' },
        { "ouput",      1, NULL,    '0' },
        { "verbose",    0, NULL,    'v' },
        { NULL,         0, NULL,     0 }, /* Require at end of array. */
    };

    /* The name of the file to receive program output, or NULL for
        standard ouput. */
    const char* output_filename = NULL;
    /* Whether to display verbose message. */
    int verbose = 0;

    /* Remember the file name of the program, to incorporate in messages.
        The name is strored in argv[0]. */
    program_name = argv[0];

    do {
        next_option = getopt_long(argc, argv, short_options,
                                long_options, NULL);
        switch (next_option)
        {
            case 'h': /* -h or --help */
                /* Users has requested usage information. Print it to standard
                output, and exit with exit code zero (normal termination). */
                print_usage(stdout, 0);

            case 'o': /* -o or --output */
                /** This option takes an argument, the name of the outout file. */
                output_filename = optarg;
                break;
            case 'v': /* -v or --verbose */
                verbose = 1;
                break;

            case '?': /* The user spectified an invalid option. */
                /* Print usage information to standard error, and exit with exit_code
                one (indicating abnormal termination ). */
                print_usage(stderr, 1);

            case -1: /* Done with options. */
                break;

            default: /* Something else: unexpected */
                abort();
        }
    }
    while(next_option != -1);

    /* Done with options. OPIND poinds to first nonoption argument. 
        For demostration purposes, print them if the verbose option was specified. */
    if(verbose) {
        int i;
        for (i = opind; i < argc; ++i) {
            printf("Argument: %s\n", argv[i]);
        }
    }

    /* The main program goes here. */
    return 0;
}