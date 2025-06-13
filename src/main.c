#include "raytracer.h"

int	main(int argc, char **argv)
{
	t_raytracer raytracer;

	if(argc != 2)
		return printf("miniRT <scene file>.rt\n");	
	ft_memset(&raytracer, 0, sizeof(t_raytracer));

	if(!parse_scene_file(&raytracer,argv[1]))
		return printf("Error: file invalid!\n");
	if(!init_mlx(&raytracer))
		return printf("Error: MLX\n");
	
	mlx_loop(raytracer.mlx);
	return (0);	
}
