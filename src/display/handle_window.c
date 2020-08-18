/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/18 17:23:35 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function creates a new window
*/

void	open_window(void)
{
	g_app->win_ptr = mlx_new_window(
		g_app->mlx_ptr,
		g_app->win_x,
		g_app->win_y,
		g_app->title);
}

/*
** This function displays image in window
*/

void	put_image_to_window(void)
{
	mlx_put_image_to_window(
		g_app->mlx_ptr,
		g_app->win_ptr,
		g_app->img->img_ptr,
		0,
		0);
}

/*
** This function reloads image in window
*/

int		reload_image(void)
{
	put_image_to_window();
	return (0);
}
