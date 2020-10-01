#include "headers.h"
void input(char *add_root)
{
    // printf("WORKING INPUUT %d",job_seq_no);
    long long int i,j,k,t,cnt_token,len;
    char *input_str, tokens[100][10000],trimmed_str[10000],command[10000];

    input_str = (char*)malloc(sizeof(char)*10000);
    size_t size = 10000;

    // getline(&input_str,&size,stdin);
    // printf("WOKINg getline %s", input_str); 
    if(fgets(input_str,10000,stdin)==NULL)
    {
        printf("\n");
        exit(0);
    }
    add_history(input_str);
    // printf("add_history");
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
        piping(tokens[t],add_root);
    }
}