#include "raytracer.h"

t_color shade_plane(t_scene *scene, t_plane *plane, t_vec3 origin, t_vec3 dir, double t)
{
    t_vec3 hit_point;
    t_vec3 normal;
    t_vec3 light_dir;
    double diff;
    t_color obj;
    t_color diffuse;
    t_color ambient;
    t_color result;
    
    hit_point = vec3_add(origin, vec3_scale(dir, t));
    
    normal = plane->normal;
    
    if (vec3_dot(dir, normal) > 0)
        normal = vec3_scale(normal, -1.0);
    
    light_dir = vec3_normalize(vec3_sub(scene->light.position, hit_point));
    
    diff = fmax(0.0, vec3_dot(normal, light_dir)) * scene->light.brightness;
    
    obj = plane->color;
    
    diffuse = (t_color){
        (int)(obj.red * diff),
        (int)(obj.green * diff),
        (int)(obj.blue * diff)
    };
    
    ambient = (t_color){
        (int)(obj.red * scene->ambient_light.ratio * scene->ambient_light.color.red / 255.0),
        (int)(obj.green * scene->ambient_light.ratio * scene->ambient_light.color.green / 255.0),
        (int)(obj.blue * scene->ambient_light.ratio * scene->ambient_light.color.blue / 255.0)
    };
    
    result = (t_color){
        fmin(255, ambient.red + diffuse.red),
        fmin(255, ambient.green + diffuse.green),
        fmin(255, ambient.blue + diffuse.blue)
    };
    
    return (result);
}