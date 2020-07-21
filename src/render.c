/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/21 21:48:35 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void	display_rt(t_scene *scene)
{
	open_window();
	g_app->img = malloc_image(g_app->win_x, g_app->win_y);
	fill_image(create_color(55, 0, 55)); // Tmp test
	put_image_to_window();
	register_events(scene);
}
