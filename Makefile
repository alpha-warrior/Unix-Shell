all:
	gcc headers.h shell.c display.c input.c echo.c cd.c pwd.c ls.c pinfo.c sys_cmd.c history.c utility.c redirection.c piping.c setenv.c unsetenv.c jobs.c kjob.c fg.c bg.c overkill.c signal_control.c -o shell
compile: