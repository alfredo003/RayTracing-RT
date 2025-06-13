#include "raytracer.h"
 
static void	is_valid(char *line, int fd, char **normal_tokens, char **tokens)
{
	int	result;

	result = 0;
	if (normal_tokens == NULL || num_tokens(normal_tokens) != 3
		|| normal_tokens[0] == NULL || normal_tokens[1] == NULL
		|| normal_tokens[2] == NULL)
	{
		result = 1;
		printf("Error: Normal plane format: 'X,Y,Z': %s", line);
	}
	else if (!ft_isdouble(normal_tokens[0])
		|| !ft_isdouble(normal_tokens[1])
		|| !ft_isdouble(normal_tokens[2]))
	{
		result = 1;
		printf("Error: Normal plane is not number: 'X,Y,Z': %s", line);
	}
	if (result == 1)
	{
		free_tokens(normal_tokens);
		free_tokens(tokens);
		free_buffer_and_exit(line, fd);
	}
}

static t_vec3	get_normal(char *xyz, char *line, int fd, char **tokens)
{
	t_vec3	normal;
	char	**normal_tokens;

	normal_tokens = ft_split(xyz, ',');
	is_valid(line, fd, normal_tokens, tokens);
	normal.x = ft_atof(normal_tokens[0]);
	normal.y = ft_atof(normal_tokens[1]);
	normal.z = ft_atof(normal_tokens[2]);
	free_tokens(normal_tokens);
	if (normal.x < -1.0 || normal.x > 1.0
		|| normal.y < -1.0 || normal.y > 1.0
		|| normal.z < -1.0 || normal.z > 1.0)
	{
		printf("Error: Normal plane must be in the range [-1,1]: %s", line);
		free_tokens(tokens);
		free_buffer_and_exit(line, fd);
	}
	normal = vec3_normalize(normal);
	if (normal.x == 0 && normal.y == 0 && normal.z == 0)
	{
		printf("Error: Normal plane cannot be zeros: %s", line);
		free_tokens(tokens);
		free_buffer_and_exit(line, fd);
	}
	return (normal);
}

void plane(char *line, t_scene *scene)
{
    char **tokens;
    char *point;
    char *normal;
    char *color;
	t_plane *plane;

    tokens = ft_split(line, ' ');
    if(!tokens || num_tokens(tokens) != 4 || !tokens[0] 
        || !tokens[1]  || !tokens[2] || !tokens[3]  )
    {
        printf("Error: Sphere format: 'pl point normal color'");
        free_tokens(tokens);
        free_buffer_and_exit(line, scene->fd);
    }

    point = tokens[1];
    normal = tokens[2];
    color = tokens[3];
    scene->plane.point = get_position(point, line , scene->fd, tokens);
    scene->plane.normal = get_normal(normal, line, scene->fd, tokens);
    scene->plane.color = get_color(color, line, scene->fd, tokens);
    free_tokens(tokens);
    scene->num_plane++;
    plane = malloc(sizeof(t_plane));
    *plane = scene->plane; 
    add_list_obj(scene, PLANE, plane);
}