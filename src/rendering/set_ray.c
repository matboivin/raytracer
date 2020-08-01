/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/01 23:25:26 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Set ray
**
** set_viewdist()      :  Set distance between camera and viewplane
** reset_ray_nearest() :  Reset t_nearest to max double value
** set_camera_ray()    :  Set direction of ray and reset t_nearest
** create_camera_ray() :  Initialize ray from camera position
*/

void	set_viewdist(t_cam *cam)
{
	cam->viewplane_d = (g_app->win_x * 0.5) * tan(cam->fov * 0.5);
}

void	reset_ray_nearest(t_ray *ray)
{
	ray->t_nearest = __DBL_MAX__;
}

void	set_camera_ray(t_ray *ray, int x, int y)
{
	(void)x;
	(void)y;
	//ray->dir = ;
	reset_ray_nearest(ray);
}

void	create_camera_ray(t_scene *scene, t_ray *ray)
{
	ray->origin = scene->main_cam->pos;
	ray->dir = scene->main_cam->rot;
	ray->t_nearest = __DBL_MAX__;
	set_viewdist(scene->main_cam);
}
