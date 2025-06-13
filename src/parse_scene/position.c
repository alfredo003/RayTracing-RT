#include "raytracer.h"

static void is_valid(char *line, int fd, char **position_tokens, char **tokens)
{
    int result;

    result = 0;
    if (!position_tokens || num_tokens(position_tokens) != 3 
        || !position_tokens[0] || !position_tokens[1] || !position_tokens[2])
    {
        result = 1;
        printf("Error: Position formart: 'X,YZ'\n");
    }
    else if (!ft_isdouble(position_tokens[0]) || !ft_isdouble(position_tokens[1])
                || !ft_isdouble(position_tokens[2]))
    {
        result = 1;
        printf("Error: Position is not nnumber: 'X,Y,Z'");
    }

    if(result == 1)
    {
        free_tokens(position_tokens);
        free_tokens(tokens);
        free_buffer_and_exit(line, fd);
    }
}

t_vec3 get_position(char *coordinate, char *line, int fd, char **tokens)
{
    t_vec3 position;
    char **position_tokens;

    position_tokens = ft_split(coordinate, ',');
    is_valid(line, fd, position_tokens, tokens);
    position.x = ft_atof(position_tokens[0]);
    position.y = ft_atof(position_tokens[1]);
    position.z = ft_atof(position_tokens[2]);
    free_tokens(position_tokens);
    return (position);
}