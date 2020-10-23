/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ambient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/24 01:14:12 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_num.h"
#include "minirt.h"

/*
** This function parses Ambient light
*/

void		get_ambient(t_minirt *env, char **input)
{
	if (env->ambient.is_declared)
		exit_error(env, AMB_DUP);
	env->ambient.is_declared = true;
	(*input) += ID_LEN;
	env->ambient.ratio = get_double(env, input);
	if (!ft_f_range(env->ambient.ratio, DEFAULT_VALUE, UNIT_VALUE))
		exit_error(env, AMB_FMT);
	env->ambient.vcolor = get_color(env, input);
	check_null_light(&(env->ambient.vcolor), &(env->ambient.ratio));
	env->ambient.vcolor = scale_vec3(
		(UNIT_VALUE / MAX_RGB),
		env->ambient.vcolor);
	skip_blank(input);
}
