/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/21 19:16:30 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function parses light points
*/

t_light			*create_light(t_scene *scene, char **input)
{
	t_light		*result;

	result = (t_light *)malloc(sizeof(t_light));
	if (result == NULL)
		exit_error(scene, DEFAULT_ERR);
	result->pos = get_vec3(scene, input);
	result->ratio = get_double(scene, input);
	if (ft_f_range(result->ratio, 0.0, 1.0) == false)
		exit_error(scene, LIGHT_FMT);
	result->color = get_color(scene, input);
	return (result);
}

/*
** This function adds light spot to scene
*/

void			get_light(t_scene *scene, char **input)
{
	t_light		*light_data;
	t_lstlight	*new_light;

	(*input) += 2;
	light_data = create_light(scene, input);
	new_light = new_lstlight(light_data);
	if (new_light == NULL)
		exit_error(scene, DEFAULT_ERR);
	lstlight_add_back(&(scene->lights), new_light);
	skip_blank(input);
}
