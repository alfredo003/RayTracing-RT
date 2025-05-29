#include "raytracer.h"

double	vec3_length(t_vec3 v)
{
	double	length;

	length = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	return (length);
}

t_vec3	vec3_normalize(t_vec3 v)
{
	t_vec3	result;
	double	length;

	length = vec3_length(v);
	if (length == 0)
		return ((t_vec3){0, 0, 0});
	result.x = v.x / length;
	result.y = v.y / length;
	result.z = v.z / length;
	return (result);
}