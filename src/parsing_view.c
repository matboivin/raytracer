/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/23 22:47:26 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_resolution(t_scene *scene, char **input)
{
	if (scene->res.is_declared == true)
		exit_error(scene, RES_DUP);
	scene->res.is_declared = true;
	(*input) += 2;
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
	(*input) += 2;
	scene->amb.ratio = get_double(scene, input);
	if (ft_f_range(scene->amb.ratio, 0.0, 1.0) == false)
		exit_error(scene, AMB_FMT);
	scene->amb.color = get_color(scene, input);
	skip_whitespaces(input);
}

void	get_cam(t_scene *scene, char **input)
{
	(*input) += 2;
	scene->cam.pos = get_coord3(scene, input);
	scene->cam.rot = get_coord3(scene, input);
	if (ft_coord3_range(scene->cam.rot, -1.0, 1.0) == false)
		exit_error(scene, CAM_FMT);
	scene->cam.fov = get_integer(scene, input);
	if (ft_n_range(scene->cam.fov, 0, 180) == false)
		exit_error(scene, CAM_FMT);
	skip_whitespaces(input);
}

void	get_light(t_scene *scene, char **input)
{
	(*input) += 2;
	scene->light.pos = get_coord3(scene, input);
	scene->light.ratio = get_double(scene, input);
	if (ft_f_range(scene->light.ratio, 0.0, 1.0) == false)
		exit_error(scene, LIGHT_FMT);
	scene->light.color = get_color(scene, input);
	skip_whitespaces(input);
}
