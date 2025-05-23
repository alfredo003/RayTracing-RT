#include "raytracer.h"

void init_raytracing(t_raytracer *raytracer)
{

    raytracer->mlx = mlx_init();
    raytracer->win = mlx_new_window(raytracer->mlx, 1920,1080, "Ray Tracing");
    raytracer->img = mlx_new_image(raytracer->mlx,1920,1080);
    raytracer->addr = mlx_get_data_addr(raytracer->img,&raytracer.bits_per_pixel);
    mlx_hook(raytracer->win,2, 1L << 0,esc_event_key,raytracer);
    mlx_hook(raytracer->win, 17, 0, close_event_window,raytracer);

    printf("Ambient Light: \n ratio: %f \n",raytracer->scene.ambient_light.ratio);
}
