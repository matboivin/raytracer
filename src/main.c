/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:16:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/20 13:19:38 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		put_usage(void)
{
	ft_dprintf(STDERR_FILENO, "Usage: ./miniRT <scene.rt> [--save]\n\n");
	ft_dprintf(
		STDERR_FILENO,
		"optional arguments:\n  --save  save the rendered image in bmp format\n"
	);
	exit(EXIT_FAILURE);
}

void		put_error(void *s)
{
	ft_dprintf(STDERR_FILENO, "Error\n%s\n", s);
	exit(EXIT_FAILURE);
}

void		check_filename(const char *filepath)
{
	int		len;

	len = ft_strlen(filepath);
	if (len < 4)
		put_error(strerror(errno));
	filepath += len - 3;
	if (!ft_strnequ(filepath, ".rt", 3))
		put_error(strerror(errno));
}

int			main(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		put_usage();
	check_filename(argv[1]);
	if (argc == 3 && ft_strcmp(argv[2], "--save"))
		put_error(strerror(errno));
	if (argc == 3)
		put_error(strerror(errno));
	return (0);
}
