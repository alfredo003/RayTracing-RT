#include "raytracer.h"

static double get_ratio(char *ratio, char *line, int fd, char **tokens)
{
    double result;

    if(ft_isdouble(ratio) == 0)
    {
        printf("Error: Ratio is not number");
        free_tokens(tokens);
        free_buffer_and_exit(line,fd);
    }
    result = ft_atof(ratio);
    if(result < 0.0 || result > 1.0)
    {   
        printf("Error: Ratio must be in the range [0.0,1.0]");
        free_tokens(tokens);
        free_buffer_and_exit(line, fd);
    }
    return (result);
}

void ambient_light(char *line, t_scene *scene)
{
    char **tokens;
    char *ratio;
    char *color;

    tokens = ft_split(line, ' ');
    if(scene->num_ambient_light >= 1)
    {
        printf("Error: Ambient light can only be defined once\n");
        free_tokens(tokens);
        free_buffer_and_exit(line, scene->fd);
    }
    if(!tokens || num_tokens(tokens) != 3 || !tokens[0] || !tokens[1] || !tokens[2])
    {
        printf("Error:  ambient Light format: 'A ratio R,G,B'");
        free_tokens(tokens);
        free_buffer_and_exit(line, scene->fd);
    }

    ratio = tokens[1];
    color = tokens[2];
    scene->ambient_light.ratio = get_ratio(ratio, line,scene->fd, tokens);
    scene->ambient_light.color = get_color(color, line, scene->fd, tokens);
    scene->num_ambient_light = 1;
    free_tokens(tokens);
}