/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:29:07 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/27 00:09:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Initialize scene elements
**
** create_resolution()
** create_ambient()
** create_cam()
** create_light()
** create_scene()
*/

void	create_resolution(t_res *res)
{
	res->is_declared = false;
	res->size_x = 0;
	res->size_y = 0;
}

void	create_ambient(t_amb *amb)
{
	amb->is_declared = false;
	amb->ratio = 0.0;
	amb->color = create_color(0, 0, 0);
}

void	create_cam(t_cam *cam)
{
	cam->pos = create_point3(0.0, 0.0, 0.0);
	cam->rot = create_point3(0.0, 0.0, 0.0);
	cam->fov = 0.0;
}

void	create_light(t_light *light)
{
	light->pos = create_point3(0.0, 0.0, 0.0);
	light->ratio = 0.0;
	light->color = create_color(0, 0, 0);
}

void	create_scene(t_scene *scene)
{
	create_resolution(&scene->res);
	create_ambient(&scene->amb);
	create_cam(&scene->cam);
	create_light(&scene->light);
	create_sphere(&scene->sphere);
	create_square(&scene->square);
	create_plane(&scene->plane);
	create_cylinder(&scene->cylinder);
	create_triangle(&scene->triangle);
}

void	destroy_scene(t_scene *to_destroy)
{
	(void)to_destroy;
}
