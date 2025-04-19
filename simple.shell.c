#include "main.h"

int main(int argc, char **argv, char **environ)
{
	char *line = NULL, *clean, *line_cpy = NULL, *arg_cpy = NULL;
	char *Path_str = NULL, *Path_copy = NULL, *Path_token = NULL;
	char *Path = NULL, *cmd = NULL, *token = NULL;
	char *arguments[MAX_ARGS];
	pid_t pid;
	int status, index, valid_cmd = 0;
	size_t len = 0;
	ssize_t user_input;

	(void)argc;
	(void)argv;

	while (1)
	{
		valid_cmd = 0;
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

		cmd = strtok(arg_cpy, " ");
		if (!cmd)
		{
			free(line_cpy);
			free(arg_cpy);
			continue;
		}

		/* Absolute or relative path */
		if (cmd[0] == '/' || cmd[0] == '.')
		{
			if (access(cmd, X_OK) == 0)
			{
				Path_token = strdup(cmd);
				valid_cmd = 1;
			}
		}
		else
		{
			Path_str = get_path(environ);
			if (Path_str && Path_str[0] != '\0')
			{
				Path_copy = strdup(Path_str);
				if (!Path_copy)
				{
					free(line_cpy);
					free(arg_cpy);
					continue;
				}
				Path = strtok(Path_copy, ":");
				while (Path)
				{
					Path_token = malloc(strlen(Path) + strlen(cmd) + 2);
					if (!Path_token)
						break;
					sprintf(Path_token, "%s/%s", Path, cmd);
					if (access(Path_token, X_OK) == 0)
					{
						valid_cmd = 1;
						break;
					}
					free(Path_token);
					Path_token = NULL;
					Path = strtok(NULL, ":");
				}
				free(Path_copy);
			}
			if (!valid_cmd && access(cmd, X_OK) == 0)
			{
				Path_token = strdup(cmd);
				valid_cmd = 1;
			}
		}

		if (!valid_cmd)
		{
			perror("command");
			free(line_cpy);
			free(arg_cpy);
			continue;
		}

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			free(Path_token);
			free(line_cpy);
			free(arg_cpy);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			index = 0;
			token = strtok(line_cpy, " ");
			while (token)
			{
				arguments[index++] = token;
				token = strtok(NULL, " ");
			}
			arguments[index] = NULL;
			if (execve(Path_token, arguments, environ ? environ : NULL) == -1)
			{
				perror("execve");
				free(Path_token);
				free(line_cpy);
				free(arg_cpy);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			free(Path_token);
			free(line_cpy);
			free(arg_cpy);
		}
	}
	free(line);
	return (0);
}

