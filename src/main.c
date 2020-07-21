/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:16:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/21 18:35:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_app		*g_app;

static void	check_filename(const char *filepath)
{
	int		len;

	len = ft_strlen(filepath);
	if (len < 4)
		put_error(FILENAME);
	filepath += len - 3;
	if (!ft_strnequ(filepath, ".rt", 3))
		put_error(FILENAME);
}

int			main(int argc, char **argv)
{
	t_scene	scene;

	if (argc < 2 || argc > 3)
		put_usage();
	check_filename(argv[1]);
	if (argc == 3 && ft_strcmp(argv[2], "--save"))
		put_error(SAVE_OPTION);
	start_application(RENDER_X, RENDER_Y, WIN_TITLE);
	create_scene(&scene);
	g_app->img = malloc_image(g_app->win_x, g_app->win_y);
	fill_image(create_color(50, 234, 97));
	mlx_put_image_to_window(g_app->mlx_ptr, g_app->win_ptr, g_app->img->img_ptr, 0, 0);
	if (argc == 3)
		save_bmp(&scene, BMP_FILE);
	register_events(&scene);
	return (run_app());
}
