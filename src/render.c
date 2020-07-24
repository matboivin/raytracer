/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/24 17:22:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Display rendering in a window
**
** open_window()         :  Creates a new window
** put_image_to_window() :  Displays image in window
** resize_window()       :  Handles window size if bigger than screen size
** display_rendering()   :  Displays the image and registers events
*/

void	open_window(void)
{
	g_app->win_ptr = mlx_new_window(
		g_app->mlx_ptr,
		g_app->win_x,
		g_app->win_y,
		g_app->title
	);
}

void	put_image_to_window(void)
{
	mlx_put_image_to_window(
		g_app->mlx_ptr,
		g_app->win_ptr,
		g_app->img->img_ptr,
		0,
		0
	);
}

void	resize_window(void)
{
	int	max_x;
	int	max_y;

	mlx_get_screen_size(g_app->mlx_ptr, &max_x, &max_y);
	if (g_app->win_x > max_x)
		g_app->win_x = max_x;
	if (g_app->win_y > max_y)
		g_app->win_y = max_y;
}

void	display_rendering(t_scene *scene)
{
	g_app->img = malloc_image(g_app->win_x, g_app->win_y);
	fill_image(create_color(0, 0, 255)); // Tmp test
	open_window();
	put_image_to_window();
	register_events(scene);
}
