/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/06 23:58:57 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function checks if the filename is correctly formatted
*/

void	check_filename(const char *filepath)
{
	int	len;

	len = ft_strlen(filepath);
	if (len < 4)
		put_error(FILENAME);
	filepath += len - 3;
	if (!ft_strnequ(filepath, ".rt", 3))
		put_error(FILENAME);
}

/*
** This function prints the usage message to standard error
*/

void	put_usage(void)
{
	ft_dprintf(
		STDERR_FILENO,
		"Usage: ./miniRT <scene.rt> [--save]\n\n");
	ft_dprintf(
		STDERR_FILENO,
		"optional arguments:\n  --save  save rendered image to bmp format\n");
	exit(EXIT_FAILURE);
}

/*
** This function warns the user if the resolution is too low
*/

void	put_warn_res(void)
{
	ft_printf("WARNING\nLow resolution: ");
	ft_printf("A minimum size of 400x400 is recommended.\n\n");
}

/*
** This function frees scene and application
*/

void	free_all(t_scene *scene)
{
	destroy_scene(scene);
	quit_app();
}

/*
** This function frees allocated memory and exits
*/

int		exit_success(t_scene *scene)
{
	free_all(scene);
	ft_printf("EXIT\n");
	exit(EXIT_SUCCESS);
	return (0);
}
