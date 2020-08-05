/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/05 21:52:05 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Parse global render settings
**
** Resolution
** Ambient light
*/

void	get_resolution(t_scene *scene, char **input)
{
	if (scene->res.is_declared == true)
		exit_error(scene, RES_DUP);
	scene->res.is_declared = true;
	(*input) += 2;
	scene->res.size_x = get_integer(scene, input);
	scene->res.size_y = get_integer(scene, input);
	if ((scene->res.size_x < 1) || (scene->res.size_y < 1))
		exit_error(scene, RES_NEG);
	if ((scene->res.size_x < 100) || (scene->res.size_y < 100))
		exit_error(scene, RES_MIN);
	scene->aspect_ratio = scene->res.size_x / scene->res.size_y;
	skip_blank(input);
}

void	get_ambient(t_scene *scene, char **input)
{
	if (scene->amb.is_declared == true)
		exit_error(scene, AMB_DUP);
	scene->amb.is_declared = true;
	(*input) += 2;
	scene->amb.ratio = get_double(scene, input);
	if (ft_f_range(scene->amb.ratio, 0.0, 1.0) == false)
		exit_error(scene, AMB_FMT);
	scene->amb.color = get_color(scene, input);
	skip_blank(input);
}
