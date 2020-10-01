#include "headers.h"

void setenvi(char * input_str)
{
    long long int i,j,k=0,token_cnt=0;
    char var[10000]="\0",value[10000]="\0";

    char * token = strtok(input_str," ");

    while(token!=NULL)
    {
        if(token_cnt==1)
        {
            strcpy(var,token);
        }
        else if(token_cnt==2)
        {
            strcpy(value,token);
        }
        token = strtok(NULL," ");
        token_cnt++;
    }

    if(token_cnt==1 || token_cnt >=4)
    {
        printf("Inconsistent number of arguments provided\n");
        return;
    }
    else
    {
        k = setenv(var,value,1);
        if(k<0)
        {
            fprintf(stderr,"Variable cannot be set\n");
        }
    }

}