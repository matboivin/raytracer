/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quad_roots.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/20 22:12:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function finds the roots using the quadratic formula
*/

bool		get_quad_roots(double *root1, double *root2, t_vec3 quad_coef)
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
