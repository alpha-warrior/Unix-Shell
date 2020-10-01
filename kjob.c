#include "headers.h"

void kjob(char * input_str)
{
    // printf("INSIDE");
    // return;
    long long int i,j,k,token_cnt=0,job_id,signal;
    char * token = strtok(input_str," ");
    // printf("%s",token);
    while(token!=NULL)
    {
        if(token_cnt==1)
        {
            job_id = atoi(token);
        }
        else if(token_cnt==2)
        {
            signal = atoi(token);
        }
        token = strtok(NULL," ");
        token_cnt++;
    }
    // printf("%lld %lld",job_id,signal);
    if(token_cnt<=2||token_cnt>=4)
    {
        printf("Inconsistent number of arguments\n");
        return;
    }
    else
    {
        if(jobs[job_id].status == 1)
        {
            kill(jobs[job_id].pid,signal);
            jobs[job_id].status = 0;
        }
        else
        {
            printf("No job to kill \n");
            return;
        }
    }
}
