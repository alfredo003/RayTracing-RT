#include "raytracer.h"

void debug_objects(t_object_list *obj_list)
{
    t_object_list *current = obj_list;
    int count = 0;
    
    printf("=== DEBUG: Lista de Objetos ===\n");
    while (current)
    {
        printf("Objeto %d: ", count++);
        if (current->type == SPHERE)
        {
            t_sphere *sphere = (t_sphere *)current->object;
            printf("SPHERE - Centro: (%.2f, %.2f, %.2f), Diâmetro: %.2f\n", 
                   sphere->center.x, sphere->center.y, sphere->center.z, sphere->diameter);
        }
        else if (current->type == PLANE)
        {
            t_plane *plane = (t_plane *)current->object;
            printf("PLANE - Ponto: (%.2f, %.2f, %.2f), Normal: (%.2f, %.2f, %.2f)\n", 
                   plane->point.x, plane->point.y, plane->point.z,
                   plane->normal.x, plane->normal.y, plane->normal.z);
        }
        else
        {
            printf("TIPO DESCONHECIDO: %d\n", current->type);
        }
        current = current->next;
    }
    printf("Total de objetos: %d\n", count);
    printf("==============================\n");
}
 
int  init_mlx(t_raytracer *raytracer)
{
    raytracer->mlx = mlx_init();
    raytracer->win = mlx_new_window(raytracer->mlx, WIDTH,HEIGHT, "Ray Tracing");
    raytracer->img = mlx_new_image(raytracer->mlx,WIDTH,HEIGHT);
    raytracer->addr = mlx_get_data_addr(raytracer->img,&raytracer->bits_per_pixel,&raytracer->line_length, &raytracer->endian);
 
    render_scene(raytracer);

    mlx_put_image_to_window(raytracer->mlx, raytracer->win, raytracer->img,0,0);
    mlx_hook(raytracer->win,2, 1L << 0,esc_event_key,raytracer);
    mlx_hook(raytracer->win, 17, 0, close_event_window,raytracer);

    printf("Ambient Light: \n ratio: %f \n",raytracer->scene.ambient_light.ratio);
    printf("Light: \n brightness: %f \n",raytracer->scene.light.brightness);
    printf("Sphere: \n diameter: %f \n",raytracer->scene.sphere.diameter);
    printf("Plane: \n Color: %d \n",raytracer->scene.plane.color.red);
    printf("Cylinder: \n Color: %.2f \n",raytracer->scene.cylinder.height);
    //debug_objects(raytracer->scene.object_list);
    return 1;
}
