/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/31 23:23:18 by mboivin          ###   ########.fr       */
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

// P(t) = origin + (t * dir)

void		*intersect(t_scene *scene, t_ray ray)
{
	(void)scene;
	(void)ray;
	return (NULL);
}

t_color		trace_ray(t_scene *scene, t_ray ray)
{
	t_color	ray_color;
	void	*nearest_obj;

	nearest_obj = intersect(scene, ray);
	if (nearest_obj)
		//ray_color = nearest_obj->color;
		ray_color = create_color(255, 255, 255);
	else
		ray_color = create_color(0, 0, 0);
	return (ray_color);
}

static void	set_viewdist(t_cam *cam)
{
	cam->viewplane_d = (g_app->win_x * 0.5) * tan(cam->fov * 0.5);
}

void		set_camera_ray(t_scene *scene, t_ray *ray)
{
	ray->origin = scene->main_cam->pos;
	// TODO: Compute dir
	ray->dir = scene->main_cam->rot;
	set_viewdist(scene->main_cam);
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
			set_camera_ray(scene, &ray);
			ray_color = trace_ray(scene, ray);
			put_pixel_to_image(g_app->img, ray_color, x, y);
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
