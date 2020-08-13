/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/13 22:52:23 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function checks whether the scene description is valid
*/

void		check_scene(t_scene *scene)
{
	if ((scene->res.is_declared == false) || (scene->amb.is_declared == false))
		exit_error(scene, MISS_RA);
	if (scene->main_cam == NULL)
		exit_error(scene, MISS_CAM);
	if (scene->lights == NULL)
		exit_error(scene, MISS_LIGHT);
	if (scene->objs == NULL)
		exit_error(scene, MISS_OBJ);
}

/*
** This function handles render size if bigger than screen size
*/

void		check_max_display(t_scene *scene)
{
	int		max_x;
	int		max_y;

	mlx_get_screen_size(g_app->mlx_ptr, &max_x, &max_y);
	if (scene->res.size_x > max_x)
		scene->res.size_x = max_x;
	if (scene->res.size_y > max_y)
		scene->res.size_y = max_y;
	g_app->win_x = scene->res.size_x;
	g_app->win_y = scene->res.size_y;
}

/*
** This function handles null vectors which are replaced by a default vector
*/

static bool	is_null_vector(t_vec3 *to_check)
{
	if ((to_check->x == 0.0) && (to_check->y == 0.0) && (to_check->z == 0.0))
		return (true);
	return (false);
}

void		check_null_vector(t_vec3 *to_check, t_vec3 default_vec)
{
	if (is_null_vector(to_check) == true)
		cpy_vec3(to_check, default_vec);
}
