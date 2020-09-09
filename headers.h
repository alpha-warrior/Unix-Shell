#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

struct pid_datapoint
{
    int id;
    char cmd[100];
};

char history_data[20][1000];
int hist_len;
extern void pinfo();
extern void display();
extern void input();
extern void echo();
extern void cd();
extern void pwd();
extern void ls();
extern void sys_cmd();
extern void add_history();
extern void history();
extern void fetch_history();
extern void save_history();