/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/06 23:17:29 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function parses light information
*/

static t_light	*parse_light(t_minirt *env, char **input)
{
	t_light		*result;

	result = (t_light *)malloc(sizeof(t_light));
	if (!result)
		exit_error(env, DEFAULT_ERR);
	result->pos = get_vec3(env, input);
	result->ratio = get_double(env, input);
	if (!ft_f_range(result->ratio, DEFAULT_VALUE, UNIT_VALUE))
		exit_error(env, LIGHT_FMT);
	result->vcolor = get_color(env, input);
	check_null_light(&(result->vcolor), &(result->ratio));
	result->vcolor = scale_vec3((UNIT_VALUE / MAX_RGB), result->vcolor);
	return (result);
}

/*
** This function adds a light to scene
*/

void			get_light(t_minirt *env, char **input)
{
	t_light		*light_data;
	t_lights	*new_light;

	(*input) += ID_LEN;
	light_data = parse_light(env, input);
	new_light = create_light(light_data);
	if (!new_light)
		exit_error(env, DEFAULT_ERR);
	append_light(&(env->lights), new_light);
	skip_blank(input);
}
