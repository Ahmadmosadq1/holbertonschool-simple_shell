#include "main.h"
/**
 * print_numbers - Entry point
 * Description :prints number from 0 to 9 using _putchar
 *.
 * Return: void.
 */

int main(int argc, char **argv, char **environ)
{
	int status;
	size_t len = 0;
	ssize_t user_input;
	char *line = NULL;
	pid_t pid;
	char *line_cpy;
	char *arguments[2];

	(void)argc;
	(void)argv;
	while (1) /*making an infinte loop for our shell*/
	{
		if (isatty(STDIN_FILENO))
			printf("$ "); /*printing our prompt symbol1*/
		
		user_input = getline(&line, &len,stdin);/*reading command lines form the user*/
		if (user_input == -1)
		{
	printf("\n");
	break;
}
line_cpy = _strncpy(line);/*using strencpy to eleminate \n*/
if (line_cpy[0] == '\0')
{
	free(line_cpy);
	continue;
}
pid = fork();
if (pid == -1)
{
	perror("fork");
	free(line_cpy);
	exit(EXIT_FAILURE);
}
if (pid == 0)
{
	arguments[0] = line_cpy;
	arguments[1] = NULL;
	printf("Running: %s\n", line_cpy);
	execve(line_cpy, arguments, environ);
	perror("execvp");
    exit(EXIT_FAILURE);
}
if (pid > 0)
{
	wait(&status);
	free(line_cpy);
}
}
free(line);
return (0);
}
