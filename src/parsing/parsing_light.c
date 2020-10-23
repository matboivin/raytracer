/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/24 01:14:18 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_num.h"
#include "minirt.h"

/*
** This function parses light information
*/

static void	parse_light(t_minirt *env, char **input, t_light *light)
{
	light->pos = get_vec3(env, input);
	light->ratio = get_double(env, input);
	if (!ft_f_range(light->ratio, DEFAULT_VALUE, UNIT_VALUE))
		exit_error(env, LIGHT_FMT);
	light->vcolor = get_color(env, input);
	check_null_light(&(light->vcolor), &(light->ratio));
	light->vcolor = scale_vec3((UNIT_VALUE / MAX_RGB), light->vcolor);
}

/*
** This function adds a light to env
*/

void		get_light(t_minirt *env, char **input)
{
	t_light	*new_light;

	(*input) += ID_LEN;
	new_light = malloc_light(env);
	parse_light(env, input, new_light);
	append_light(&(env->lights), new_light);
	skip_blank(input);
}
