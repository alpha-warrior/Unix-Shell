#include "headers.h"
void unsetenvi(char * input_str)
{
    long long int token_cnt=0,i;
    char var[10000];
    char * token = strtok(input_str," ");
    while(token!=NULL)
    {
        if(token_cnt==1)
        {
            strcpy(var,token);
        }
        token = strtok(NULL," ");
        token_cnt++;
    }

    if(token_cnt==1||token_cnt>2)
    {
        printf("Inconsistent number of arguments\n");
        return;
    }
    else
    {
        i = unsetenv(var);
        if(i<0)
        {
            fprintf(stderr,"Variable cannot be deleted\n");
        }
    }
}