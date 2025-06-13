#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <stdio.h>
#include "libft.h"
#include <float.h>
#include "mlx.h"
#include <errno.h>
#include <math.h>

typedef struct s_vec3
{
    double x;
    double y;
    double z;
} t_vec3;

typedef struct t_ray_vector
{
	double	x;
	double	y;
	t_vec3	up;
	t_vec3	right;
	t_vec3	forward;
	t_vec3	up_world;
	t_vec3	direction;
}		t_ray_vector;


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

typedef struct s_camera
{
    t_vec3 position;
    t_vec3 direction;
    double fov;
} t_camera;

typedef struct s_light{
    t_vec3 position;
    double brightness;
} t_light;


typedef enum e_object_type
{
    PLANE,
    SPHERE,
    CYLINDER
}   t_object_type;

typedef struct s_shade_object
{
    t_vec3  origin;
    t_vec3  ray_dir;
    double  distance_min;
} t_shade_object;


typedef struct s_object_list
{
    t_object_type        type;
    void                 *object;
    struct s_object_list *next;
}      t_object_list;

typedef struct s_phere
{
    t_vec3 center;
    double diameter;
    t_color color;
} t_sphere;

typedef struct s_plane
{
    t_vec3 point;
    t_vec3 normal;
    t_color color;
}   t_plane;

typedef struct s_scene
{
   int fd;
   t_ambient_light ambient_light;
   int num_ambient_light;
   t_camera camera;
   int num_camera;
   t_sphere sphere;
   int num_sphere;
   t_light light;
   int num_light; 
   t_plane plane;
   int num_plane;
   t_object_list	*object_list;
}   t_scene;


typedef struct s_raytracer
{
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    t_scene scene;
}   t_raytracer;

#include "./objects.h"
#include "./render.h"

void init_raytracing(t_raytracer *raytracer);
int esc_event_key(int keycod, t_raytracer *param);
int  close_event_window(t_raytracer *param);
int parse_scene_file(t_raytracer *raytracer,char *filename);

void ambient_light(char *line, t_scene *scene);
void camera(char *line, t_scene *scene);
void light(char *line, t_scene *scene);

t_color get_color(char *color, char *line, int fd, char **tokens);
t_vec3  get_position(char *coordinate, char *line, int fd, char **tokens);
t_vec3  get_direction(char *coordinate, char *line, int fd, char **tokens);

t_vec3	vec3_normalize(t_vec3 v);
t_vec3	vec3_cross(t_vec3 a, t_vec3 b);
t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3 vec3_scale(t_vec3 v, double s);
t_vec3 vec3_sub(t_vec3 a, t_vec3 b);
double vec3_dot(t_vec3 a, t_vec3 b);

void add_list_obj(t_scene *scene, t_object_type type, void *object);
void free_buffer_and_exit(char *line, int fd);
int  num_tokens(char **tokens);
void free_tokens(char **tokens);

#endif
