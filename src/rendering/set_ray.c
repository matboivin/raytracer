/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/04 23:58:00 by mboivin          ###   ########.fr       */
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

// viewplane_d = (g_app->win_x * 0.5) * tan(cam->fov * 0.5);

void	reset_ray_nearest(t_ray *ray)
{
	ray->t_nearest = __DBL_MAX__;
}

void	set_camera_ray(t_ray *ray, int x, int y, t_mat4x4 mat)
{
	t_vec4	vec;

	vec = create_vec4(x, y, -1, 1);
	ray->dir = mult_mat4x4_vec4(mat, vec);
	reset_ray_nearest(ray);
}

void	create_camera_ray(t_scene *scene, t_ray *ray, t_mat4x4 mat)
{
	t_vec4	vec;

	vec = create_vec4(scene->main_cam->pos.x, scene->main_cam->pos.y, scene->main_cam->pos.z, 1);
	ray->origin = mult_mat4x4_vec4(mat, vec);
	ray->t_nearest = __DBL_MAX__;
}
