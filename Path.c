#include "main.h"

char *get_path(char **env)
{
    int i = 0;  /*Start from the first environment variable*/

    while (env[i])  /*While there's a string at env[i]*/
    {
        /*Check if the current string starts with "PATH="*/
        if (env[i][0] == 'P' &&
            env[i][1] == 'A' &&
            env[i][2] == 'T' &&
            env[i][3] == 'H' &&
            env[i][4] == '=')
        {
            return (env[i] + 5);  /* Skip "PATH=" and return the rest*/
        }

        i++;  /* Move to the next environment string*/
    }

    return (NULL);  /*If no PATH= found, return NULL*/
}

