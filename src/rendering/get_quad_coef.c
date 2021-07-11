/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quad_coef.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2021/07/11 16:01:06 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function computes coefficients for solving quadratic equation
*/

t_vec3	get_quad_coef(t_vec3 dir, t_vec3 oc, double radius)
{
	t_vec3	result;

	result.x = quadnorm_vec3(dir);
	result.y = DBL_UNIT * dot_vec3(dir, oc);
	result.z = quadnorm_vec3(oc) - ft_sqr(radius);
	return (result);
}
