/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/31 22:47:54 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function solves quadratic equation for a sphere
*/

static bool	solve_quadratic_sphere(t_ray *ray, t_vec3 quad_coef)
{
	double	root1;
	double	root2;

	if (get_quad_roots(&root1, &root2, quad_coef) == true)
	{
		if ((root1 <= EPSILON && root2 <= EPSILON)
		|| (root1 >= ray->t_nearest && root2 >= ray->t_nearest))
			return (false);
		if (root1 <= EPSILON)
			root1 = root2;
		if (root2 <= EPSILON)
			root2 = root1;
		ray->t_nearest = fmin(root1, root2);
		return (true);
	}
	return (false);
}

/*
** This function handles intersection with a sphere
** If a sphere is intersected, t_nearest is updated and true is returned
*/

bool		hit_sphere(t_sphere *sphere, t_ray *ray)
{
	t_vec3	quad_coef;
	t_vec3	oc;

	oc = sub_vec3(ray->origin, sphere->center);
	quad_coef = get_quad_coef(ray->dir, oc, sphere->radius);
	return (solve_quadratic_sphere(ray, quad_coef));
}
