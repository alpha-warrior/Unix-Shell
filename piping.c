#include "headers.h"

void piping(char * input_str,char * add_root)
{
    long long int i,j,k,token_cnt=0,token_no,status,pid;
    int stat;
    char * trimmed_str,temp[10000];
    strcpy(temp,input_str);
    char *  token = strtok(temp,"|");
    while(token!=NULL)
    {
        token_cnt++;
        token = strtok(NULL,"|");
    }
    // printf("%lld",token_cnt);
    if(token_cnt==0)
    {
        return;
    }
    else if(token_cnt==1)
    {
        trimmed_str = trim(input_str);
        redirection(trimmed_str,add_root);
    }
    else
    {
        int p[2],in = dup(0),out = dup(1);
        token_no = 0;
        token = strtok(input_str,"|");
        // printf("%s",token);
        while(token!=NULL)
        {
            // printf("\nPIPINGINGIN %s\n%lld",token,token_no);
            if(token_no > 0)
            {
                status = dup2(p[0],0);
                if(status<0)
                {
					fprintf(stderr, "failure of dup2\n");
                }
                close(p[0]);
            }
            
            if(token_no < token_cnt -1)
            {
                pipe(p);
                status = dup2(p[1],1);
                if(status<0)
                {
					fprintf(stderr, "failure of dup2\n");
                }
                close(p[1]);
            }

            trimmed_str = trim(token);
            pid = fork();

            if(pid > 0)
            {
                waitpid(pid,&stat,WUNTRACED);
                dup2(in,0);
                dup2(out,1);
            }
            else if(pid == 0 )
            {
                redirection(trimmed_str,add_root);
                exit(0);
            }
            else
            {
				perror("Forking ERROR\n");
                dup2(in,0);
                dup2(out,1);
                return;
            }
            token = strtok(NULL,"|");
            token_no++;
        }
    }
}