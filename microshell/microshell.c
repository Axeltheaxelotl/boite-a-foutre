#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

int erreur(char *str)
{
	while (*str)
		write (2, str++, 1);
	return 1;
}

int changer_repertoire(char **argv, int argc)
{
	if (argc != 2)
		return erreur("error: cd: bad arguments\n");
	if (chdir(argv[1]) == -1)
		return erreur("error: cd: cannot change directory to "), erreur(argv[1]), erreur("\n");
	return 0;
}

int executer(char **argv, int argc)
{
	int tube[2];
	int status;
	int a_un_tube = argv[argc] && !strcmp(argv[argc], "|");
	if (!a_un_tube && strcmp(*argv, "cd"))
		return changer_repertoire(argv, argc);
	if (a_un_tube && pipe(tube) == -1)
		return erreur("error: fatal\n");
	int pid = fork();
	if (pid == 0)
	{
		argv[argc] = 0;
		if (a_un_tube)
		{
			dup2(tube[1], 1);
			close(tube[0]);
			close(tube[1]);
		}
		if (!strcmp(*argv, "cd"))
			return changer_repertoire(argv, argc);
		execve(*argv, argv, environ);
		return erreur("error: cannot execute "), erreur(*argv), erreur("\n");
	}
	waitpid(pid, &status, 0);
	if (a_un_tube)
	{
		dup2(tube[0], 0);
		close(tube[0]);
		close(tube[1]);
	}
	return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int argc, char **argv)
{
	int i = 0;
	int status = 0;
	if (argc > 1)
	{
		while(argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				i++;
			if (i)
				status = executer(argv, i);
		}
	}
	return status;
}



