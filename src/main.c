/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:16:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/16 15:18:23 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_app		*g_app;

/*
** miniRT
** A minimal ray tracer
**
** Open app to connect to the X server with mlx_init()
** Parse a given scene description and store data in the scene struct
** Use scene data to generate an image
** If '--save' option is used, save the image in BMP format
** Else, display the rendered imaged in a window
** Run a loop to listen to events
*/

int			main(int argc, char **argv)
{
	t_scene	scene;

	check_params(argc, argv);
	open_app(WIN_TITLE);
	parse_scene(&scene, argv[1]);
	generate_image(&scene);
	if (argc == 3)
		save_bmp(&scene, BMP_FILENAME);
	display_render(&scene);
	return (run_app());
}
