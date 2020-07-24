/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:16:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/25 01:08:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_app		*g_app;

/*
** miniRT
** Generate images using the Ray tracing protocol
**
** Requirements: MinilibX for Linux
**
** Open app to connect to the X server with mlx_init()
** Initialize scene struct
** Parse a given scene description to store data in the scene struct
** Use scene data to generate an image
** If '--save' option is used, save the image in BMP format
** Else, display the rendered imaged in a window
** Run a loop to listen to events
*/

int			main(int argc, char **argv)
{
	t_scene	scene;

	if (argc < 2 || argc > 3)
		put_usage();
	check_filename(argv[1]);
	if (argc == 3 && ft_strcmp(argv[2], "--save"))
		put_error(SAVE_OPTION);
	open_app(WIN_TITLE);
	create_scene(&scene);
	parse_scene(&scene, argv[1]);
	generate_image(&scene);
	if (argc == 3)
		save_bmp(&scene, BMP_FILENAME);
	display_rendering(&scene);
	return (run_app());
}
