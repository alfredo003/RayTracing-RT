#include "raytracer.h"

int esc_event_key(int keycod, t_raytracer *param)
{
    if(keycod == 65307)
    {
        mlx_destroy_window(param->mlx,param->win);
         exit(0);
    }
    return 0;
}

int  close_event_window(t_raytracer *param)
{
    mlx_destroy_window(param->mlx,param->win);
    exit(0);
}