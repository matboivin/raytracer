/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ambient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/07 18:32:00 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function parses Ambient light
*/

void		get_ambient(t_minirt *env, char **input)
{
	if (env->ambient.is_declared)
		exit_error(env, AMB_DUP);
	env->ambient.is_declared = true;
	(*input) += 2;
	env->ambient.ratio = get_double(env, input);
	if (!ft_f_range(env->ambient.ratio, 0.0, 1.0))
		exit_error(env, AMB_FMT);
	env->ambient.vcolor = get_color(env, input);
	env->ambient.vcolor = scale_vec3((1.0 / MAX_RGB), env->ambient.vcolor);
	check_null_light(&(env->ambient.vcolor), &(env->ambient.ratio));
	skip_blank(input);
}
