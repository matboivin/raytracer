/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/28 13:05:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Render image
**
** trace_ray()      :  Traces ray and retrieves color
** set_ray()        :  Retrieves origin and direction of ray
** fill_image()     :  Fills the image starting from pos (0,0)
** generate_image() :  Generate the rendered image
*/

t_color		trace_ray(t_scene *scene, t_ray ray)
{
	t_color	ray_color;

	(void)scene;
	(void)ray;
	// if intersect, compute and retrieve color
	// else return default color
	ray_color = create_color(0, 0, 255); // default color
	return (ray_color);
}

void		set_ray(t_scene *scene, t_ray *ray)
{
	(void)scene;
	// TODO: Retrieve origin and dir
	// cf. main camera
	ray->origin = create_vec3(0.0, 0.0, 0.0);
	ray->dir = create_vec3(0.0, 0.0, 1.0);
	ray->t = 0.0;
}

void		render(t_scene *scene)
{
	int		x;
	int		y;
	t_ray	ray;
	t_color	ray_color;

	y = 0;
	while (y < g_app->win_y)
	{
		x = 0;
		while (x < g_app->win_x)
		{
			set_ray(scene, &ray);
			ray_color = trace_ray(scene, ray);
			set_pixel(g_app->img, ray_color, x, y);
			x++;
		}
		y++;
	}
}

void		generate_image(t_scene *scene)
{
	g_app->img = malloc_image();
	render(scene);
	if ((scene->res.size_x < 400) || (scene->res.size_y < 400))
		put_warn_res();
}
