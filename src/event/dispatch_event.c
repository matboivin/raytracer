/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:57:56 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/16 18:05:52 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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