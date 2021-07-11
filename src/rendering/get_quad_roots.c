/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quad_roots.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2021/07/11 16:01:01 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

/*
** This function finds the roots using the quadratic formula
*/

bool	get_quad_roots(double *root1, double *root2, t_vec3 quad_coef)
{
	double	discr;

	discr = ft_sqr(quad_coef.y) - (QUAD_UNIT * quad_coef.x * quad_coef.z);
	if (discr < 0.0)
		return (false);
	*root1 = (-quad_coef.y + sqrt(discr)) / (DBL_UNIT * quad_coef.x);
	*root2 = (-quad_coef.y - sqrt(discr)) / (DBL_UNIT * quad_coef.x);
	return (true);
}
