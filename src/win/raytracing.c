#include "raytracer.h"

t_color shade_object(t_scene *scene, t_object_list *obj, t_shade_object shade)
{
    if (obj && obj->type == SPHERE)
        return (shade_sphere(scene, (t_sphere *)obj->object, shade.origin, shade.ray_dir, shade.distance_min));
    else if (obj && obj->type == PLANE)
        return (shade_plane(scene, (t_plane *)obj->object, shade.origin, shade.ray_dir, shade.distance_min));
    else if (obj && obj->type == CYLINDER)
        return (shade_cylinder(scene, (t_cylinder *)obj->object, shade.origin, shade.ray_dir, shade.distance_min));
    return ((t_color){30, 30, 30});
}

double hit_object(t_object_list *obj, t_vec3 origin, t_vec3 direction)
{
    double result = -1.0;
    
    if (obj->type == SPHERE)
        result = intersect_sphere(origin, direction, (t_sphere *)obj->object);
    else if (obj->type == PLANE)
        result = intersect_plane(origin, direction, (t_plane *)obj->object);
    else if (obj->type == CYLINDER)
        result = intersect_cylinder(origin, direction, (t_cylinder *)obj->object);
    return (result);
}
 
t_color raytracing(t_scene *scene, t_vec3 origin, t_vec3 ray_direction)
{
    t_object_list *obj;
    t_object_list *closest_obj;
    double         distance_ray;
    double         distance_min;
    t_shade_object shade;

    closest_obj = NULL;
    distance_min = DBL_MAX;
    obj = scene->object_list;
    
    while(obj)
    {
       distance_ray = hit_object(obj, origin, ray_direction);
       if(distance_ray > 0.0001 && distance_ray < distance_min)
       {
            distance_min = distance_ray;
            closest_obj = obj;
       }
       obj = obj->next;
    }
    
    shade.origin = origin;
    shade.ray_dir = ray_direction;
    shade.distance_min = distance_min;
    return (shade_object(scene, closest_obj, shade));
}