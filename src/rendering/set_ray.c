/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/01 22:32:11 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Set ray
**
** set_viewdist()   :  Set distance between camera and viewplane
** set_camera_ray() :  Initialize ray from camera position
** set_ray_dir()    :  Set direction of ray
*/

void	set_viewdist(t_cam *cam)
{
	cam->viewplane_d = (g_app->win_x * 0.5) * tan(cam->fov * 0.5);
}

void	set_camera_ray(t_scene *scene, t_ray *ray)
{
	ray->origin = scene->main_cam->pos;
	ray->dir = scene->main_cam->rot;
	set_viewdist(scene->main_cam);
	ray->t = 0.0;
}

void	set_ray_dir(t_ray *ray, int x, int y)
{
	(void)ray;
	(void)x;
	(void)y;
	//ray->dir = ;
}
