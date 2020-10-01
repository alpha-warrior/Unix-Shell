 ### UNIX - SHELL
 **Akshit Garg**
 **2018113006**

### Files
* headers.h     - contains all the required headers and functions
* shell.c - contains the main functioning of the shell managing different functions.
* display.c - displays prompt to user
* input.c - parses the input and execute the suitable command
* pwd.c - function to implement pwd command
* cd.c - function to implement cd command
* echo.c - function to implement echo command
* ls.c - function to implement ls -[la] command
* pinfo.c - function to implement pinfo command
* sys_cmd.c - fucntion to implement foreground and background processing of system commands
* history.c - functions to implement the history command
* piping.c - handles piping
* redirection.c - handles redirections
* setenv.c - sentenv command to set environment variable 
* unsetenv.c - unsetenv command to unset environment variable
* jobs.c - job command to list active jobs
* kjob.c - kjob command to kill a job
* fg.c - fg command to bring background process to foreground
* bg.c - bg command to run stopped background process
* overkill.c - overkill command to kill all background processes
* signal_control.c - Signal Handeling
* utility.c - contains all the utility functions


### Fuctioning
* cd <path to new directory> - Changes directory to the given path. Changes to shell home if no directory is provided
* pwd - Shows the absolute path of the current working directory 
* echo <message> - Prints the <message> to the terminal
* ls -[al] <path to directory1> <path to directory2> - lists all files of the given directory(s) with respcet to mentioned flags
* pinfo [pid] - Prints process related info (pid, Process Status {R, S, S+, Z}, memory and Executable Path) about given pid. Prints process related info of shell program if no pid is provided.
* history [n]  - Prints history of n (max 20) commands. Default n = 10.
* setenv <var> <value> - creates/changes the environment variable "var" and sets its value to "value"
* unsetenv var - unsets the value of the environment variable "var"
* jobs - prints a list of all currently running jobs along with their job ids , pid, in particular, background jobs, in order of their creation along with their state – Running or Stopped.
* ​kjob <jobNumber> <signalNumber> - takes the job id of a running job and sends a signal value to that process
* ​fg <jobNumber> ​- brings a running or a stopped background job with given job number to foreground
* ​bg <jobNumber> ​- changes a stopped background job to a running background
* ​overkill - kills all background process at once
* quit/q/exit - exits the shell
* CTRL-Z - changes the status of currently running job to stop, and push it to background. If there is no foreground job, then the signal has no effect.
* CTRL-C - causes a SIGINT signal to be sent to the current foreground job of the shell​. If there is no foreground job, then the signal has no effect.
* CTRL-D - exits the shell
* Any process can be run to Background by adding '&' in the command.
* cd can handle [~ .  .. -] special symbols. 
* $'cd -' takes user to last working directory.
* ls can handle [~ . ..] special symbols.


### How to run :-
```
foo@bar:~$ make
foo@bar:~$ ./shell
```
