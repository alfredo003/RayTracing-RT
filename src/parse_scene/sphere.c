#include "raytracer.h"

void sphere(char *line, t_scene *scene)
{
    char **tokens;
    char *diameter;
    char *center;
    char *color;
    t_sphere *sphere;
 
    tokens = ft_split(line, ' ');

    if(!tokens || num_tokens(tokens) != 4 || !tokens[0] 
        || !tokens[1]  || !tokens[2] || !tokens[3]  )
    {
        printf("Error: Sphere format: 'sp center diameter color'");
        free_tokens(tokens);
        free_buffer_and_exit(line, scene->fd);
    }

    center = tokens[1];
    diameter = tokens[2];
    color = tokens[3];
    scene->sphere.center = get_position(center, line , scene->fd, tokens);
    scene->sphere.diameter = get_diameter(diameter, line, scene->fd, tokens);
    scene->sphere.color = get_color(color, line, scene->fd, tokens);
    free_tokens(tokens);
    scene->num_sphere++;
    sphere = malloc(sizeof(t_sphere));
    *sphere = scene->sphere;
    add_list_obj(scene, SPHERE, sphere);
}