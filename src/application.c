/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:52:05 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/21 21:27:52 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	start_application(int p_x, int p_y, char *title)
{
	g_app = (t_app *)malloc(sizeof(t_app));
	if (g_app == NULL)
		put_error(MALLOC_APP);
	g_app->mlx_ptr = mlx_init();
	g_app->win_x = p_x;
	g_app->win_y = p_y;
	g_app->title = title;
	g_app->win_ptr = NULL;
	g_app->img = NULL;
}

void	quit_application(void)
{
	if (g_app->img != NULL)
		free_image(g_app->img);
	if (g_app->win_ptr != NULL)
		mlx_destroy_window(g_app->mlx_ptr, g_app->win_ptr);
}

int		run_app(void)
{
	mlx_loop(g_app->mlx_ptr);
	return (EXIT_SUCCESS);
}
