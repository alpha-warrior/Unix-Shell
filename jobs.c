#include "headers.h"

void jobs_func()
{
    long long int i,j,k,fd_file,job_cnt=0;
    char file[10000],pid_str[100],state[100];
    for(i=0;i<job_seq_no;i++)
    {
        if(jobs[i].status==1)
        {
            char file_path[1000]="/proc/";
            sprintf(pid_str,"%d",jobs[i].pid);
            strcat(file_path,pid_str);
            strcat(file_path,"/stat");
            fd_file = open(file_path,O_RDONLY);
            if(fd_file<0)
            {
                jobs[i].status=0;
            }
            else
            {
                job_cnt+=1;
                read(fd_file,file,10000);
                j=0;
                char * token = strtok(file," ");
                while(token!=NULL)
                {
                    token = strtok(NULL," ");
                    j++;
                    // printf(":: %s\n",token);
                    if(j==2)
                        break;
                }
                if(strcmp(token,"T")==0)
                {
                    strcpy(state,"Stopped");
                }
                else
                {
                    // printf("%s",token);
                    strcpy(state,"Running");
                }
                printf("[%lld] %s %s [%d]\n",i,state,jobs[i].command,jobs[i].pid);
            }
        }
    }

    if(job_cnt==0)
    {
        printf("No jobs are running currently\n");
    }

}