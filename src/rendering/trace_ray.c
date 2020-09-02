/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/02 22:24:38 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		set_secondary_ray(t_lstobj *hit_obj, t_ray *ray)
{
	ray->vcolor = get_obj_color(hit_obj);
	ray->hit_p = get_hit_point(ray->origin, ray->t_nearest, ray->dir);
	get_obj_normal(hit_obj, ray, ray->hit_p);
	ray->hit_p = add_vec3(ray->hit_p, scale_vec3(EPSILON, ray->normal));
}

static void		shade(t_minirt *env, t_ray *ray)
{
	t_lstobj	*hit_obj;

	hit_obj = trace_ray_to_objs(env->objs, ray);
	if (hit_obj)
	{
		set_secondary_ray(hit_obj, ray);
		trace_ray_to_lights(env, ray);
	}
}

/*
** This function sets the ray origin and iterates over all pixels in the image.
** At each pixel, it sets the ray direction, casts the ray and
** retrieves the ray color to put it in the image.
*/

void			trace_ray(t_minirt *env, t_cam *cam, t_img *img)
{
	t_ray		ray;
	int			x;
	int			y;
	int			progress;

	look_at(cam);
	set_ray_origin(&ray, cam->pos);
	y = 0;
	while (y < env->res.size_y)
	{
		x = 0;
		while (x < env->res.size_x)
		{
			set_ray_dir(env, &ray, x, y);
			shade(env, &ray);
			put_pixel_to_image(img, ray.vcolor, x, y);
			x++;
		}
		y++;
		progress = y * 100 / env->res.size_y;
		ft_printf("\rRendering image... %d%%", progress);
	}
	ft_printf("\n");
}
