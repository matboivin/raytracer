/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/31 22:35:37 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function checks whether the intersection point lies in cylinder
*/

static bool		is_inside_cyl(t_cyl *cylinder, t_ray *ray, double t)
{
	t_vec3		hit_p;
	t_vec3		bottom;
	t_vec3		top;

	hit_p = get_hit_point(ray->origin, t, ray->dir);
	bottom = sub_vec3(hit_p, cylinder->base1);
	top = sub_vec3(hit_p, cylinder->base2);
	if ((dot_vec3(cylinder->dir, bottom) > 0)
		&& (dot_vec3(cylinder->dir, top) < 0))
		return (true);
	return (false);
}

/*
** This function solves quadratic equation
*/

static bool		solve_quadratic_cyl(
	t_cyl *cylinder, t_ray *ray, t_vec3 quad_coef)
{
	double		root1;
	double		root2;

	if (get_quad_roots(&root1, &root2, quad_coef) == true)
	{
		if ((root1 <= EPSILON && root2 <= EPSILON)
			|| (root1 >= ray->t_nearest && root2 >= ray->t_nearest))
			return (false);
		if ((is_inside_cyl(cylinder, ray, root1) == false)
			&& (is_inside_cyl(cylinder, ray, root2) == false))
			return (false);
		if (is_inside_cyl(cylinder, ray, root1) == false)
			root1 = root2;
		if (is_inside_cyl(cylinder, ray, root2) == false)
			root2 = root1;
		ray->t_nearest = fmin(root1, root2);
		return (true);
	}
	return (false);
}

/*
** This function helps computing coefficients for solving quadratic equation
*/

static t_vec3	pre_compute_coef(t_vec3 v, t_vec3 dir)
{
	t_vec3		result;

	result = sub_vec3(v, scale_vec3(dot_vec3(v, dir), dir));
	return (result);
}

/*
** This function handles intersection with a cylinder
** If a cylinder is intersected, t_nearest is updated and true is returned
*/

bool			hit_cylinder(t_cyl *cylinder, t_ray *ray)
{
	t_vec3		quad_coef;
	t_vec3		dist;
	t_vec3		tmp_a;
	t_vec3		tmp_b;

	dist = sub_vec3(ray->origin, cylinder->base1);
	tmp_a = pre_compute_coef(ray->dir, cylinder->dir);
	tmp_b = pre_compute_coef(dist, cylinder->dir);
	quad_coef = get_quad_coef(tmp_a, tmp_b, cylinder->radius);
	return (solve_quadratic_cyl(cylinder, ray, quad_coef));
}
