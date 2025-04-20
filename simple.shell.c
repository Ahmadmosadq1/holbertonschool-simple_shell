
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
	int index;
	size_t len = 0;
	ssize_t user_input;
	char *line = NULL;
	pid_t pid;
	char *line_cpy;
	char *arguments[MAX_ARGS];
	char *clean;
	char *command_token;
	char *Path;
	char *Path_token;
	char *Path_str;
	char *Path_copy;

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
		{
			exit(EXIT_FAILURE);
		}
		strncpy(line_cpy, clean, strlen(clean) + 1);
		free(clean);
		if (line_cpy[0] == '\0')
		{
			free(line_cpy);
			free(line);
			continue;
		}
		Path_str = get_path(environ);

	if (!Path_str)
	{
    	perror("PATH not found");
    	exit(EXIT_FAILURE);
		}
	 
                        index = 0;
                        command_token = strtok(line_cpy, " ");
                        while (command_token != NULL)
                        {
                                arguments[index++] = command_token;
                                command_token = strtok(NULL, " ");
                        }
                        arguments[index] = NULL;
		Path_copy = strdup(Path_str);
		Path_token = NULL;
		Path = strtok(Path_copy, ":"); 
		while (Path)
		{
			Path_token = malloc(strlen(Path) + strlen(arguments[0]) + 2);
			if (Path_token == NULL)
			{
				exit(EXIT_FAILURE);
			}
			sprintf(Path_token, "%s/%s", Path, arguments[0]);
			 if (access(Path_token, X_OK) == 0)
				 break;
			 Path = strtok(NULL, ":");
			 free(Path_token);
		}
		if (Path_token == NULL)
                         {
                                 perror("command :");
                                 continue;
                         }
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (execve(Path_token, arguments, environ) == -1)
                        {
                        perror("execvp");
                        exit(EXIT_FAILURE);
                        }
			
		}
		if (pid > 0)
		{
			wait(&status);
		}
	}
	return (0);
}

