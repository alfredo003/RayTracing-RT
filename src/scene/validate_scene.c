#include "raytracer.h"

int is_valide_extension(char *file)
{
    char *dot;
    dot = ft_strrchr(file,'.');
    if(dot && ft_strcmp(dot, ".rt") == 0)
        return (1);
    return (0);
}

int read_file(char *file)
{
    int fd;

    if(!is_valide_extension(file))
    {
        printf("Error: Invalid file extension, expected .rt\n");
        exit(1);
    }

    fd = open(file, O_RDONLY);
    if(fd == -1)
    {
        perror("Error: File not found or unable to open\n");
        exit(2);
    }

    return (fd);
}
void  validate_scene(char *file,t_scene *scene)
{
    //int i;
    int fd;
    //char *line;



    fd = read_file(file);

    close(fd);
}