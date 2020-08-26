/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:16:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/27 00:29:25 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int				main(int argc, char **argv)
{
	t_minirt	env;
	bool		to_bmp;

	to_bmp = false;
	check_params(argc, argv, &to_bmp);
	init_minirt(&env, WIN_TITLE);
	parse_scene(&env, argv[1]);
	render(&env, to_bmp);
	display_render(&env);
	return (run_minirt(&env));
}
