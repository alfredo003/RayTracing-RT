#include "raytracer.h"

static void axis_is_valid(char *line, int fd, char **axis_tokens, char **tokens)
{
	int	result;

	result = 0;
	if (axis_tokens == NULL || num_tokens(axis_tokens) != 3
		|| axis_tokens[0] == NULL || axis_tokens[1] == NULL
		|| axis_tokens[2] == NULL)
	{
		result = 1;
		printf("Error: Axi cylinder format: 'X,Y,Z'");
	}
	else if (!ft_isdouble(axis_tokens[0]) || !ft_isdouble(axis_tokens[1])
		|| !ft_isdouble(axis_tokens[2]))
	{
		result = 1;
		printf("Error: Axi cylinder is not number: 'X,Y,Z'");
	}
	if (result == 1)
	{
		free_tokens(axis_tokens);
		free_tokens(tokens);
		free_buffer_and_exit(line, fd);
	}
}

t_vec3 get_axis(char *xyz, char *line, int fd, char **tokens)
{
    t_vec3 axis;
    char **axis_tokens;

    axis_tokens = ft_split(xyz, ',');
    axis_is_valid(line, fd, axis_tokens, tokens);
    axis.x = ft_atof(axis_tokens[0]);
    axis.y = ft_atof(axis_tokens[1]);
    axis.z = ft_atof(axis_tokens[2]);
    free_tokens(axis_tokens);
    if(axis.x < -1.0 || axis.x > 1.0 || axis.y < -1.0 || axis.y > 1.0 || axis.z < -1.0 || axis.z > 1.0)
    {
        printf("Error: Axios cylinder must be in the range [-1,0]");
        free_tokens(tokens);
        free_buffer_and_exit(line, fd);
    }
    axis = vec3_normalize(axis);
    if (axis.x == 0 && axis.y == 0 && axis.z == 0)
    {
        printf("Error: Axis cylinder cannot be zeros");
        free_tokens(tokens);
        free_buffer_and_exit(line, fd);
    }
    return (axis);
}