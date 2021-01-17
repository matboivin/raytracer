/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/24 01:15:11 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft_printf.h"
#include "minirt.h"

static void	set_secondary_ray(t_obj *hit_obj, t_ray *ray)
{
	get_obj_color(hit_obj, ray);
	ray->hit_p = get_hit_point(ray->origin, ray->t_nearest, ray->dir);
	get_obj_normal(hit_obj, ray, ray->hit_p);
}

static void	shade(t_minirt *env, t_ray *ray)
{
	t_obj	*hit_obj;

	hit_obj = trace_ray_to_objs(env->objs, ray);
	if (hit_obj)
	{
		set_secondary_ray(hit_obj, ray);
		trace_ray_to_lights(env, ray);
	}
}

/*
** (Pull requested by 0auBSQ)
** (To move to an external file, contains vector * float operation, vector reflection and refraction deviation calculus, taken from my RT)
*/

t_vec3	v3dotf(t_vec3 v, double f)
{
	t_vec3	r;

	r.x = v.x * f;
	r.y = v.y * f;
	r.z = v.z * f;
	return (r);
}

t_vec3	v3reflect(t_vec3 i, t_vec3 n)
{
	t_vec3	r;
	double	double_dot;

	double_dot = 2. * (i.x * n.x + i.y * n.y + i.z * n.z);
	r.x = i.x - double_dot * n.x;
	r.y = i.y - double_dot * n.y;
	r.z = i.z - double_dot * n.z;
	return (r);
}

t_vec3	v3refract(t_vec3 i, t_vec3 n, double indice)
{
	double	cosi;
	double	etai;
	double	eta;
	double	k;

	cosi = dot_vec3(i, n);
	cosi = (cosi > 1) ? 1 : cosi;
	cosi = (cosi < -1) ? -1 : cosi;
	etai = 1;
	if (cosi < 0)
		cosi = -cosi;
	else
	{
		indice = 1;
		etai = indice;
		n = v3dotf(n, -1);
	}
	if (indice <= 0.1)
		indice = 1.;
	eta = etai / indice;
	k = 1 - eta * eta * (1 - cosi * cosi);
	return ((k < 0) ? (t_vec3){0, 0, 0}
		: add_vec3(v3dotf(i, eta), v3dotf(n, eta * cosi - sqrt(k))));
}

/*
** (Pull requested by 0auBSQ)
** (Raw) Recurrsive Reflection and refraction handling (Few refractions per pixel so no stack overflow risks)
** To do : 
** - Add REFLECT (Reflection factor), REFRACT (Refraction indice) and TRANSPARENCY (Transparency factor) within the file definition, replace the placeholder by the parsed values
** - Use vec4 instead of vec3 for colors (add a w variable for alpha scale)
** - Move RECURSIVE_REFLECTION_HITS and RECURSIVE_REFRACTION_HITS in the header file
** - side have to be set to -1 if camera is inside the object (Handler for in/out refraction deviation)
** - Fix the distance = 0 issue to avoid the ray to stick at the object surface (ignore hit if distance from origin to hit = 0) and eventually add an epsilon to make transparency and refraction work correctly
*/

#define REFLECT 0.25
#define REFRACT 1.50
#define TRANSPARENCY 0.8
#define RECURSIVE_REFLECTION_HITS 2
#define RECURSIVE_REFRACTION_HITS 0

t_vec3		shade_ray(t_minirt *env, t_ray ray, int layer, int refr_layer, int side) {
	shade(env, &ray);
	//printf("hit %f %f %f layer %d origin %f %f %f nearest %f\n", ray.hit_p.x, ray.hit_p.y, ray.hit_p.z, refr_layer, ray.origin.x, ray.origin.y, ray.origin.z, ray.t_nearest);
	// Reflection
	if (ray.t_nearest != INFINITY && layer > 0 && REFLECT >= 0.01) {
		ray.dir = v3reflect(ray.dir, ray.normal);
		ray.origin = ray.hit_p;
		ray.vcolor = add_vec3(v3dotf(ray.vcolor, 1. - REFLECT), v3dotf(shade_ray(env, ray, layer - 1, refr_layer, side), REFLECT));
	}
	// Refraction
	if (ray.t_nearest != INFINITY && refr_layer > 0 && TRANSPARENCY >= 0.01) {
		ray.dir = v3refract(ray.dir, ray.normal, pow(REFRACT, side));
		ray.origin = ray.hit_p;
		ray.vcolor = add_vec3(v3dotf(ray.vcolor, 1. - TRANSPARENCY), v3dotf(shade_ray(env, ray, layer, refr_layer - 1, -side), TRANSPARENCY));
	}
	return (ray.vcolor);
}

/*
** This function sets the ray origin and iterates over all pixels in the image.
** At each pixel, it sets the ray direction, casts the ray and
** retrieves the ray color to put it in the image.
*/

void		trace_ray(t_minirt *env, t_camera *cam, t_image *img)
{
	t_ray	ray;
	int		x;
	int		y;
	int		progress;

	look_at(cam);
	set_ray_origin(&ray, cam->pos);
	y = 0;
	while (y < env->res.size_y)
	{
		x = 0;
		while (x < env->res.size_x)
		{
			set_ray_dir(cam, &ray, get_pixel_coord(cam->fov, env->res, x, y));
			t_vcolor col = shade_ray(env, ray, RECURSIVE_REFLECTION_HITS, RECURSIVE_REFRACTION_HITS, 1);
#ifdef DEBUG
			ray.vcolor = map_normal(&ray);
#endif /* DEBUG */
			put_pixel_to_image(img, col, x, y);
			x++;
		}
		y++;
		progress = ft_percent(y, env->res.size_y);
		ft_printf("\rRendering image... %d%%", progress);
	}
	ft_printf("\n");
}
