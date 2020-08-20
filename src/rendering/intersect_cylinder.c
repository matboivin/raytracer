/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/20 22:49:50 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function checks whether the intersection point lies in cylinder
*/

static bool		is_inside_cyl(t_cyl *cylinder, t_ray *ray, double t)
{
	t_vec3		inter_p;
	t_vec3		ymin;
	t_vec3		ymax;

	inter_p = get_intersection_point(ray->origin, t, ray->dir);
	ymin = sub_vec3(inter_p, cylinder->base1);
	ymax = sub_vec3(inter_p, cylinder->base2);
	if ((dot_vec3(cylinder->dir, ymin) > 0)
		&& (dot_vec3(cylinder->dir, ymax) < 0))
		return (true);
	return (false);
}

/*
** This function solves quadratic equation
**
** quad_coef.x = a
** quad_coef.y = b
** quad_coef.z = c
*/

static bool		solve_quadratic_cyl(
	t_cyl *cylinder, t_ray *ray, t_vec3 quad_coef)
{
	double		root1;
	double		root2;

	if (get_quad_roots(&root1, &root2, quad_coef) == true)
	{
		if ((root1 <= 0.0 && root2 <= 0.0)
			|| (root1 > ray->t_nearest && root2 > ray->t_nearest))
			return (false);
		if ((is_inside_cyl(cylinder, ray, root1) == false)
			&& (is_inside_cyl(cylinder, ray, root2) == false))
			return (false);
		if (is_inside_cyl(cylinder, ray, root1) == false)
			root1 = root2;
		if (is_inside_cyl(cylinder, ray, root2) == false)
			root2 = root1;
		if (root1 > root2)
			root1 = root2;
		ray->t_nearest = root1;
		return (true);
	}
	return (false);
}

/*
** This function helps computing coefficients for solving quadratic equation
*/

static t_vec3	pre_compute_coeff(t_vec3 v, t_vec3 dir)
{
	t_vec3		result;

	result = sub_vec3(v, scale_vec3(dot_vec3(v, dir), dir));
	return (result);
}

/*
** This function handles intersection with a cylinder
** If a cylinder is intersected, t_nearest is updated and true is returned.
*/

bool			intersect_cylinder(t_cyl *cylinder, t_ray *ray)
{
	t_vec3		quad_coef;
	t_vec3		l;
	t_vec3		tmp_a;
	t_vec3		tmp_b;

	l = sub_vec3(ray->origin, cylinder->base1);
	tmp_a = pre_compute_coeff(ray->dir, cylinder->dir);
	tmp_b = pre_compute_coeff(l, cylinder->dir);
	quad_coef.x = quadnorm_vec3(tmp_a);
	quad_coef.y = 2.0 * dot_vec3(tmp_a, tmp_b);
	quad_coef.z = quadnorm_vec3(tmp_b) - ft_sqr(cylinder->radius);
	return (solve_quadratic_cyl(cylinder, ray, quad_coef));
}
