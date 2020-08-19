/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quad_coeff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/19 18:50:13 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function computes the coefficients for solving quadratic equation
*/

t_vec3	get_quad_coeff(t_vec3 origin, t_vec3 dir, t_vec3 center, double radius)
{
	t_vec3	result;
	t_vec3	l;

	l = sub_vec3(origin, center);
	result.x = quadnorm_vec3(dir);
	result.y = 2.0 * dot_vec3(dir, l);
	result.z = quadnorm_vec3(l) - ft_sqr(radius);
	return (result);
}
