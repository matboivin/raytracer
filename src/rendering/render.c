/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/25 01:32:16 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function creates a cam_to_world matrix,
** sets the ray origin and iterates over all pixels in the image.
** At each pixel, it sets the ray direction, casts the ray and
** retrieves the ray color to put it in the image.
*/

static void	render_image(t_scene *scene, t_cam *cam)
{
	t_ray	ray;
	t_color	ray_color;
	int		x;
	int		y;
	int		progress;

	look_at(cam);
	set_ray_origin(&ray, cam->pos);
	y = 0;
	while (y < g_app->win_y)
	{
		x = 0;
		while (x < g_app->win_x)
		{
			set_ray_dir(&ray, scene, x, y);
			ray_color = trace_ray(scene, &ray);
			put_pixel_to_image(cam->img, ray_color, x, y);
			x++;
		}
		y++;
		progress = y * 100 / g_app->win_y;
		ft_printf("\rRendering image... %d%%", progress);
	}
	ft_printf("\n");
}

static void	render_n_image(t_scene *scene, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		scene->cameras->cam->img = malloc_image();
		render_image(scene, scene->cameras->cam);
		if (g_app->img == NULL)
			g_app->img = scene->cameras->cam->img;
		scene->cameras = scene->cameras->next;
		i++;
	}
}

void		render(t_scene *scene, bool to_bmp)
{
	if (to_bmp == true)
	{
		render_n_image(scene, 1);
		save_bmp(scene, BMP_FILENAME);
	}
	ft_printf("Generating %d image(s)\n", scene->cam_count);
	render_n_image(scene, scene->cam_count);
	if ((scene->res.size_x < 400) || (scene->res.size_y < 400))
		put_warn_res();
}
