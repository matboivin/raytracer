/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quad_coef.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/31 23:02:11 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function computes coefficients for solving quadratic equation
*/

t_vec3		get_quad_coef(t_vec3 dir, t_vec3 oc, double radius)
{
	t_vec3	result;

	result.x = quadnorm_vec3(dir);
	result.y = 2.0 * dot_vec3(dir, oc);
	result.z = quadnorm_vec3(oc) - ft_sqr(radius);
	return (result);
}
