/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/06 16:28:13 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Render image
**
** cast_ray()        :  Computes the color at the intersection point of a ray
** get_pixel_coord() :  Converts pixel to world coordinates
** render()          :  Fills image starting from pos (0,0)
** generate_image()  :  Generate the rendered image
*/

/*
** If a ray intersects an object, process shading and return its color
** Else, return the default color
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
** Convert pixel to world coordinates
*/

t_vec4			get_pixel_coord(t_scene *scene, int x, int y)
{
	t_vec4		result;
	double		scale;
	int			pixel_x;
	int			pixel_y;

	scale = tan(degrees_to_radians(scene->main_cam->fov * 0.5));
	pixel_x = (2 * (x + 0.5) / g_app->win_x - 1) * scene->aspect_ratio * scale;
	pixel_y = (1 - 2 * (y + 0.5) / g_app->win_y) * scale;
	result = create_vec4(pixel_x, pixel_y, -1, 1);
	return (result);
}

/*
** Create a cam_to_world matrix
** Set the ray origin to the camera position
** Iterate over all pixels in the image
** At each pixel, set the ray direction, cast the ray
** Retrieve the ray color and put it in the image
*/

void			render(t_scene *scene)
{
	t_mat4x4	cam_to_world;
	t_ray		ray;
	t_color		ray_color;
	int			x;
	int			y;

	cam_to_world = look_at(scene->main_cam);
	set_ray_origin(&ray, cam_to_world);
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

/*
** Malloc an image an start rendering
*/

void			generate_image(t_scene *scene)
{
	g_app->img = malloc_image();
	render(scene);
	if ((scene->res.size_x < 400) || (scene->res.size_y < 400))
		put_warn_res();
}
