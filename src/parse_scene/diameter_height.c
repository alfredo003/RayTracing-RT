#include "raytracer.h"

double get_diameter(char *diameter, char *line, int fd, char **tokens)
{
    if(ft_isdouble(diameter) == 0)
    {
        printf("Dimeter is invalid!");
        free_tokens(tokens);
        free_buffer_and_exit(line, fd);
    }

    return (ft_atof(diameter));
}

double get_height(char *height, char *line, int fd, char **tokens)
{
       if(ft_isdouble(height) == 0)
    {
        printf("Height is invalid!");
        free_tokens(tokens);
        free_buffer_and_exit(line, fd);
    }

    return (ft_atof(height));
}