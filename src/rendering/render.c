/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/12 00:29:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function casts a ray. If an object is intersected, it processes shading
** and final color is returned. Else, default color is returned.
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

/*
** This function creates a cam_to_world matrix,
** sets the ray origin and iterates over all pixels in the image.
** At each pixel, it sets the ray direction, casts the ray and
** retrieves the ray color to put it in the image.
*/

void			render(t_scene *scene)
{
	t_mat3x3	cam_to_world3;
	t_mat4x4	cam_to_world4;
	t_ray		ray;
	t_color		ray_color;
	int			x;
	int			y;

	cam_to_world4 = look_at(scene->main_cam); // tmp
	cam_to_world3 = create_camtoworld3(cam_to_world4); // tmp
	set_ray_origin(&ray, cam_to_world4);
	y = 0;
	while (y < g_app->win_y)
	{
		x = 0;
		while (x < g_app->win_x)
		{
			set_ray_dir(&ray, cam_to_world3, get_pixel_coord(scene, x, y));
			ray_color = cast_ray(scene, &ray);
			put_pixel_to_image(g_app->img, ray_color, x, y);
			x++;
		}
		y++;
	}
}

/*
** This function creates an image and starts rendering
*/

void			generate_image(t_scene *scene)
{
	g_app->img = malloc_image();
	render(scene);
	if ((scene->res.size_x < 400) || (scene->res.size_y < 400))
		put_warn_res();
}
