#include "raytracer.h"

void init_raytracing(t_raytracer *raytracer)
{

    raytracer->mlx = mlx_init();
    raytracer->win = mlx_new_window(raytracer->mlx, WIDTH,HEIGHT, "Ray Tracing");
    raytracer->img = mlx_new_image(raytracer->mlx,WIDTH,HEIGHT);
    raytracer->addr = mlx_get_data_addr(raytracer->img,&raytracer->bits_per_pixel,&raytracer->line_length, &raytracer->endian);

    render_scene(&raytracer);

    mlx_put_image_to_window(raytracer->mlx, raytracer->win, raytracer,0,0);
    mlx_hook(raytracer->win,2, 1L << 0,esc_event_key,raytracer);
    mlx_hook(raytracer->win, 17, 0, close_event_window,raytracer);
    printf("Ambient Light: \n ratio: %f \n",raytracer->scene.ambient_light.ratio);
}
