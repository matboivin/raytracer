/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/11 21:03:44 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool		solve_quadratic(t_ray *ray, double a, double b, double c)
{
	double	t0;
	double	t1;
	double	discriminant;

	discriminant = pow(b, 2) - (4 * a * c);
	if (discriminant < 0)
		return (false);
	if (discriminant == 0)
		ray->t_nearest = (b / a) * -0.5;
	else if (discriminant > 0)
	{
		t0 = (-b + sqrt(discriminant)) / (2 * a);
		t1 = (-b - sqrt(discriminant)) / (2 * a);
		if (
			(t0 <= 0.0 && t1 <= 0.0)
			|| (t0 > ray->t_nearest && t1 > ray->t_nearest))
			return (false);
		if (t0 <= 0.0)
			t0 = t1;
		if (t1 <= 0.0)
			t1 = t0;
		ray->t_nearest = t0 < t1 ? t0 : t1;
	}
	return (true);
}
