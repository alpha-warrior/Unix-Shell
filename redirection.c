#include "headers.h"

void redirection(char * input_str, char * add_root)
{
    long long int i,j,k,r_flag=0,w_flag=0,len,a_flag=0,temp_var;
    len = strlen(input_str);
    char command[1000], temp[1000], read_file[1000]="\0", write_file[1000]="\0";

    char * token;
	struct stat info;
    int fd_read,fd_write;

    for(i=0;i<len;i++)
    {
        if(input_str[i]=='<')
        {
            r_flag=1;
        }
        if(input_str[i]=='>')
        {
            if(input_str[i+1]=='>')
            {
                a_flag=1;
            }
            else
            {
                w_flag=1;
            }
        }
    }

    if(r_flag==0 && w_flag==0 && a_flag==0)
    {
        command_selector(input_str,add_root);
    }
    else
    {
		int in = dup(0) , out =  dup(1);
        for(i=0;input_str[i]!='<' && input_str[i]!='>';i++)
        {
            command[i] = input_str[i];
        }
        for(;i>0;i--)
        {
            if(command[i]!=' ')
                break;
        }
        command[i+1]='\0';

        if(r_flag!=0)
        {
            strcpy(temp,input_str);
            token = strtok(temp," ");
            while(token!=NULL)
            {
                if(strcmp(token,"<")==0)
                {
                    token = strtok(NULL," ");
                    if(token!=NULL)
                        strcpy(read_file,token);
                    break;
                }

                token = strtok(NULL," ");
            }

            if(stat(read_file, &info) < 0)
            {
                fprintf(stderr, "file does not exist\n");
                return;	
            }
            else
            {
                fd_read = open(read_file , O_RDONLY);
                if(fd_read < 0)
                {
                    fprintf(stderr, "Error while opening the file\n");
                    return;
                }
                temp_var = dup2(fd_read, 0);
                if (temp_var < 0)
                {	
                    fprintf(stderr, "Failure of dup2\n");
                }
                close(fd_read);
            }

        }
        if(w_flag!=0)
        {
            strcpy(temp,input_str);
            token = strtok(temp," ");
            while(token!=NULL)
            {
                if(strcmp(token,">")==0 || strcmp(token,">>")==0)
                {
                    token = strtok(NULL," ");
                    if(token!=NULL)
                        strcpy(write_file,token);
                    break;
                }
                token = strtok(NULL," ");
               
            }

            if(a_flag!=0)
                fd_write = open(write_file, O_WRONLY|O_APPEND|O_CREAT, 0644);
            else
                fd_write = open(write_file, O_WRONLY|O_TRUNC|O_CREAT, 0644);

            if(fd_write < 0)
            {
                fprintf(stderr, "Error while opening the file\n");
                return;
            }
            if (dup2(fd_write, 1) < 0)
            {	
                fprintf(stderr, "Failure of dup2\n");
            }
            close(fd_write);

        }
        // printf("cmd:%s \nread:%s \nwrite:%s \n",command,read_file,write_file);
        command_selector(command,add_root);
        dup2(in , 0);
		dup2(out , 1);
		close(in);
		close(out);
    }
}