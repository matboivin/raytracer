/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_op3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:38:29 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/27 23:37:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3		add_vec3(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

t_vec3		sub_vec3(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result = add_vec3(a, scale_vec3(-1, b));
	return (result);
}

t_vec3		mult_vec3(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x * b.x;
	result.y = a.y * b.y;
	result.z = a.z * b.z;
	return (result);
}

t_vec3		div_vec3(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x / b.x;
	result.y = a.y / b.y;
	result.z = a.z / b.z;
	return (result);
}

t_vec3		scale_vec3(double scalar, t_vec3 vec)
{
	t_vec3	result;

	result.x = scalar * vec.x;
	result.y = scalar * vec.y;
	result.z = scalar * vec.z;
	return (result);
}
