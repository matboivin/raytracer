/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/23 19:24:54 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

struct s_err	g_err[] =
{
	{ AMB_DUP, "Invalid scene: Ambient light must be declared once." },
	{ AMB_FMT, "Invalid scene: Ambient light badly formatted." },
	{ CAM_FMT, "Invalid scene: Camera badly formatted." },
	{ COLOR_FMT, "Invalid scene: Color badly formatted." },
	{ COORD_FMT, "Invalid scene: Coord3 badly formatted." },
	{ CYL_FMT, "Invalid scene: Cylinder badly formatted." },
	{ DOUBLE_FMT, "Invalid scene: Double badly formatted." },
	{ FILENAME, "Invalid scene file format: Try 'scene.rt'." },
	{ ID_ERRR, "Invalid scene: Unknown identifier." },
	{ LIGHT_FMT, "Invalid scene: Light badly formatted." },
	{ MALLOC_APP, "Malloc application failed." },
	{ MALLOC_IMG, "Malloc image failed." },
	{ NUM_FMT, "Invalid scene: Number badly formatted." },
	{ PLANE_FMT, "Invalid scene: Plane badly formatted." },
	{ SAVE_OPTION, "Invalid option: Try '--save'." },
	{ RES_DUP, "Invalid scene: Resolution must be declared once." },
	{ RES_NEG, "Invalid scene: Resolution width and height must be positive." },
	{ SCENE_FMT, "Invalid scene: Scene badly formatted." },
	{ SPHERE_FMT, "Invalid scene: Sphere badly formatted." },
	{ SQUARE_FMT, "Invalid scene: Square badly formatted." },
	{ TRI_FMT, "Invalid scene: Triangle badly formatted." },
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

char		*catch_err(t_errid raised)
{
	int		i;

	i = 0;
	while (g_err[i].u_id != DEFAULT)
	{
		if (g_err[i].u_id == raised)
			return (g_err[i].msg);
		i++;
	}
	return ((char *)strerror(errno));
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
