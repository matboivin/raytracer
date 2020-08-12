/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/12 18:40:04 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	update_ray_nearest(t_ray *ray, double root1, double root2)
{
	if (root2 <= 0.0)
		root2 = root1;
	if ((root1 <= 0.0) || (root1 > root2))
		root1 = root2;
	ray->t_nearest = root1;
}

bool		solve_quadratic(t_ray *ray, double a, double b, double c)
{
	double	discriminant;
	double	q;
	double	root1;
	double	root2;

	discriminant = ft_sqr(b) - (4 * a * c);
	if (discriminant < 0)
		return (false);
	else if (discriminant == 0)
		ray->t_nearest = -(0.5 * (b / a));
	else if (discriminant > 0)
	{
		if (b > 0)
			q = -0.5 * (b + sqrt(discriminant));
		else
			q = -0.5 * (b - sqrt(discriminant));
		root1 = q / a;
		root2 = c / q;
		if ((root1 <= 0.0 && root2 <= 0.0)
			|| (root1 > ray->t_nearest && root2 > ray->t_nearest))
			return (false);
		update_ray_nearest(ray, root1, root2);
	}
	return (true);
}
