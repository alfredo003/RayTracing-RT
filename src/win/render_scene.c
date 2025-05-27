#include "raytracer.h"

void put_pixel(t_raytracer *img, int x, int y, t_color color)
{
    char *destinetion;
    destinetion = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int *)destinetion = (color.red << 16 | color.green << 8 | color.blue);
}

void render_scene(t_raytracer *raytracer)
{
    int x;
    int y;
    t_vec3 origin;
    t_vec3 ray_direction;
    t_color color;

    y =0;
    origin = raytracer->scene.position;
    while(y < HEIGHT)
    {
        x = 0;
        while(x < WIDTH)
        {
            ray_direction = get_ray_direction(raytracer->scene.camera, x, y);
            color = ray_trace(&raytracer->scene, origin, ray_direction);
            put_pixel(&raytracer, x, y, color);
            x++;
        }
        y++;
    }
}
