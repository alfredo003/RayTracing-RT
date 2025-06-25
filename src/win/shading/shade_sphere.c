#include "raytracer.h"

t_color shade_sphere(t_scene *scene, t_sphere *sphere, t_vec3 origin, t_vec3 dir, double t)
{
    t_vec3 hit_point = vec3_add(origin, vec3_scale(dir, t));
    t_vec3 normal = vec3_normalize(vec3_sub(hit_point, sphere->center));
    t_vec3 light_dir = vec3_normalize(vec3_sub(scene->light.position, hit_point));

    double diff = fmax(0.0, vec3_dot(normal, light_dir)) * scene->light.brightness;

    t_color obj = sphere->color;

    t_color diffuse = (t_color){
        (int)(obj.red * diff),
        (int)(obj.green * diff),
        (int)(obj.blue * diff)
    };

    t_color ambient = (t_color){
        (int)(obj.red * scene->ambient_light.ratio * scene->ambient_light.color.red / 255.0),
        (int)(obj.green * scene->ambient_light.ratio * scene->ambient_light.color.green / 255.0),
        (int)(obj.blue * scene->ambient_light.ratio * scene->ambient_light.color.blue / 255.0)
    };

    t_color result = {
        fmin(255, ambient.red + diffuse.red),
        fmin(255, ambient.green + diffuse.green),
        fmin(255, ambient.blue + diffuse.blue)
    };


    return (result);
}

