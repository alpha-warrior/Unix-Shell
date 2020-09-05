#include "headers.h"

void ls(char * input_str, char * add_root)
{
    long long int i,j,k,len,flag_l = 0,flag_a = 0,num_dirs=0,curr_dir=0,cnt=0,blocks=0;
    char * token  = strtok(input_str, " "),dirs[100][1000],add_curr_dir[1000];
    struct dirent * file;
    struct stat info;
    struct passwd * passwd;
    struct group * grp;
    time_t now = time (NULL);
    struct tm timefl , timenow;
    char time_str[10000];
    DIR *DIR_dir;

    token = strtok(NULL, " ");

    while(token!=NULL)
    {
        if(token[0]=='-')
        {
            len = strlen(token);
            for(i=1;i<len;i++)
            {
                if(token[i]!='a' && token[i]!='l')
                {
                    printf("Flag not found : %c\n",token[i]);
                    return;
                }
                else
                {
                    if(token[i] == 'a')
                    {
                        flag_a = 1;
                    }
                    else if(token[i] == 'l')
                    {
                        flag_l = 1;
                    }
                }

            }
        }
        else
        {
            strcpy(dirs[num_dirs],token);
            num_dirs++; 
        }
        token = strtok(NULL," ");
    }

    if(num_dirs==0)
    {
        strcpy(dirs[num_dirs++],".");
    }

    for(curr_dir=0;curr_dir<num_dirs;curr_dir++)
    {
        if(dirs[curr_dir][0]=='~')
        {
            strcpy(add_curr_dir,add_root);
            j=strlen(add_root);
            len = strlen(dirs[curr_dir]);
            for(i=1;i<len;i++)
            {
                add_curr_dir[j++]=dirs[curr_dir][i];
            }
            add_curr_dir[j]='\0';
        }
        else
        {
            strcpy(add_curr_dir,dirs[curr_dir]);
        }

        // printf("%s\n",add_curr_dir);
        DIR_dir = opendir(add_curr_dir);
        if(num_dirs>1)
        {
            if(curr_dir >=1)
            {
                printf("\n\033[1;35m%s :\033[0m\n",dirs[curr_dir]);
            }
            else
            {
                printf("\033[1;35m%s :\033[0m\n",dirs[curr_dir]);
            }
        }
        if (DIR_dir==0)
        {
            printf("No such file or directory\n");
        }
        else
        {
            if(flag_l==0)
            {
                cnt=0;
                    while(file = readdir(DIR_dir))
                    {
                        char *name = file->d_name;
                        
                        if(flag_a==0)
                        {
                            if(name[0]!='.')
                            {
                                printf("%15s  ",name);
                                cnt++;
                            }
                        }
                        else
                        {
                            printf("%15s  ",name);
                            cnt++;
   
                        }

                        if(cnt%6==0 && cnt!=0)
                        {
                            printf("\n");
                        }
                    }
                    if(cnt%6!=0 && cnt!=0)
                    {
                    printf("\n");
                    }
            }
            else if(flag_l!=0)
            {
                blocks=0;
                    while(file = readdir(DIR_dir))
                    {
                        stat(file->d_name, &info);
                        char *name = file->d_name;
                        if(flag_a==0)
                        {
                            if(name[0] != '.')
                            {
                                blocks += info.st_blocks;
                            }
                        }
                        else
                        {
                            blocks += info.st_blocks; 
                        }
                    }
                    printf("total %lld\n",blocks/2);
                    closedir(DIR_dir);
                    DIR_dir = opendir(add_curr_dir);
                    while(file = readdir(DIR_dir))
                    {
                        // stat(file->d_name, &info);
                        // printf("\nNAME %s\n",file->d_name);
                        char *name = file->d_name;
                        char file_path_name[10000];
                        strcpy(file_path_name,add_curr_dir);
                        strcat(file_path_name,"/");
                        strcat(file_path_name,name);
                        // printf("\nNAME %s\n",file_path_name);
                        stat(file_path_name, &info);

                        localtime_r(&info.st_mtime, &timefl);
                        localtime_r(&now, &timenow);

                        if(timefl.tm_year != timenow.tm_year)
                        {
                            strftime(time_str, 10000 , "%b %e  %Y",&timefl);
                        }
                        else
                        {
                            strftime(time_str, 10000 , "%b %e %H:%M", &timefl);
                        }

                        if(flag_a==0 && name[0]=='.')
                        {
                            continue;
                        }
                        
                        passwd = getpwuid(info.st_uid);
                        grp = getgrgid(info.st_gid);
                        

                        if(S_ISDIR(info.st_mode)==1)
                            printf("d");
                        else
                            printf("-");

                        if((info.st_mode & S_IRUSR))
                            printf("r");
                        else
                            printf("-");

                        if((info.st_mode & S_IWUSR))
                            printf("w");
                        else
                            printf("-");

                        if((info.st_mode & S_IXUSR))
                            printf("x");
                        else
                            printf("-");

                        if((info.st_mode & S_IRGRP))
                            printf("r");
                        else
                            printf("-");

                        if((info.st_mode & S_IWGRP))
                            printf("w");
                        else
                            printf("-");

                        if((info.st_mode & S_IXGRP))
                            printf("x");
                        else
                            printf("-");

                        if((info.st_mode & S_IROTH))
                            printf("r");
                        else
                            printf("-");

                        if((info.st_mode & S_IWOTH))
                            printf("w");
                        else
                            printf("-");

                        if((info.st_mode & S_IXOTH))
                            printf("x ");
                        else
                            printf("- ");

                        printf("%ld ", info.st_nlink);
                        printf("%s ",passwd->pw_name);
                        printf("%s ",grp->gr_name);
                        printf("%10ld ", info.st_size);
                        printf("%s ",time_str);
                        printf("%s",name);
                        printf("\n");
                    }
            }
        closedir(DIR_dir);
        }
    }    
}