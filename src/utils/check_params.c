/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:17:52 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/11 23:35:09 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_filename(const char *filepath)
{
	size_t	filename_len;

	filename_len = ft_strlen(filepath);
	if (filename_len < MIN_FILENAME_LEN)
		print_error(FILENAME);
	filepath += filename_len - EXT_LEN;
	if (ft_strncmp(filepath, ".rt", EXT_LEN))
		print_error(FILENAME);
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
			print_error(SAVE_OPTION);
		*to_bmp = true;
	}
}
