/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/05 01:00:51 by mboivin          ###   ########.fr       */
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

/*
** viewplane_d = (g_app->win_x * 0.5) * tan(cam->fov * 0.5);
*/

t_vec4		get_pixels_coord(t_scene *scene, int x, int y)
{
	t_vec4	result;
	double	scale;
	int		pixel_x;
	int		pixel_y;

	scale = tan(degrees_to_radians(scene->main_cam->fov * 0.5));
	pixel_x = (2 * (x + 0.5) / g_app->win_x - 1) * scene->aspect_ratio * scale;
	pixel_y = (1 - 2 * (y + 0.5) / g_app->win_y) * scale;
	result = create_vec4(pixel_x, pixel_y, -1, 1);
	return (result);
}

void		reset_ray_nearest(t_ray *ray)
{
	ray->t_nearest = __DBL_MAX__;
}

void		set_cam_ray(t_ray *ray, t_mat4x4 mat, t_vec4 pixel_coord)
{
	ray->dir = mult_mat4x4_vec4(mat, pixel_coord);
	reset_ray_nearest(ray);
}

void		create_cam_ray(t_cam *cam, t_ray *ray, t_mat4x4 mat)
{
	t_vec4	vec;

	vec = create_vec4(cam->pos.x, cam->pos.y, cam->pos.z, 1);
	ray->origin = mult_mat4x4_vec4(mat, vec);
	ray->t_nearest = __DBL_MAX__;
}
