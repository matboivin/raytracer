/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:57:56 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/06 12:26:53 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function dispatches event handlers
*/

void	dispatch_events(t_minirt *env)
{
	mlx_key_hook(
		env->win_ptr,
		handle_key,
		env);
	mlx_hook(
		env->win_ptr,
		DESTROYNOTIFY,
		STRUCTURENOTIFYMASK,
		exit_success,
		env);
	mlx_hook(
		env->win_ptr,
		MAPNOTIFY,
		STRUCTURENOTIFYMASK,
		reload_image,
		env);
}
