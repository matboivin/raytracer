/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/27 00:09:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Parse properties
**
** get_resolution()
** get_ambient()
** get_cam()
** get_light()
*/

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

void	get_cam(t_scene *scene, char **input)
{
	(*input) += 2;
	scene->cam.pos = get_point3(scene, input);
	scene->cam.rot = get_point3(scene, input);
	if (ft_point3_range(scene->cam.rot, -1.0, 1.0) == false)
		exit_error(scene, CAM_FMT);
	scene->cam.fov = get_integer(scene, input);
	if (ft_n_range(scene->cam.fov, 0, 180) == false)
		exit_error(scene, CAM_FMT);
	skip_blank(input);
}

void	get_light(t_scene *scene, char **input)
{
	(*input) += 2;
	scene->light.pos = get_point3(scene, input);
	scene->light.ratio = get_double(scene, input);
	if (ft_f_range(scene->light.ratio, 0.0, 1.0) == false)
		exit_error(scene, LIGHT_FMT);
	scene->light.color = get_color(scene, input);
	skip_blank(input);
}
