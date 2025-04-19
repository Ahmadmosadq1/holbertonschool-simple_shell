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
	int index = 0;
	size_t len = 0;
	ssize_t user_input;
	char *line = NULL;
	pid_t pid;
	char *line_cpy;
	char *arguments[MAX_ARGS];
	char *clean;
	char *token;
	char *Path;
	char *Path_token;
	char *Path_str;

	(void)argc;
	(void)argv;
	while (1) /*making an infinte loop for our shell*/
	{
		if (isatty(STDIN_FILENO))
			printf("$ "); /*printing our prompt symbol1*/
		/*reading command lines form the user*/
		user_input = getline(&line, &len, stdin);
		if (user_input == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}
		clean = trim_spaces(line);
		line_cpy = malloc(sizeof(char) * strlen(clean) + 1);
		if (line_cpy == NULL)
			return (-1);
		strncpy(line_cpy, clean, strlen(clean) + 1);
		free(clean);
		if (line_cpy[0] == '\0')
		{
			free(line_cpy);
			continue;
		}
		Path_str = getenv("PATH");
		Path_token = strtok(Path_str, ":");
		while (Path)
		{
			Path_token = malloc(strlen(Path) + strlen(line_cpy) + 2);
			if (Path_token == NULL)
				return (-1);
			sprintf(Path_token, "%s/%s", Path, line_cpy);
			 if (access(Path_token, X_OK) == 0)
				 break;
			 free(Path_token);
			 Path = strtok("NULL", ":");
		}
		if (Path_token == NULL)
                         {
                                 perror("command :");
                                 return (-1);
                         }
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			free(Path_token);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			token = strtok(line_cpy, " ");
			while (token != NULL)
			{
				arguments[index++] = token;
				token = strtok(NULL, " ");
			}
			arguments[index] = NULL;
			execve(Path_token, arguments, environ);
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
