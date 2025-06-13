#include "raytracer.h"


static double get_brightness(char *brightn, char *line, int fd, char **tokens)
{
    double brightness;

    if(ft_isdouble(brightn) == 0)
    {
        printf("Error: Light brightness is not nuber");
        free_tokens(tokens);
        free_buffer_and_exit(line, fd);
    }

    brightness  = ft_atof(brightn);
    if(brightness < 0.0 || brightness > 1.0)
    {
        printf("Error: Brightness must be in the range [0.1,1.0]");
        free_tokens(tokens);
        free_buffer_and_exit(line, fd);
    }
    return (brightness);
}

void light(char *line, t_scene *scene)
{
    char **tokens;
    char *position;
    char *brightness;

    tokens = ft_split(line, ' ');

    if(scene->num_light >= 1)
    {
        printf("Error: Light can only be defined once\n");
        free_tokens(tokens);
        free_buffer_and_exit(line, scene->fd);
    }
    if(!tokens || num_tokens(tokens) != 3 || !tokens[0] || !tokens[1] || !tokens[2])
    {
        printf("Error: Light format: 'L position brightness\n");
        free_tokens(tokens);
        free_buffer_and_exit(line, scene->fd);
    }

    position = tokens[1];
    brightness = tokens[2];
    scene->light.brightness = get_brightness(brightness, line, scene->fd, tokens);
    scene->light.position = get_position(position, line, scene->fd, tokens);
    scene->num_light = 1;
    free_tokens(tokens);
}