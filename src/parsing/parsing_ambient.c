/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ambient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/30 01:37:55 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function parses Ambient light
*/

void		get_ambient(t_minirt *env, char **input)
{
	if (env->ambient.is_declared == true)
		exit_error(env, AMB_DUP);
	env->ambient.is_declared = true;
	(*input) += 2;
	env->ambient.ratio = get_double(env, input);
	if (ft_f_range(env->ambient.ratio, 0.0, 1.0) == false)
		exit_error(env, AMB_FMT);
	env->ambient.vcolor = get_color(env, input);
	check_null_light(&(env->ambient.vcolor), &(env->ambient.ratio));
	env->ambient.vcolor = scale_vec3((1.0 / 255.0), env->ambient.vcolor);
	skip_blank(input);
}
