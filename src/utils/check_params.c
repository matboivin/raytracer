/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:17:52 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/16 18:00:32 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function checks if the filename is correctly formatted
*/

static void	check_filename(const char *filepath)
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

static void	put_usage(void)
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
** This function checks the parameters
*/

void		check_params(int argc, char **argv)
{
	if ((argc < 2) || (argc > 3))
		put_usage();
	check_filename(argv[1]);
	if ((argc == 3) && (ft_strcmp(argv[2], "--save")))
		put_error(SAVE_OPTION);
}
