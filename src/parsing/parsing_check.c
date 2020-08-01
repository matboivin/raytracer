/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/01 17:25:55 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Checkers for parsing
**
** check_scene()       :  Checks the scene description is valid
** check_max_display() :  Handles render size if bigger than screen size
*/

void	check_scene(t_scene *scene)
{
	if ((scene->res.is_declared == false) || (scene->amb.is_declared == false))
		exit_error(scene, MISS_RA);
	if (scene->main_cam == NULL)
		exit_error(scene, MISS_CAM);
	if (scene->lights == NULL)
		exit_error(scene, MISS_LIGHT);
}

void	check_max_display(t_scene *scene)
{
	int	max_x;
	int	max_y;

	mlx_get_screen_size(g_app->mlx_ptr, &max_x, &max_y);
	if (scene->res.size_x > max_x)
		scene->res.size_x = max_x;
	if (scene->res.size_y > max_y)
		scene->res.size_y = max_y;
	g_app->win_x = scene->res.size_x;
	g_app->win_y = scene->res.size_y;
}
