#include "raytracer.h"

void init_struct(t_scene *scene)
{
    scene->num_ambient_light = 0;
	scene->num_camera = 0;
	scene->num_light = 0;
	scene->num_sphere = 0;
	scene->num_plane = 0;
	scene->num_cylinder = 0;
}

void check_element(char *line,int *i, t_raytracer *raytracer)
{
	if(ft_strncmp(&line[*i], "A", 1) == 0)
		ambient_light(line,&raytracer->scene);
	else if(ft_strncmp(&line[*i], "C", 1) == 0)
		camera(line,&raytracer->scene);
	else if(ft_strncmp(&line[*i], "L", 1) == 0)
		light(line,&raytracer->scene);
	else if (ft_strncmp(&line[*i], "sp", 2) == 0)
		sphere(line, &raytracer->scene);
	else if (ft_strncmp(&line[*i], "pl", 2) == 0)
		plane(line, &raytracer->scene);
	else if (ft_strncmp(&line[*i], "cy", 2) == 0)
		cylinder(line, &raytracer->scene);
}

int extension_is_valide(char *filename)
{
	char *dot;
	dot = ft_strrchr(filename, '.');
	if(dot && ft_strcmp(dot, ".rt") == 0)
		return (1);
	return (0);
}

int open_file(char *file)
{
	int fd;

	fd = open(file,O_RDONLY);
	if(fd == -1)
	{
		printf("Error: file not found!\n");
		exit(2);
	}
	if(!extension_is_valide(file))
	{
		close(fd);
		printf("Error: extension is invalid!\n");
		exit(2);
	}

	return (fd);
}

int parse_scene_file(t_raytracer *raytracer,char *filename)
{
	char *line;
	int  fd;
	int i;
	init_struct(&raytracer->scene);
	fd = open_file(filename);
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
		{
			return (1);
			break;
		}
			
		if(ft_strisspace(line))
		{
			free(line);
			continue;
		}
		i = 0;
		while(line[i] && ft_isspace(line[i]))
			i++;
		raytracer->scene.fd = fd;
		check_element(line, &i, raytracer);
		free(line);
	}
	close(fd);
	return (0);
}
