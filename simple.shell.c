#include "main.h"

/**
 * main - Entry point for the simple shell program.
 * @argc: Number of command line arguments.
 * @argv: Array of command line arguments.
 * @environ: Array of environment variables.
 * Return: 0 on success, exit status on failure.
 */
int main(int argc, char **argv, char **environ)
{
<<<<<<< HEAD
	char *line = NULL, *clean, *line_cpy = NULL, *arg_cpy = NULL;
	char *Path_str = NULL, *Path_copy = NULL, *Path_token = NULL;
	char *Path = NULL, *cmd = NULL, *token = NULL;
	char *arguments[MAX_ARGS];
	pid_t pid;
	int status, index, valid_cmd = 0;
	size_t len = 0;
	ssize_t user_input;
=======
    char *line = NULL, *clean, *line_cpy = NULL, *arg_cpy = NULL;
    char *path_str, *path_copy, *path_token = NULL, *path, *cmd, *token;
    char *arguments[MAX_ARGS];
    pid_t pid;
    int status, index;
    size_t len = 0;
    ssize_t user_input;
>>>>>>> 626546db9c30d47ab19db54ae9c2e7c13c788da3

    (void)argc;
    (void)argv;

<<<<<<< HEAD
	while (1)
	{
		valid_cmd = 0;
		if (isatty(STDIN_FILENO))
			printf("$ ");
		user_input = getline(&line, &len, stdin);
		if (user_input == -1)
			break;
=======
    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf("$ ");
>>>>>>> 626546db9c30d47ab19db54ae9c2e7c13c788da3

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

<<<<<<< HEAD
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
=======
        if (!line_cpy || !arg_cpy)
        {
            free(line_cpy);
            free(arg_cpy);
            continue;
        }

        cmd = strtok(arg_cpy, " ");

        /* Absolute or relative path */
        if (cmd[0] == '/' || cmd[0] == '.')
        {
            if (access(cmd, X_OK) != 0)
            {
                perror("command");
                free(line_cpy);
                free(arg_cpy);
                continue;
            }
            path_token = strdup(cmd);
        }
        else
        {
            path_str = get_path(environ);
            if (!path_str || path_str[0] == '\0')
            {
                /* If PATH is not found, use the command with its full path */
                if (access(cmd, X_OK) == 0)
                {
                    path_token = strdup(cmd);
                }
                else
                {
                    perror("command");
                    free(line_cpy);
                    free(arg_cpy);
                    continue;
                }
            }
            else
            {
                path_copy = strdup(path_str);
                if (!path_copy)
                {
                    free(line_cpy);
                    free(arg_cpy);
                    continue;
                }

                path = strtok(path_copy, ":");
                while (path)
                {
                    path_token = malloc(strlen(path) + strlen(cmd) + 2);
                    if (!path_token)
                        break;
                    sprintf(path_token, "%s/%s", path, cmd);
                    if (access(path_token, X_OK) == 0)
                        break;
                    free(path_token);
                    path_token = NULL;
                    path = strtok(NULL, ":");
                }
                free(path_copy);
                if (!path_token)
                {
                    perror("command");
                    free(line_cpy);
                    free(arg_cpy);
                    continue;
                }
            }
        }

        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            free(path_token);
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

            if (execve(path_token, arguments, environ) == -1)
            {
                perror("execve");
                free(path_token);
                free(line_cpy);
                free(arg_cpy);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(&status);
            free(path_token);
            free(line_cpy);
            free(arg_cpy);
        }
    }
    free(line);
    return (0);
>>>>>>> 626546db9c30d47ab19db54ae9c2e7c13c788da3
}
