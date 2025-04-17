#include <stddef.h>
#include <stdlib.h>

char *trim_spaces(char *str)
{
	int start = 0, end, len;
	char *new;
	int i;

	if (!str)
		return (NULL);

	/* Skip leading spaces/tabs */
	while (str[start] == ' ' || str[start] == '\t')
		start++;

	/* Count characters from start until newline */
	len = 0;
	while (str[start + len] && str[start + len] != '\n')
		len++;

	/* Move 'end' backward to skip trailing spaces */
	end = len - 1;
	while (end >= 0 && (str[start + end] == ' ' || str[start + end] == '\t'))
		end--;

	/* Allocate space for trimmed string + \0 */
	new = malloc(end + 2);
	if (!new)
		return (NULL);

	/* Copy only trimmed part */
	for (i = 0; i <= end; i++)
		new[i] = str[start + i];

	new[end + 1] = '\0';
	return (new);
}

