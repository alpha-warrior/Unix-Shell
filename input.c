#include "headers.h"
void input(char *add_root,struct pid_datapoint pid_data[])
{
    long long int i,j,k,t,cnt_token,len;
    char *input_str, tokens[100][10000],trimmed_str[10000],command[10000];

    input_str = (char*)malloc(sizeof(char)*10000);
    size_t size = 10000;

    getline(&input_str,&size,stdin);
    // printf("%s", input_str); 
    char * token = strtok(input_str, ";");
    cnt_token=0;
    while(token!=NULL)
    {

        for(j=strlen(token)-1;j>=0;j--)
        {
            if(token[j]!='\n'  && token[j]!=' ')
            {
                break;
            }
        }
        len = strlen(token);
        for(i=0;i<len;i++)
        {
            if(token[i]!=' ')
            {
                break;
            }
        }

        if(j!=-1)
        {     
            k=0;
            for(;i<=j;i++)
            {
                tokens[cnt_token][k++]=token[i];     
            }
            tokens[cnt_token][k]='\0';
            cnt_token++;
        // strcpy(tokens[cnt_token++],token);
        }
        token=strtok(NULL, ";");
        // printf("\n%s\n",tokens[i-1]);
    }

   
    // for(i=0;i<cnt_token;i++)
    // {
    //     printf("\n%s\n",tokens[i]);
    // }

    for(t=0;t<cnt_token;t++)
    {
        len=strlen(tokens[t]);
        for(i=0;tokens[t][i]!=' ' && i < len ;i++)
        {
            command[i]=tokens[t][i];
        }
        command[i]='\0';
        // printf("%s",command);
        if(strcmp(command,"echo")==0)
        {
            echo(tokens[t]);
        }
        else if(strcmp(command,"cd")==0)
        {
            cd(tokens[t],add_root);
        }
        else if(strcmp(command,"pwd")==0)
        {
            pwd();
        }
        else if(strcmp(command,"ls")==0)
        {
            ls(tokens[t],add_root);
        }
        else if(strcmp(command,"pinfo")==0)
        {
            pinfo(tokens[t],add_root);
        }
        else if(strcmp(command,"quit")==0 || strcmp(command,"q")==0 || strcmp(command,"exit")==0)
        {
            exit(1);
        }
        else
        {
            sys_cmd(tokens[t],pid_data);
        }
    }
}