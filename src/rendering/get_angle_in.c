/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_angle_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/26 01:01:10 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3		get_light_dir(t_vec3 pos, t_vec3 hit_p)
{
	return (normalize_vec3(sub_vec3(pos, hit_p)));
}

/*
** This function computes the angle of incidence (coming light)
*/

double		get_angle_in(t_vec3 normal, t_vec3 light_dir)
{
	return (dot_vec3(normal, light_dir));
}
