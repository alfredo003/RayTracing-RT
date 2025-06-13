#include "raytracer.h"

void add_list_obj(t_scene *scene, t_object_type type, void *object)
{
    t_object_list *new_obj;

    new_obj = malloc(sizeof(t_object_list));
    if(new_obj == NULL)
    {
        perror("Error: malloc failed");
        free(object);
        exit(1);
    }
    new_obj->type = type;
    new_obj->object = object;
    new_obj->next = scene->object_list;
    scene->object_list = new_obj;
}