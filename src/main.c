/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:16:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/20 15:56:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_app		*g_app;

static void	export_to_bmp(void)
{
	ft_dprintf(STDOUT_FILENO, "Rendered image save in bmp format.\n");
	exit_all(false);
}

static void	check_filename(const char *filepath)
{
	int		len;

	len = ft_strlen(filepath);
	if (len < 4)
		exit_error(catch_err(FILENAME));
	filepath += len - 3;
	if (!ft_strnequ(filepath, ".rt", 3))
		exit_error(catch_err(FILENAME));
}

int			main(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		put_usage();
	check_filename(argv[1]);
	if (argc == 3 && ft_strcmp(argv[2], "--save"))
		exit_error(catch_err(SAVE_OPTION));
	start_application(RENDER_X, RENDER_Y, WIN_TITLE);
	if (argc == 3)
		export_to_bmp();
	return (mlx_loop(g_app->mlx_ptr));
}
