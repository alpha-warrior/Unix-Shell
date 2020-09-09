#include "headers.h"

void fetch_history()
{
    long long int i,j,k,flag;
    size_t len = 1000;
    char * history_datapoint;
    FILE *file;
    file = fopen("history.txt","r");
    if(!file)
    {
        printf("Error in history.txt");
        return;
    }
    i=0;
    for(;;)
    {
        flag=getline(&history_datapoint,&len,file);
        if(flag==-1)
        {
            break;
        }
        for(j=strlen(history_datapoint);j>=0;j--)
        {
            // printf("%c",history_datapoint[j]);
            if(history_datapoint[j]!=' ' && history_datapoint[j]!='\n')
            {
                break;
            }
        }
        // printf("%lld",j);
        history_datapoint[j]='\0';
        strcpy(history_data[i%20],history_datapoint);
        i+=1;
        // printf("%s",history_datapoint);
    }
    hist_len = i;
}

void add_history(char * input_str)
{
    long long int i,j,k;
    if(input_str[0]!=' ' && input_str[0]!='\n')
    {
        if(hist_len<20)
        {
            strcpy(history_data[hist_len],input_str);
            hist_len+=1;
        }
        else
        {
            for(i=0;i<19;i++)
            {
                strcpy(history_data[i],history_data[i+1]);
            }
            strcpy(history_data[i],input_str);
        }
    }
}

void history(char * input_str)
{
    long long int i,j,k,flag=0,start;
    int hist_count=10;
    char * history_datapoint;

    char * token = strtok(input_str," ");
    token = strtok(NULL," ");
    if(token == NULL)
    {
        hist_count=10;
    }
    else
    {
        hist_count = atoi(token);
    }

    if(hist_count>20)
    {
        hist_count=20;
    }
    
    if( hist_len-hist_count >= 0)
    {
        start = hist_len-hist_count;
    }
    else
    {
        start = 0;
    }
    for(j=start;j<20;j++)
    {
        printf("%s",history_data[j]);
    }
}

void save_history()
{
    long long int i,j,k,flag;
    size_t len = 1000;
    char * history_datapoint;
    FILE *file;
    file = fopen("history.txt","w");
    if(!file)
    {
        printf("Error in history.txt");
        return;
    }

    for(i=0;i<hist_len;i++)
    {
        fprintf(file,"%s",history_data[i]);
    }
    fclose(file);
}