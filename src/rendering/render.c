/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/05 01:17:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Render image
**
** cast_ray()       :  Computes the color at the intersection point of a ray
** render()         :  Fills image starting from pos (0,0)
** generate_image() :  Generate the rendered image
*/

t_color			cast_ray(t_scene *scene, t_ray *ray)
{
	t_color		default_color;
	t_color		hit_color;
	t_lstobj	*hit_obj;

	default_color = create_color(0, 0, 0);
	hit_obj = trace(scene, ray);
	if (hit_obj)
	{
		hit_color = shading(scene, ray, hit_obj);
		return (hit_color);
	}
	return (default_color);
}

void			render(t_scene *scene)
{
	t_mat4x4	cam_to_world;
	t_ray		ray;
	t_color		ray_color;
	int			x;
	int			y;

	cam_to_world = look_at(scene->main_cam);
	set_ray_pos(scene->main_cam, &ray, cam_to_world);
	y = 0;
	while (y < g_app->win_y)
	{
		x = 0;
		while (x < g_app->win_x)
		{
			set_ray_dir(&ray, cam_to_world, get_pixel_coord(scene, x, y));
			ray_color = cast_ray(scene, &ray);
			put_pixel_to_image(g_app->img, ray_color, x, y);
			x++;
		}
		y++;
	}
}

void			generate_image(t_scene *scene)
{
	g_app->img = malloc_image();
	render(scene);
	if ((scene->res.size_x < 400) || (scene->res.size_y < 400))
		put_warn_res();
}
