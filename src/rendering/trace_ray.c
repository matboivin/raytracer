/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/26 20:30:15 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		set_secondary_ray(t_lstobj *hit_obj, t_ray *ray)
{
	ray->obj_color = get_obj_color(hit_obj);
	ray->hit_p = get_hit_point(ray->origin, ray->t_nearest, ray->dir);
	ray->normal = get_obj_normal(hit_obj, ray, ray->hit_p);
}

static void		shade(t_scene *scene, t_ray *ray)
{
	t_lstobj	*hit_obj;

	hit_obj = trace_ray_to_objs(scene->objs, ray);
	if (hit_obj)
	{
		set_secondary_ray(hit_obj, ray);
		trace_ray_to_lights(scene->objs, scene->lights, ray);
	}
}

/*
** This function sets the ray origin and iterates over all pixels in the image.
** At each pixel, it sets the ray direction, casts the ray and
** retrieves the ray color to put it in the image.
*/

void			trace_ray(t_scene *scene, t_cam *cam)
{
	t_ray		ray;
	int			x;
	int			y;
	int			progress;

	look_at(cam);
	set_ray_origin(&ray, cam->pos);
	y = 0;
	while (y < g_app->win_y)
	{
		x = 0;
		while (x < g_app->win_x)
		{
			set_ray_dir(scene, &ray, x, y);
			shade(scene, &ray);
			put_pixel_to_image(cam->img, ray.vcolor, x, y);
			x++;
		}
		y++;
		progress = y * 100 / g_app->win_y;
		ft_printf("\rRendering image... %d%%", progress);
	}
	ft_printf("\n");
}
