/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:57:56 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/23 23:56:57 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Handle events
**
** handle_key()      :  Handles keyboard events
** register_events() :  Register event handlers
*/

int		handle_key(int keycode, t_scene *scene)
{
	if (keycode == ESC_KEY)
		exit_success(scene);
	return (0);
}

void	register_events(t_scene *scene)
{
	mlx_key_hook(g_app->win_ptr, handle_key, scene);
	mlx_hook(g_app->win_ptr, DESTROYNOTIFY, DESTROYNOTIFYMASK, exit_success, scene);
}
