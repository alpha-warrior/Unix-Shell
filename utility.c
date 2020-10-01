#include "headers.h"

void command_selector(char * input_str,char * add_root)
{
    char command[1000],temp[1000];
    strcpy(temp,input_str);
    char * token = strtok(temp," ");
    strcpy(command,token);
    
    if(strcmp(command,"echo")==0)
    {
        echo(input_str);
    }
    else if(strcmp(command,"cd")==0)
    {
        cd(input_str,add_root);
    }
    else if(strcmp(command,"pwd")==0)
    {
        pwd();
    }
    else if(strcmp(command,"ls")==0)
    {
        ls(input_str,add_root);
    }
    else if(strcmp(command,"pinfo")==0)
    {
        pinfo(input_str,add_root);
    }
    else if(strcmp(command,"quit")==0 || strcmp(command,"q")==0 || strcmp(command,"exit")==0)
    {
        save_history();
        exit(1);
    }
    else if(strcmp(command,"history")==0)
    {
        history(input_str);
    }
    else if(strcmp(command,"setenv")==0)
    {
        setenvi(input_str);
    }
    else if(strcmp(command,"unsetenv")==0)
    {
        unsetenvi(input_str);
    }
    else if(strcmp(command,"jobs")==0)
    {
        jobs_func();
    }
    else if(strcmp(command,"kjob")==0)
    {
        kjob(input_str);
    }
    else if(strcmp(command,"fg")==0)
    {
        fg(input_str);
    }
    else if(strcmp(command,"bg")==0)
    {
        bg(input_str);
    }
    else if(strcmp(command,"overkill")==0)
    {
        overkill();
    }
    else if(command==NULL)
    {
        exit(0);
    }
    else
    {
        sys_cmd(input_str);
    }
}

char * trim(char * input_str)
{
    long long int i,j,k,len=strlen(input_str);
    char * output_str = (char*)malloc(sizeof(char)*1000);
    for(j=len-1;j>=0;j--)
    {
        if(input_str[j]!='\n' && input_str[j]!=' ')
            break;
    }

    for(i=0;i<len;i++)
    {
        if(input_str[i]!=' ')
            break;
    }
    
    if(j!=-1)
    {   k=0;
        for(;i<=j;i++)
        {
            output_str[k++]=input_str[i];
        }
        output_str[k]='\0';
    }

    return output_str;
}

// void check_job_stat()
// {
//     long long int i,j,k,flag,tmp;
//     size_t len = 1000;
//     char * pid;
//     int pid_int;
//     FILE * file;
//     file = fopen("communicate.txt","r");
//     if(!file)
//     {
//         printf("Error in process Termination\n");
//         return;
//     }
//     i=0;
//     for(;;)
//     {
//         flag=getline(&pid,&len,file);
//         if(flag==-1)
//         {
//             break;
//         }
//         pid_int = atoi(pid);
//         // printf("%d",pid_int);
//         i+=1;
//         for(tmp=0;tmp<job_seq_no;tmp++)
//         {
//             // printf("%d\n",jobs[tmp].pid);
//             if(jobs[tmp].pid == pid_int)
//             {
//                 jobs[tmp].status = 0;
//                 // printf("%d",jobs[tmp].id);
//                 break;
//             }
//         }
//     }
//     fclose(file);
//     file = fopen("communicate.txt","w");
//     fclose(file);
// }

void child_killed()
{
    long long int i,j,exit_status;
    int status;
    long long int pid = waitpid(-1, &status, WNOHANG | WUNTRACED);
    if(pid > 0)
    {
        if (WIFEXITED(status))
        {	
            for(i=0;i<job_seq_no;i++)
            {
                if(jobs[i].pid == pid)
                {
                    exit_status = WEXITSTATUS(status);
                    if (exit_status != 0)
                    {
                        // printf("NORMAL");
                        printf("Process %s with pid %lld exited with exit status %lld\n", jobs[i].command, pid, exit_status);
                    }
                    else
                    {
                        printf("Process %s with pid %lld exited normally\n", jobs[i].command, pid);
                        // printf("STATUS");
                    }
                    jobs[i].status = 0;
                    printf("Press [ENTER] to continue\n ");
                }
            }

        }                                                       
    }
}
