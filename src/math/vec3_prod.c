/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_prod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:38:29 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/29 16:32:13 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		dot_vec3(t_vec3 a, t_vec3 b)
{
	t_vec3	vec;
	double	result;

	vec = mult_vec3(a, b);
	result = vec.x + vec.y + vec.z;
	return (result);
}

t_vec3		cross(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = (a.y * b.z) - (b.y * a.z);
	result.y = (a.z * b.x) - (b.z * a.x);
	result.z = (a.x * b.y) - (b.x * a.y);
	return (result);
}
