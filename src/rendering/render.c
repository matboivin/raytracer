/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/05 00:13:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Render image
**
** cast_ray()       :  Computes the color at the intersection point of a ray
** fill_image()     :  Fills the image starting from pos (0,0)
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
	int			i;
	int			j;
	double		aspect_ratio;
	double		scale;

	aspect_ratio = g_app->win_x / g_app->win_y;
	scale = tan(degrees_to_radians(scene->main_cam->fov * 0.5));
	cam_to_world = look_at(scene->main_cam);
	create_camera_ray(scene, &ray, cam_to_world);
	j = 0;
	while (j < g_app->win_y)
	{
		i = 0;
		while (i < g_app->win_x)
		{
			x = (2 * (i + 0.5) / g_app->win_x - 1) * aspect_ratio * scale;
			y = (1 - 2 * (j + 0.5) / g_app->win_y) * scale;
			set_camera_ray(&ray, x, y, cam_to_world);
			ray_color = cast_ray(scene, &ray);
			put_pixel_to_image(g_app->img, ray_color, i, j);
			i++;
		}
		j++;
	}
}

void			generate_image(t_scene *scene)
{
	g_app->img = malloc_image();
	render(scene);
	if ((scene->res.size_x < 400) || (scene->res.size_y < 400))
		put_warn_res();
}
