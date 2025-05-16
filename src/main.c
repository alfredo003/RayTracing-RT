#include "raytracer.h"


int	main(int argc, char **argv)
{
	t_scene scene;

	if(argc != 2)
		return printf("Error! ./name_program <Path Map> \n");
	

	validate_scene(argv[1], &scene);	

	printf("Ambient Light:\n");
	printf("  Ratio: %.1f\n", scene.ambient_light.ratio);
	printf("  Color: R=%d, G=%d, B=%d\n", scene.ambient_light.color.red, 
	scene.ambient_light.color.green, scene.ambient_light.color.blue);

	return (0);
}