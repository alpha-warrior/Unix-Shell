#include "headers.h"

void echo(char *input_str)
{
    char * token = strtok(input_str," ");
    token=strtok(NULL, " ");

    while(token!=NULL)
    {
        printf("%s ",token);
        token=strtok(NULL, " ");
    }
    printf("\n");
}