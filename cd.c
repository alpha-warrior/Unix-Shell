#include "headers.h"

void cd(char * input_str, char * add_root)
{
    long long int i,j,k,len,status;
    char new_dir[10000];
    // printf("cdcdcd\n");
    len = strlen(input_str);
    for(i=2;i<len;i++)
    {
        if(input_str[i]!=' ')
        {
            break;
        }
    }
    if(input_str[i]=='~')
    {
        i++;
        strcpy(new_dir,add_root);
        j=strlen(add_root);
        // new_dir[j++]='/';
        for(;i<len;i++)
        {
            if(input_str[i]==' ')
            {
                printf("too many arguments\n");
                return;
            }
            else
            {
                new_dir[j++]=input_str[i];
            }
        }
        new_dir[j]='\0';
    }
    else
    {
        j=0;
        for(;i<len;i++)
        {
            if(input_str[i]==' ')
            {
                printf("too many arguments\n");
                return;
            }
            else
            {
                new_dir[j++]=input_str[i];
            }
        }
        new_dir[j]='\0';
    }
    // printf("%s",new_dir);
    status=chdir(new_dir);

    if(status==-1)
    {
        printf("No such file or directry\n");
    }
}