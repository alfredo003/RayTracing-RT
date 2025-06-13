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


t_vec3 get_direction(char *coordinate, char *line, int fd, char **tokens)
{
    t_vec3 direction;
    char **direction_tokens;

    direction_tokens = ft_split(coordinate, ',');
    is_valid(line, fd, direction_tokens, tokens);
    direction.x = ft_atof(direction_tokens[0]);
    direction.y = ft_atof(direction_tokens[1]);
    direction.z = ft_atof(direction_tokens[2]);
    if(direction.x < -1.0 || direction.x > 1.0
        || direction.y < -1.0 || direction.y > 1.0
        || direction.z < -1.0 || direction.z > 1.0)
    {
        printf("Error: Direction must be in the range [-1,1]\n");
        free_tokens(tokens);
        free_buffer_and_exit(line, fd);
    }
    direction = vec3_normalize(direction);
    
    if(direction.x == 0 && direction.y == 0 && direction.z == 0)
    {
        printf("Error: Direction camera cannot be zeros\n");
        free_tokens(tokens);
        free_buffer_and_exit(line, fd);
    }

    return (direction);
}