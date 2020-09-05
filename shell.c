# include "headers.h"

int main(int argc, char * argv[])
{
    long long int i,j,k,pid;
    int status;
    char add_curd[10000],add_root[10000];

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

    chdir(add_curd);
    for(;;)
    {
        pid = waitpid(-1, &status, WNOHANG | WUNTRACED);
        if(pid > 0)
            {
                if (WIFEXITED(status))
                {	
                    printf("pid: %lld exited normally\n",pid);	
                }
                                    
            }

        signal(SIGINT, SIG_IGN);
        display(add_root);
        input(add_root);
    }
}