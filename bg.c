#include "headers.h"

void bg(char * input_str)
{
    int i,token_cnt=0,id,status;
    char * token = strtok(input_str," ");
    while(token!=NULL)
    {
        if(token_cnt==1)
        {
            id = atoi(token);
        }
        token = strtok(NULL," ");
        token_cnt++;
    }
    // printf("%d",token_cnt);
    if(token_cnt==1||token_cnt>=3)
    {
        printf("Inconsistent number of arguments\n");
        return;
    }
    else
    {
        if(id<job_seq_no)
        {
            if(jobs[id].status==1)
            {
                kill(jobs[id].pid , SIGCONT);
                return;
            }
        }
        else
        {
            printf("Job not found\n");
            return;
        }
    }
}