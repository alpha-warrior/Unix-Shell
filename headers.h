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

struct job
{
    int pid;
    char command[100];
    int status;
    int id;
};

struct job jobs[1000];
int job_seq_no;
struct job foreground_job;
char lwd[10000];

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
extern void command_selector();
extern char * trim();
extern void redirection();
extern void piping();
extern void setenvi();
extern void unsetenvi();
extern void jobs_func();
// extern void check_job_stat();
extern void kjob();
extern void child_killed();
extern void fg();
extern void bg();
extern void overkill();
extern void signal_control();