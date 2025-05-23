#include "raytracer.h"


int	main(int argc, char **argv)
{
	t_raytracer raytracer;

	if(argc != 2)
		return printf("miniRT <scene file>.rt\n");
		
	validate_scene(&raytracer,argv[1]);
	init_raytracing(&raytracer);

	mlx_loop(raytracer.mlx);

	return (0);
}
