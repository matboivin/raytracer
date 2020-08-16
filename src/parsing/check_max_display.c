/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/16 18:22:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles render size if bigger than screen size
*/

void		check_max_display(t_scene *scene)
{
	int		max_x;
	int		max_y;

	mlx_get_screen_size(g_app->mlx_ptr, &max_x, &max_y);
	if (scene->res.size_x > max_x)
		scene->res.size_x = max_x;
	if (scene->res.size_y > max_y)
		scene->res.size_y = max_y;
	g_app->win_x = scene->res.size_x;
	g_app->win_y = scene->res.size_y;
}
