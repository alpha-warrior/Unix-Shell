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

    chdir(add_curd);
    for(;;)
    {
        signal(SIGINT, SIG_IGN);
        display(add_root);
        input(add_root);
    }
}