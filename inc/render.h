#ifndef RENDER_H
#define RENDER_H

#define WIDTH 1920
#define HEIGHT 1080


double intersect_sphere(t_vec3 origin, t_vec3 ray_direction, t_sphere *sphere);
double intersect_plane(t_vec3 origin, t_vec3 ray_direction, t_plane *plane);
double intersect_cylinder(t_vec3 origin, t_vec3 ray_direction, t_cylinder *cylinder);

t_color shade_sphere(t_scene *scene, t_sphere *sphere, t_vec3 origin, t_vec3 dir, double t);
t_color shade_cylinder(t_scene *scene, t_cylinder *cylinder, t_vec3 origin, t_vec3 dir, double t);
t_color shade_plane(t_scene *scene, t_plane *plane, t_vec3 origin, t_vec3 dir, double t);
void render_scene(t_raytracer *raytracer);
t_color raytracing(t_scene *scene, t_vec3 origin, t_vec3 ray_direction);

#endif