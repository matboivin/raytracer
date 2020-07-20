/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:52:05 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/20 14:16:31 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_application(int p_x, int p_y, char *title)
{
	g_app = (t_app *)malloc(sizeof(t_app));
	if (g_app == NULL)
		return (NULL);
	g_app->mlx_ptr = mlx_init();
	g_app->win_x = p_x;
	g_app->win_y = p_y;
	g_app->title = title;
	g_app->win_ptr = mlx_new_window(
		g_app->mlx_ptr,
		g_app->win_x,
		g_app->win_y,
		g_app->title
	);
	g_app->img = NULL;
}

void	destroy_application(void)
{
	if (g_app->img != NULL)
		free_image(g_app->img = NULL);
	mlx_destroy_window(g_app->mlx_ptr, g_app->win_ptr);
}
