#include "raytracer.h"

static void color_is_valid(char *line, int fd, char **color_tokens, char **tokens)
{
    int result;

    result = 0;
    if(!color_tokens || num_tokens(color_tokens) != 3 || !color_tokens[0]
        || !color_tokens[1] || !color_tokens[2])
    {
        result = 1;
        printf("Error: color format: 'R,G,B'\n");
    }
    else if (!ft_isnumber(color_tokens[0]) || !ft_isnumber(color_tokens[1]) || !ft_isnumber(color_tokens[2]))
    {
        result = 1;
        printf("Error: Color is not number: 'R,G,B'");
    }
    if(result == 1)
    {
        free_tokens(color_tokens);
        free_tokens(tokens);
        free_buffer_and_exit(line, fd);
    }

}

t_color get_color(char *color, char *line, int fd, char **tokens)
{
        t_color rgb;
        char **color_tokens;


        color_tokens = ft_split(color, ',');
        color_is_valid(line, fd, color_tokens, tokens);
        rgb.red = ft_atoi(color_tokens[0]);
        rgb.blue = ft_atoi(color_tokens[2]);
        rgb.green = ft_atoi(color_tokens[1]);
       if(rgb.red < 0 || rgb.red > 255 || rgb.green < 0 || rgb.green > 255
            || rgb.blue < 0 || rgb.blue > 255)
        {
            printf("Error: Color must be in the range 0-255: 'R,G,B'");
            free_tokens(color_tokens);
            free_tokens(tokens);
            free_buffer_and_exit(line, fd);
        }
        free_tokens(color_tokens);
        return (rgb);
}