/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/08 00:55:41 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	reset_ray(t_ray *ray)
{
	ray->t_nearest = INFINITY;
	ray->vcolor = create_vec3(0.0, 0.0, 0.0);
	ray->hit_p = create_vec3(0.0, 0.0, 0.0);
	ray->normal = create_vec3(0.0, 0.0, 0.0);
}

void		set_ray_dir(t_cam *cam, t_ray *ray, t_vec3 pixel_coord)
{
	ray->dir = mult_mat3x3_vec3(
		cam->cam_to_world3,
		pixel_coord);
	ray->dir = normalize_vec3(ray->dir);
	reset_ray(ray);
}
