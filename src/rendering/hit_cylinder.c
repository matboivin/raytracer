/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2021/05/20 15:20:32 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

static bool		is_inside_cyl(t_cyl *cylinder, t_ray *ray, double t)
{
	t_vec3		hit_p;
	t_vec3		bottom, top;

	hit_p = get_hit_point(ray->origin, t, ray->dir);
	bottom = sub_vec3(hit_p, cylinder->base1);
	top = sub_vec3(hit_p, cylinder->base2);
	return (
		(dot_vec3(cylinder->dir, bottom) > 0.0)
		&& (dot_vec3(cylinder->dir, top) < 0.0));
}

static bool		solve_cylinder(t_cyl *cylinder, t_ray *ray, t_vec3 quad_coef,
																	 double *t)
{
	double		root1, root2 = INFINITY;
	bool		retval = false;

	if (get_quad_roots(&root1, &root2, quad_coef))
	{
		if ((root1 > EPSILON) && is_inside_cyl(cylinder, ray, root1))
		{
			*t = root1;
			retval = true;
		}
		if ((root2 > EPSILON) && is_inside_cyl(cylinder, ray, root2))
		{
			if (root2 < root1)
			{
				*t = root2;
				retval = true;
			}
		}
	}
	return (retval);
}

static t_vec3	pre_compute_coef(t_vec3 v1, t_vec3 v2)
{
	return (sub_vec3(v1, scale_vec3(dot_vec3(v1, v2), v2)));
}

bool			hit_cylinder(t_cyl *cylinder, t_ray *ray, double *t)
{
	t_vec3		quad_coef;
	t_vec3		oc, dir, ocdir;

	oc = sub_vec3(ray->origin, cylinder->base1);
	dir = pre_compute_coef(ray->dir, cylinder->dir);
	ocdir = pre_compute_coef(oc, cylinder->dir);
	quad_coef = get_quad_coef(dir, ocdir, cylinder->radius);
	return (solve_cylinder(cylinder, ray, quad_coef, t));
}
