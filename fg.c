#include "headers.h"
void fg(char * input_str)
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
            kill(jobs[id].pid , SIGCONT);
            printf("%s brought to Foreground\n",jobs[id].command);
            waitpid(jobs[id].pid, &status, WUNTRACED);
            if(WIFSTOPPED(status)==0)
                jobs[id].status = 0;
        }
        else
        {
            printf("Job not found\n");
            return;
        }
    }
}