/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/19 19:12:25 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function finds the roots using the quadratic formula
*/

static bool	get_quad_roots(double *root1, double *root2, t_vec3 quad_coef)
{
	double	discr;
	double	q;

	discr = ft_sqr(quad_coef.y) - (4 * quad_coef.x * quad_coef.z);
	if (discr < 0)
		return (false);
	else if (discr == 0)
	{
		*root1 = -(0.5 * (quad_coef.y / quad_coef.x));
		*root2 = -(0.5 * (quad_coef.y / quad_coef.x));
	}
	else if (discr > 0)
	{
		discr = sqrt(discr);
		if (quad_coef.y > 0)
			q = -0.5 * (quad_coef.y + discr);
		else
			q = -0.5 * (quad_coef.y - discr);
		*root1 = q / quad_coef.x;
		*root2 = quad_coef.z / q;
	}
	return (true);
}

/*
** This function solves quadratic equation
**
** quad_coef.x = a
** quad_coef.y = b
** quad_coef.z = c
*/

bool		solve_quadratic(t_ray *ray, t_vec3 quad_coef)
{
	double	root1;
	double	root2;

	if (get_quad_roots(&root1, &root2, quad_coef) == true)
	{
		if ((root1 <= 0.0 && root2 <= 0.0)
		|| (root1 > ray->t_nearest && root2 > ray->t_nearest))
			return (false);
		if (root2 <= 0.0)
			root2 = root1;
		if ((root1 <= 0.0) || (root1 > root2))
			root1 = root2;
		ray->t_nearest = root1;
		return (true);
	}
	return (false);
}
