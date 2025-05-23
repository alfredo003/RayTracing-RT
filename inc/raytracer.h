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
   int fd;
  t_ambient_light ambient_light;
   int num_ambient_light;
}   t_scene;

typedef struct s_raytracer
{
    void *mlx;
    void *win;
    void *img;
    void *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    t_scene scene;
}   t_raytracer;

void init_raytracing(t_raytracer *raytracer);
int esc_event_key(int keycod, t_raytracer *param);
int  close_event_window(t_raytracer *param);
void validate_scene(t_raytracer *raytracer,char *filename);
void ambient_light(char *line, t_scene *scene);
t_color get_color(char *color, char *line, int fd, char **tokens);



void free_buffer_and_exit(char *line, int fd);
int num_tokens(char **tokens);
void free_tokens(char **tokens);
#endif
