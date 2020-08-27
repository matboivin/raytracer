/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:29:07 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/27 01:59:43 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Initialize miniRT controler
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
	lstimg_clear(env->mlx_ptr, &(env->imgs));
	lstcam_clear(&(env->cams));
	lstlight_clear(&(env->lights));
	lstobj_clear(&(env->objs));
}

int		run_minirt(t_minirt *env)
{
	mlx_loop(env->mlx_ptr);
	return (EXIT_SUCCESS);
}
