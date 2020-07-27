/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_prod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:38:29 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/28 00:23:12 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		dot_vec3(t_vec3 a, t_vec3 b)
{
	t_vec3	vec;
	double	product;

	vec = mult_vec3(a, b);
	product = vec.x + vec.y + vec.z;
	return (product);
}

t_vec3		cross(t_vec3 a, t_vec3 b)
{
	t_vec3	product;

	product.x = a.y * b.z - b.y * a.z;
	product.y = a.z * b.x - b.z * a.x;
	product.z = a.x * b.y - b.x * a.y;
	return (product);
}
