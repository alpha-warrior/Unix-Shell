#include "headers.h"

void pinfo(char * input_str, char * add_root)
{
    long long int i,j,k,len,pid,cnt,fd;
    char pid_str[10000],path_stat[10000]="/proc/",path_exe[10000]="/proc/",buffer[100000],status[10000],memory[10000],print_path[10000];
    len=strlen(input_str);
    char * token = strtok(input_str," ");
    token = strtok(NULL," ");
    cnt=0;
    while(token!=NULL)
    {
        cnt++;
        // printf("%s",token);
        if(cnt==1)
        {
            strcpy(pid_str,token);
        }
        else
        {
            printf("Too many arguments\n");
            return;
        }
        token = strtok(NULL," ");
    }
    if(cnt==0)
    {
        pid = getpid();
        sprintf(pid_str,"%lld",pid);
    }
    strcat(path_exe,pid_str);
    strcat(path_exe,"/exe");
    strcat(path_stat,pid_str);
    strcat(path_stat,"/stat");

    fd = open(path_stat,O_RDONLY);
    read(fd, buffer, 10000);

    if(fd>0)
    {
        token = strtok(buffer," ");
        cnt = 0;
        while(token!=NULL)
        {
            // printf("%lld",cnt);
            if(cnt==2)
            {
                strcpy(status,token);
                // printf("stst %s",token);
            }
            else if(cnt==22)
            {
                strcpy(memory,token);
                // printf("mem %s",token);
            }
            cnt++;
            token = strtok(NULL," ");
        }
    char real_path[10000];
    realpath(path_exe,real_path);
    // printf("%s %s",path_exe,real_path);
    len = strlen(add_root);
    for(i=0;i<len;i++)
    {
        if(real_path[i]!=add_root[i])
        {
            break;
        }
    }

    if(i!=len)
    {
        strcpy(print_path,real_path);
    }
    else
    {
        print_path[0]='~';
        j=1;
        for(;i<strlen(real_path);i++)
        {
            print_path[j++]=real_path[i];
        }
        print_path[j]='\0';
    }

    printf("pid -- %s\n",pid_str);
    printf("Process Status -- {%s}\n",status);
    printf("memory ​ -- %s\n",memory);
    printf("Executable Path -- %s\n",print_path);
    }
    else
    {
        printf("Error: could not open info file \n");
    }
}