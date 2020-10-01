# include "headers.h"

int main(int argc, char * argv[])
{
    long long int i,j,k,pid;
    int status;
    char add_curd[10000],add_root[10000],cmd[100];
    
    // pid_data[2].id = 21;
    getcwd(add_curd,10000);
    // printf("%s\n",add_curd);
    // printf("%ld",strlen(add_curd));

    for(i=strlen(argv[0])-1;i>=0;i--)
    {
        if(argv[0][i] == '/')
        {
            break;
        }
    }
    argv[0][i]='\0';
    // printf("%s\n",argv[0]);

    chdir(argv[0]);

    getcwd(add_root,10000);
    // printf("%s",add_root);

    fetch_history();
    chdir(add_curd);
    strcpy(lwd,add_root);
    for(;;)
    {
        signal(SIGCHLD, child_killed);
        // printf("WORKING SHELL");
        display(add_root);
        signal(SIGINT, signal_control);
        signal(SIGTSTP, signal_control);
        input(add_root);

        // check_job_stat();

    }
}