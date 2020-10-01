#include "headers.h"

void signal_control(int signal)
{
    if(foreground_job.pid>0)
    {
        jobs[job_seq_no].pid = foreground_job.pid;
        strcpy(jobs[job_seq_no].command,foreground_job.command);
        jobs[job_seq_no].id=job_seq_no;
        jobs[job_seq_no].status = 1;
        job_seq_no++;
  		kill(foreground_job.pid , signal);
        foreground_job.pid=-1;
        printf("\n");
    }
    else
    {
        printf("\nNo foreground process found\n");
        printf("Press [ENTER] to continue\n");
    }
}