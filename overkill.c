#include "headers.h"

void overkill()
{
    int i,cnt=0;
    for(i=0;i<job_seq_no;i++)
    {
        if(jobs[i].status==1)
        {
            kill(jobs[i].pid,SIGKILL);
            cnt++;
        }
    }

    if(cnt==0)
    {
        printf("No Background processes to kill\n");
    }
}