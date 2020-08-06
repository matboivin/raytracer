/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:57:56 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/06 23:57:43 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles keyboard events
*/

int		handle_key(int keycode, t_scene *scene)
{
	if (keycode == ESC_KEY)
		exit_success(scene);
	if (keycode == SPC_KEY)
		switch_camera(scene);
	return (0);
}

/*
** This function dispatches event handlers
*/

void	dispatch_event(t_scene *scene)
{
	mlx_key_hook(
		g_app->win_ptr,
		handle_key,
		scene);
	mlx_hook(
		g_app->win_ptr,
		DESTROYNOTIFY,
		DESTROYNOTIFYMASK,
		exit_success,
		scene);
}
