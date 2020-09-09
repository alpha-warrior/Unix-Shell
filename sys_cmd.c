#include "headers.h"

void sys_cmd(char * input_str)
{
    long long int i,j,k,cnt,flag_and=0,child_pid,exe_stat,child_child_pid,pid;
    int status;
    char * command[1000];
    char * arg_list[1000];
    char cmd[1000];


    for(i=0;i<1000;i++)
    {
        arg_list[i] = (char*)malloc(sizeof(char)*1000);
    }

    char * token = strtok(input_str, " ");
    cnt=0;
    while (token!=NULL)
    {
        if(strcmp(token,"&")!=0)
        {
            arg_list[cnt]=token;
            cnt++;
        }
        else
        {
            flag_and=1;
        }
        token = strtok(NULL," ");
    }
    // command = arg_list[0];
    arg_list[cnt] = NULL;

    // for(i=0;i<cnt;i++)
    // {
    //     printf("%s\n",arg_list[i]);
    // }

    child_pid = fork();
    if(child_pid<0)
    {
        perror("ERROR");
        return;
    }
    
    if(child_pid==0)
    {
        if(flag_and==0)
        {
            exe_stat = execvp(arg_list[0],arg_list);
            if(exe_stat==-1)
            {
                printf("Please enter a Valid Command\n");
            }
            exit(0);
        }
        else
        {
            child_child_pid = fork();
            if(child_child_pid==0)
            {
                exe_stat = execvp(arg_list[0],arg_list);
                if(exe_stat==-1)
                {
                    printf("Please enter a Valid Command\n");
                }
                exit(0);      
            }
            else
            {
                for(;;)
                {
                    pid = waitpid(-1, &status, WNOHANG | WUNTRACED);
                    if(pid > 0)
                    {
                        if (WIFEXITED(status))
                        {	

                            printf("\n%s with pid %lld exited normally\n",arg_list[0],pid);	
                        }
                                            
                    }
                }
            }
        }
    }
    
    if(child_pid>0)
    {
        if(flag_and==0)
        {
            waitpid(child_pid,&status, WUNTRACED);
        }
        else
        {
            printf("%s with process pid %lld started\n",arg_list[0],child_pid);
        }
    }
}