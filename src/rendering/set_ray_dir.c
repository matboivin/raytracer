/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/25 22:56:05 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function converts pixel to World coordinates
*/

static t_vec3	get_pixel_coord(double fov, t_res res, int x, int y)
{
	t_vec3		result;
	double		scale;
	double		pixel_x;
	double		pixel_y;
	double		aspect_ratio;

	aspect_ratio = (double)res.size_x / (double)res.size_y;
	scale = tan(degrees_to_radians(fov * 0.5));
	pixel_x = (
		2 * (x + 0.5) / (double)res.size_x - 1) * aspect_ratio * scale;
	pixel_y = (
		1 - 2 * (y + 0.5) / (double)res.size_y) * scale;
	result = create_vec3(pixel_x, pixel_y, 1);
	return (result);
}

static void		reset_ray(t_ray *ray)
{
	ray->t_nearest = __DBL_MAX__;
	ray->obj_color = create_vec3(0.0, 0.0, 0.0);
	ray->color = create_vec3(0.0, 0.0, 0.0);
	ray->hit_p = create_vec3(0.0, 0.0, 0.0);
	ray->normal = create_vec3(0.0, 0.0, 0.0);
	// ray->color = create_vec3(255.0, 255.0, 255.0);
}

/*
** This function sets the ray direction
**
** t_nearest is reset to max double value at each ray cast
*/

void			set_ray_dir(t_ray *ray, t_scene *scene, int x, int y)
{
	t_vec3		pixel_coord;

	pixel_coord = get_pixel_coord(
		scene->cameras->cam->fov,
		scene->res,
		x,
		y);
	ray->dir = mult_mat3x3_vec3(
		scene->cameras->cam->cam_to_world3,
		pixel_coord);
	ray->dir = normalize_vec3(ray->dir);
	reset_ray(ray);
}
