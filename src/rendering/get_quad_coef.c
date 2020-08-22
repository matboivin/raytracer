/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quad_coef.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/22 18:46:21 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function computes coefficients for solving quadratic equation
*/

t_vec3		get_quad_coef(t_vec3 a, t_vec3 b, double radius)
{
	t_vec3	result;

	result.x = quadnorm_vec3(a);
	result.y = 2.0 * dot_vec3(a, b);
	result.z = quadnorm_vec3(b) - ft_sqr(radius);
	return (result);
}
