/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:29:07 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/17 18:35:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** miniRT controler
** Contains mlx pointer, window information, images and scene elements
*/

void	init_minirt(t_minirt *env, char *title)
{
	env->mlx_ptr = mlx_init();
	env->win_ptr = NULL;
	env->title = title;
	env->imgs = NULL;
	create_resolution(&(env->res));
	create_ambient(&(env->ambient));
	env->cam_count = 0;
	env->cams = NULL;
	env->lights = NULL;
	env->objs = NULL;
}

void	quit_minirt(t_minirt *env)
{
	if (env->win_ptr)
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	delete_images(env->mlx_ptr, &(env->imgs));
	delete_cameras(&(env->cams));
	delete_lights(&(env->lights));
	delete_objs(&(env->objs));
}
