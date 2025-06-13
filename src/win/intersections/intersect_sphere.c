#include "raytracer.h"

static double quadratic_formula(double a, double b, double c)
{
        double  distance1;
        double distance2;
        double descriminant;
 
        descriminant = b * b - 4 * a * c;
        if (descriminant < 0)
                return (-1.0);
        distance1 = (-b - sqrt(descriminant)) / (2 * a);
        distance2 = (-b + sqrt(descriminant)) / (2 * a);
        if(distance1 > 0.0001)
                return (distance1);
        if(distance2 > 0.0001)
                return (distance2);
        return (-1.0);
}

double intersect_sphere(t_vec3 origin, t_vec3 ray_direction, t_sphere *sphere)
{
        t_vec3  oc;
        double radius;
	double	a;
	double	b;
	double	c;

        oc = vec3_sub(origin, sphere->center);
        radius = sphere->diameter / 2.0;
        a = vec3_dot(ray_direction, ray_direction);
        b = 2.0 * vec3_dot(oc, ray_direction);
        c = vec3_dot(oc, oc) - (radius * radius);
        return (quadratic_formula(a, b, c));
}