#include "raytracer.h"

int	main(int argc, char **argv)
{
	t_raytracer raytracer;

	if(argc != 2)
		return printf("miniRT <scene file>.rt\n");	
	if(!parse_scene_file(&raytracer,argv[1]))
		return printf("Error: file invalid!\n");

	raytracer.mlx = mlx_init();
    raytracer.win = mlx_new_window(raytracer.mlx, WIDTH, HEIGHT, "Ray Tracing");
    raytracer.img = mlx_new_image(raytracer.mlx, WIDTH, HEIGHT);
    raytracer.addr = mlx_get_data_addr(raytracer.img,&raytracer.bits_per_pixel,&raytracer.line_length, &raytracer.endian);
 
    render_scene(&raytracer);

    mlx_put_image_to_window(raytracer.mlx, raytracer.win, raytracer.img,0,0);
    mlx_hook(raytracer.win,2, 1L << 0,esc_event_key,&raytracer);
    mlx_hook(raytracer.win, 17, 0, close_event_window,&raytracer); 
	
	mlx_loop(raytracer.mlx);
	return (0);	
}
