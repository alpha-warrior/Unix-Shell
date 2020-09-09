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

### Fuctioning
* cd <path to new directory> - Changes directory to the given path. Changes to shell home if no directory is provided
* pwd - Shows the absolute path of the current working directory 
* echo <message> - Prints the <message> to the terminal
* ls -[al] <path to directory1> <path to directory2> - lists all files of the given directory(s) with respcet to mentioned flags
* pinfo [pid] - Prints process related info (pid, Process Status {R, S, S+, Z}, memory and Executable Path) about given pid. Prints process related info of shell program if no pid is provided.
* history [n]  - Prints history of n (max 20) commands. Default n = 10.
* Any process can be moved to Background by adding '&' in the command.
### How to run :-
```
foo@bar:~$ make
foo@bar:~$ ./a.out
```