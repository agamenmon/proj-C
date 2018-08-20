#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *server_name = getenv ("SERVER_NAME");
    if(server_name == NULL) {

        /* Then SERVER_NAME environment variable was not set.
        Use defailt. */ 
        server_name = "server.my-company.com";
    }

    printf("accessing server %s\n", server_name);
    /* Access the server here ... */

    return 0;
}