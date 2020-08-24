/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:52:05 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/24 19:16:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Application to use MLX functions
**
** open_app() :  Constructor
** quit_app() :  Destructor
** run_app()  :  Starts loop to listen to events
*/

void	open_app(char *title)
{
	g_app = (t_app *)malloc(sizeof(t_app));
	if (g_app == NULL)
		put_error(DEFAULT_ERR);
	g_app->mlx_ptr = mlx_init();
	g_app->win_x = 0;
	g_app->win_y = 0;
	g_app->title = title;
	g_app->win_ptr = NULL;
	g_app->img = NULL;
}

void	quit_app(void)
{
	if (g_app->win_ptr)
		mlx_destroy_window(g_app->mlx_ptr, g_app->win_ptr);
}

int		run_app(void)
{
	mlx_loop(g_app->mlx_ptr);
	return (EXIT_SUCCESS);
}
