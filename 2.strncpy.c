#include <stdlib.h>
#include <stdio.h>

/**
 * _strncpy - Creates a copy of a string and removes trailing newline
 * @line: The original string to copy
 *
 * Return: A newly allocated copy of the string (without newline)
 */
char *_strncpy(char *line)
{
	int counter = 0;
	char *line_cpy;

	if (line == NULL)
		return (NULL);

	while (line[counter])
		counter++;

	line_cpy = malloc(sizeof(char) * (counter + 1));
	if (line_cpy == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	counter = 0;
	while (line[counter] && line[counter] != '\n')
	{
		line_cpy[counter] = line[counter];
		counter++;
	}

	line_cpy[counter] = '\0';
	return (line_cpy);
}

