#include "main.h"

int main(int argc, char **argv, char **environ)
{
	char *line = NULL, *clean, *line_cpy = NULL, *arg_cpy = NULL;
	char *Path_str, *Path_copy, *Path_token = NULL, *Path, *cmd, *token;
	char *arguments[MAX_ARGS];
	pid_t pid;
	int status, index;
	size_t len = 0;
	ssize_t user_input;

	(void)argc;
	(void)argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		user_input = getline(&line, &len, stdin);
		if (user_input == -1)
			break;

		clean = trim_spaces(line);
		if (!clean || clean[0] == '\0')
		{
			free(clean);
			continue;
		}

		arg_cpy = strdup(clean);
		line_cpy = strdup(clean);
		free(clean);
		if (!line_cpy || !arg_cpy)
		{
			free(line_cpy);
			free(arg_cpy);
			continue;
		}

		Path_str = get_path(environ);
		if (!Path_str)
		{
			perror("PATH not found");
			free(line_cpy);
			free(arg_cpy);
			exit(1);
		}
		Path_copy = strdup(Path_str);
		if (!Path_copy)
		{
			free(line_cpy);
			free(arg_cpy);
			continue;
		}

		cmd = strtok(arg_cpy, " ");
		Path = strtok(Path_copy, ":");
		while (Path)
		{
			Path_token = malloc(strlen(Path) + strlen(cmd) + 2);
			if (!Path_token)
				break;
			sprintf(Path_token, "%s/%s", Path, cmd);
			if (access(Path_token, X_OK) == 0)
				break;
			free(Path_token);
			Path_token = NULL;
			Path = strtok(NULL, ":");
		}
		if (!Path_token && access(cmd, X_OK) == 0)
			Path_token = strdup(cmd);
		if (!Path_token)
		{
			perror("command");
			free(Path_copy);
			free(line_cpy);
			free(arg_cpy);
			continue;
		}

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			free(Path_token);
			free(Path_copy);
			free(line_cpy);
			free(arg_cpy);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			index = 0;
			token = strtok(line_cpy, " ");
			while (token)
				arguments[index++] = token, token = strtok(NULL, " ");
			arguments[index] = NULL;
			if (execve(Path_token, arguments, environ) == -1)
			{
				perror("execve");
				free(line_cpy);
				free(Path_token);
				free(Path_copy);
				free(arg_cpy);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			free(line_cpy);
			free(arg_cpy);
			free(Path_token);
			free(Path_copy);
		}
	}
	free(line);
	return (0);
}

