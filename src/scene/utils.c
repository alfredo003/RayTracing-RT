#include "raytracer.h"


double	vec3_length(t_vec3 v)
{
	double	length;

	length = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	return (length);
}

t_vec3	vec3_normalize(t_vec3 v)
{
	t_vec3	result;
	double	length;

	length = vec3_length(v);
	if (length == 0)
		return ((t_vec3){0, 0, 0});
	result.x = v.x / length;
	result.y = v.y / length;
	result.z = v.z / length;
	return (result);
}


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