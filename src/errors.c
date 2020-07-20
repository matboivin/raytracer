/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/20 15:04:45 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

struct s_err	g_err[] =
{
	{ FILENAME, "Invalid scene file format: Try 'scene.rt'." },
	{ MALLOC_APP, "Malloc application failed." },
	{ MALLOC_IMG, "Malloc image failed." },
	{ SAVE_OPTION, "Invalid option: Try '--save'." }
};

void		put_usage(void)
{
	ft_dprintf(STDERR_FILENO, "Usage: ./miniRT <scene.rt> [--save]\n\n");
	ft_dprintf(
		STDERR_FILENO,
		"optional arguments:\n  --save  save the rendered image in bmp format\n"
	);
	exit(EXIT_FAILURE);
}

static void	free_all(void)
{
	quit_application();
}

void		*catch_err(t_errid raised)
{
	int		i;

	i = 0;
	while (g_err[i].u_id != raised)
		i++;
	if (g_err[i].u_id == raised)
		return (g_err[i].msg);
	return (strerror(errno));
}

void		exit_error(void *s)
{
	ft_dprintf(STDERR_FILENO, "Error\n%s\n", s);
	exit_all(true);
}

void		exit_all(bool err)
{
	free_all();
	if (err == true)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
