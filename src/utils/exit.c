/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/02 00:30:29 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Exit program
**
** check_filename() :  Checks if the filename is correctly formatted
** put_usage()      :  Prints usage message to standard error
** put_warn_res()   :  Warns the user if the resolution is too low
** free_all()       :  Frees scene and application
** exit_success()   :  Frees allocated memory and exits
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

void	put_warn_res(void)
{
	ft_printf("WARNING\nLow window resolution: ");
	ft_printf("A minimum size of 400x400 is recommended.\n\n");
}

void	free_all(t_scene *scene)
{
	destroy_scene(scene);
	quit_app();
}

int		exit_success(t_scene *scene)
{
	free_all(scene);
	ft_printf("EXIT\n");
	exit(EXIT_SUCCESS);
	return (0);
}
