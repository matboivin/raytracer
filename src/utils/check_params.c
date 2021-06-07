/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:17:52 by mboivin           #+#    #+#             */
/*   Updated: 2021/06/07 17:34:13 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft_str.h"
#include "minirt.h"

static void	check_filename(const char *filepath)
{
	size_t	filename_len;

	filename_len = ft_strlen(filepath);
	if (filename_len < MIN_FILENAME_LEN)
		print_error("Invalid scene file: Use the '.rt' extension.");
	filepath += filename_len - EXT_LEN;
	if (ft_strncmp(filepath, DEFAULT_EXT, EXT_LEN))
		print_error("Invalid scene file: Use the '.rt' extension.");
}

static void	print_usage(void)
{
	dprintf(
		STDERR_FILENO,
		"Usage: ./miniRT <scene.rt> [--save]\n\n\
		\roptional arguments:\n  --save  save rendered image to bmp format\n");
	exit(EXIT_FAILURE);
}

void		check_params(int argc, char **argv, bool *to_bmp)
{
	if ((argc < MIN_ARGC) || (argc > MAX_ARGC))
		print_usage();
	check_filename(argv[1]);
	if (argc == MAX_ARGC)
	{
		if (ft_strcmp(argv[2], SAVE_OPT))
			print_error("Invalid option: Try '--save'.");
		*to_bmp = true;
	}
}
