/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:17:52 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/02 22:24:26 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_filename(const char *filepath)
{
	int	len;

	len = ft_strlen(filepath);
	if (len < 4)
		put_error(FILENAME);
	filepath += len - 3;
	if (ft_strncmp(filepath, ".rt", 3) != 0)
		put_error(FILENAME);
}

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

void		check_params(int argc, char **argv, bool *to_bmp)
{
	if ((argc < 2) || (argc > 3))
		put_usage();
	check_filename(argv[1]);
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save"))
			put_error(SAVE_OPTION);
		*to_bmp = true;
	}
}
