#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <stdio.h>
#include "libft.h"
#include "mlx.h"
#include <errno.h>

typedef struct s_color
{
    int red;
    int green;
    int blue;
} t_color;

typedef struct s_ambient_light
{
    double ratio;
    t_color color;

} t_ambient_light;

typedef struct s_scene
{
    t_ambient_light ambient_light;
} t_scene;

void  validate_scene(char *file, t_scene *scene);

#endif
