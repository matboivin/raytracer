/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specular.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/30 14:35:39 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		get_specular(
	t_ray *ray, t_light *light, t_vec3 light_dir, double angle)
{
	t_vec3	rev_dir;
	t_vec3	reflect;
	double	coef;

	coef = DEFAULT_VALUE;
	rev_dir = scale_vec3(REVUNIT_VALUE, ray->dir);
	reflect = sub_vec3(
		scale_vec3(2 * angle, ray->normal), normalize_vec3(light_dir));
	if (dot_vec3(reflect, rev_dir) > 0.0)
		coef = light->ratio * pow(cos_vec3(reflect, rev_dir), SPECULAR_COEF);
	return (coef);
}
