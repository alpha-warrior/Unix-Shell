#include "headers.h"

void display(char *add_root)
{
    long long int i,j,k,len_root,len_curd;
    char add_curd[10000],add_display[10000],host[10000],* user;

    user = (char*)malloc(sizeof(char)*10000);

    getcwd(add_curd,10000);
    len_root = strlen(add_root);
    len_curd = strlen(add_curd);

    if(len_curd<len_root)
    {
        strcpy(add_display, add_curd);
    }
    else
    {
        // strcpy(add_display, "testing");
        for(i=0;i<len_root;i++)
        {
            if(add_curd[i]!=add_root[i])
            {
                strcpy(add_display,add_curd);
                break;
            }
        }

        if(i >= len_root)
        {
            add_display[0]='~';
            // add_display[1]='/';
            j=1;
            for(;i<len_curd;i++)
            {
                add_display[j++] = add_curd[i];
            }
            add_display[j]='\0';
        }
    }

    // printf("%s",add_display);

    user = getlogin();
    gethostname(host,10000);

    // printf("%s %s",user,host);

    printf("\033[1;31m%s@%s\033[0m:",user,host);
    printf("\033[1;34m%s\033[0m$ ",add_display);
}