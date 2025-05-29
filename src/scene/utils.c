#include "raytracer.h"

int num_tokens(char **tokens)
{
    int i;

    i = 0;
    while(tokens[i] && !ft_strisspace(tokens[i]))
        i++;
    return (i);
}

void free_tokens(char **tokens)
{
    int i;

    i =0;
    while (tokens && tokens[i])
    {
        free(tokens[i]);
        tokens[i] = NULL;

    }
    free(tokens);
}

void free_buffer_and_exit(char *line, int fd)
{
    char *buffer;

    free(line);
    while(1)
    {
        buffer = get_next_line(fd);
        if(!buffer)
            break;
        free(buffer);
    }
    close(fd);
    exit(1);
}