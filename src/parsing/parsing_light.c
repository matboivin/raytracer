/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/26 23:06:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function parses light information
*/

static t_light	*create_light(t_minirt *env, char **input)
{
	t_light		*result;

	result = (t_light *)malloc(sizeof(t_light));
	if (result == NULL)
		exit_error(env, DEFAULT_ERR);
	result->pos = get_vec3(env, input);
	result->ratio = get_double(env, input);
	if (ft_f_range(result->ratio, 0.0, 1.0) == false)
		exit_error(env, LIGHT_FMT);
	result->vcolor = get_color(env, input);
	result->vcolor = scale_vec3(result->ratio, result->vcolor);
	return (result);
}

/*
** This function adds a light to scene
*/

void			get_light(t_minirt *env, char **input)
{
	t_light		*light_data;
	t_lstlight	*new_light;

	(*input) += 2;
	light_data = create_light(env, input);
	new_light = new_lstlight(light_data);
	if (new_light == NULL)
		exit_error(env, DEFAULT_ERR);
	lstlight_add_back(&(env->lights), new_light);
	skip_blank(input);
}
