/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/21 21:54:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

struct s_err	g_err[] =
{
	{ FILENAME, "Invalid scene file format: Try 'scene.rt'." },
	{ MALLOC_APP, "Malloc application failed." },
	{ MALLOC_IMG, "Malloc image failed." },
	{ SAVE_OPTION, "Invalid option: Try '--save'." },
	{ DEFAULT, "" }
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

static void	free_all(t_scene *scene)
{
	destroy_scene(scene);
	quit_application();
}

void		*catch_err(t_errid raised)
{
	int		i;

	if (raised != DEFAULT)
	{
		i = 0;
		while (g_err[i].u_id != raised)
			i++;
		if (g_err[i].u_id == raised)
			return (g_err[i].msg);
	}
	return (strerror(errno));
}

void		put_error(t_errid raised)
{
	char	*msg;

	msg = catch_err(raised);
	ft_dprintf(STDERR_FILENO, "Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}

void		exit_error(t_scene *scene, t_errid raised)
{
	free_all(scene);
	put_error(raised);
}

int			exit_success(t_scene *scene)
{
	free_all(scene);
	ft_dprintf(STDOUT_FILENO, "EXIT\n");
	exit(EXIT_SUCCESS);
	return (0);
}
