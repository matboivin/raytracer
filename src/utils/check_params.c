/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:17:52 by mboivin           #+#    #+#             */
/*   Updated: 2021/07/11 16:31:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_str.h"
#include "minirt.h"

static void	check_filename(const char *pathname)
{
	size_t	filename_len;

	filename_len = ft_strlen(pathname);
	if (filename_len < MIN_FILENAME_LEN)
		put_err("Invalid scene file: Use the '.rt' extension.");
	pathname += filename_len - EXT_LEN;
	if (ft_strncmp(pathname, DEFAULT_EXT, EXT_LEN))
		put_err("Invalid scene file: Use the '.rt' extension.");
}

static void	put_usage(void)
{
	const char	*usage_msg = "Usage: ./miniRT <scene.rt> [--save]\n\n\
		\roptional arguments:\n  --save  save rendered image to bmp format\n";

	write(STDERR_FILENO, usage_msg, ft_strlen(usage_msg));
	exit(EXIT_FAILURE);
}

void	check_params(int argc, char **argv, bool *save_to_bmp)
{
	if ((argc < MIN_ARGC) || (argc > MAX_ARGC))
		put_usage();
	check_filename(argv[1]);
	if (argc == MAX_ARGC)
	{
		if (ft_strcmp(argv[2], SAVE_OPT))
			put_err("Invalid option: Try '--save'.");
		*save_to_bmp = true;
	}
}
