#include "raytracer.h"



t_vec3	get_up_world(t_vec3 forward)
{
	if (fabs(forward.x) == 0 && fabs(forward.z) == 0)
		return ((t_vec3){0, 0, 1});
	else
		return ((t_vec3){0, 1, 0});
}

t_vec3 get_ray_direction(t_camera camera, int i, int j)
{
    double  aspect_ratio;
    double  fov_rad;
    double viewport_height;
    double viewport_width;
    t_ray_vector  vector;

    aspect_ratio = (double)WIDTH / (double)HEIGHT;
    fov_rad = camera.fov * M_PI / 180.0;
    viewport_height = 2.0 * tan(fov_rad / 2.0);

    viewport_width = viewport_height * aspect_ratio;
 
    vector.x = (double)i / (WIDTH - 1);
    vector.y = (double)j / (HEIGHT - 1);
    vector.x = (vector.x - 0.5) * viewport_width;
    vector.y = (0.5 - vector.y) * viewport_height;

    vector.forward = camera.direction;
    vector.up_world = get_up_world(vector.forward);
    vector.right = vec3_normalize(vec3_cross(vector.forward, vector.up_world));
    vector.up = vec3_normalize(vec3_cross(vector.right, vector.forward));
    
    vector.direction = (t_vec3){
        vector.forward.x + vector.x * vector.right.x + vector.y * vector.up.x,
		vector.forward.y + vector.x * vector.right.y + vector.y * vector.up.y,
		vector.forward.z + vector.x * vector.right.z + vector.y * vector.up.z
    };

    return (vec3_normalize(vector.direction));
}

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
    origin = raytracer->scene.camera.position;
    while(y < HEIGHT)
    {
        x = 0;
        while(x < WIDTH)
        {  
            ray_direction = get_ray_direction(raytracer->scene.camera, x, y);
            color = raytracing(&raytracer->scene, origin, ray_direction);
            put_pixel(raytracer, x, y, color);
            x++;
        }
        y++; 
        
    }
}
