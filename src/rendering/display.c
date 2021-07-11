/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2021/07/11 16:06:13 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function creates a new window
*/

void	open_window(t_minirt *env)
{
	env->win_ptr = mlx_new_window(
		env->mlx_ptr,
		env->res.size_x,
		env->res.size_y,
		env->title);
}

/*
** This function displays image in window
*/

void	put_image_to_window(t_minirt *env)
{
	mlx_put_image_to_window(
		env->mlx_ptr,
		env->win_ptr,
		env->imgs->img_ptr,
		UPPER_LEFT_CORNER,
		UPPER_LEFT_CORNER);
}

int		reload_image(t_minirt *env)
{
	put_image_to_window(env);
	return (0);
}

/*
** This function switches camera view when user presses space bar
*/

void	switch_camera(t_minirt *env)
{
	env->imgs = env->imgs->next;
	put_image_to_window(env);
}

/*
** This function displays the image and dispatches events
*/

void	display_render(t_minirt *env)
{
	open_window(env);
	put_image_to_window(env);
	dispatch_events(env);
}
