#include "headers.h"

void cd(char * input_str, char * add_root)
{
    long long int i,j,k,len,status;
    char new_dir[10000],temp[10000];
    // printf("INPUT STR %s\n",input_str);
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
    else if(input_str[i]=='-')
    {
        j=0;
        i++;
        for(;i<len;i++)
        {
            if(input_str[i]!=' ')
            {
                printf("too many arguments\n");
                return;
            }
        }

        strcpy(new_dir,lwd);
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
    // printf("directory: %s\n",new_dir);
    getcwd(temp,10000);
    status=chdir(new_dir);

    if(status==-1)
    {
        printf("No such file or directry\n");
    }
    else
    {
        strcpy(lwd,temp);
    }
}