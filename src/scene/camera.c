#include "raytracer.h"

static double get_field_view(char *fov_tokens, char *line, int fd, char **tokens)
{
    double fov;

    if(ft_isdouble(fov_tokens) == 0)
    {
        printf("Error: FOV for camera is not number: %s", line);
		free_tokens(tokens);
		free_buffer_and_exit(line, fd);
    }
    fov = ft_atof(fov_tokens);
    if(fov < 0.0 || fov > 180.0)
    {
        printf("Error: FOV for camera must be in the range [0,180]: %s", line);
		free_tokens(tokens);
		free_buffer_and_exit(line, fd);
    }
    return (fov);
}

void camera(char *line, t_scene *scene)
{
    char **tokens;
    
    tokens = ft_split(line, ' ');
    if(scene->num_camera >= 1)
    {
        printf("Error: Camera can only be defined once\n");
        free_tokens(tokens);
        free_buffer_and_exit(line, scene->fd);
    }
    if(!tokens || num_tokens(tokens) != 4 || !tokens[0] || !tokens[1] || !tokens[2] || !tokens[3])
    {
        printf("Error: Camera format: 'C position direction FOV\n");
        free_tokens(tokens);
        free_buffer_and_exit(line, scene->fd);
    }

    scene->camera.position = get_position(tokens[1], line, scene->fd, tokens);
    scene->camera.direction = get_direction(tokens[2], line, scene->fd, tokens);
    scene->camera.fov = get_field_view(tokens[3], line, scene->fd, tokens);
    scene->num_camera = 1;
    free_tokens(tokens);

}