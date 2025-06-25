#include "raytracer.h"

void cylinder(char *line, t_scene *scene)
{
        char **tokens;
        char *diameter;
        char *center;
        char *axis;
        char *height;
        char *color;

        t_cylinder *cylinder;

        tokens = ft_split(line, ' ');
        if(!tokens || num_tokens(tokens) != 6 || !tokens[0] 
            || !tokens[1]  || !tokens[2] || !tokens[3] || !tokens[4] || !tokens[5])
        {
            printf("Error: Cylinder format: 'cy center axis diameter height color'");
            free_tokens(tokens);
            free_buffer_and_exit(line, scene->fd);
        } 

        center = tokens[1];
        axis = tokens[2];
        diameter = tokens[3];
        height = tokens[4];
        color = tokens[5];
        scene->cylinder.center =  get_position(center, line , scene->fd, tokens);
        scene->cylinder.axis =  get_axis(axis, line , scene->fd, tokens);
        scene->cylinder.diameter =  get_diameter(diameter, line , scene->fd, tokens);
        scene->cylinder.height = get_height(height, line, scene->fd, tokens);
        scene->cylinder.color = get_color(color, line, scene->fd, tokens);
        free_tokens(tokens);
        scene->num_cylinder++;
       cylinder = malloc(sizeof(t_cylinder));
        *cylinder = scene->cylinder;
        add_list_obj(scene,CYLINDER, cylinder);
}