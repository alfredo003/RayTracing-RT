#ifndef RENDER_H
#define RENDER_H

typedef struct s_ray_var
{
	double	x;
	double	y;
	t_vec3	up;
	t_vec3	right;
	t_vec3	forward;
	t_vec3	up_world;
	t_vec3	direction;
}		t_ray_var;



#endif