/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_res.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/22 21:41:32 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_resolution(t_scene *scene, char **input)
{
	if (scene->res.is_declared == true)
		exit_error(scene, RES_DUP);
	scene->res.is_declared = true;
	(*input)++;
	scene->res.size_x = get_integer(scene, input);
	scene->res.size_y = get_integer(scene, input);
	if (scene->res.size_x < 1 || scene->res.size_y < 1)
		exit_error(scene, RES_NEG);
	g_app->win_x = scene->res.size_x;
	g_app->win_y = scene->res.size_y;
	skip_whitespaces(input);
}

void	get_ambient(t_scene *scene, char **input)
{
	if (scene->amb.is_declared == true)
		exit_error(scene, AMB_DUP);
	scene->amb.is_declared = true;
	(*input)++;
	scene->amb.ratio = get_double(scene, input);
	scene->amb.color = get_color(scene, input);
	skip_whitespaces(input);
}
