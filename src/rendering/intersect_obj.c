/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/16 18:42:56 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles intersection with a sphere
** If a sphere is intersected, t_nearest is updated and true is returned.
**
** If a point is on the primitive: x^2 + y^2 + z^2 = 1
**
** quad_coef.x = a
** quad_coef.y = b
** quad_coef.z = c
*/

bool		intersect_sphere(t_sphere *sphere, t_ray *ray)
{
	t_vec3	l;
	t_vec3	quad_coef;

	l = sub_vec3(ray->origin, sphere->pos);
	quad_coef.x = quadnorm_vec3(ray->dir);
	quad_coef.y = 2.0 * dot_vec3(ray->dir, l);
	quad_coef.z = quadnorm_vec3(l) - ft_sqr(sphere->radius);
	return (solve_quadratic(ray, quad_coef));
}

/*
** This function handles intersection with a plane
** If a plane is intersected, t_nearest is updated and true is returned.
**
** Ax + By + Cz + D = 0
*/

bool		intersect_plane(t_plane *plane, t_ray *ray)
{
	double	t;
	double	denom;
	t_vec3	p0l0;

	denom = dot_vec3(plane->rot, ray->dir);
	if (fabs(denom) > 1e-6)
	{
		p0l0 = sub_vec3(plane->pos, ray->origin);
		t = dot_vec3(p0l0, plane->rot) / denom;
		if (t >= 0)
		{
			ray->t_nearest = t;
			return (true);
		}
	}
	return (false);
}

/*
** This function handles intersection with a square
** If a square is intersected, t_nearest is updated and true is returned.
*/

bool		intersect_square(t_scene *scene, t_square *square, t_ray *ray)
{
	t_plane	*tmp;
	t_vec3	inter_p;
	t_vec3	v;
	double	d;

	tmp = create_plane(scene, square->pos, square->rot, square->color);
	if (intersect_plane(tmp, ray) == true)
	{
		free(tmp);
		inter_p = add_vec3(ray->origin, scale_vec3(ray->t_nearest, ray->dir));
		v = sub_vec3(inter_p, square->pos);
		d = 0.5 * square->side;
		if ((fabs(v.x) <= d) && (fabs(v.y) <= d) && (fabs(v.z) <= d))
			return (true);
		set_ray_nearest(ray);
	}
	else
		free(tmp);
	return (false);
}
