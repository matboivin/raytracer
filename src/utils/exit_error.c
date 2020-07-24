/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/24 17:27:20 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Print error messages and exit program
**
** g_err struct :  Error ids associated to error messages
** catch_err()  :  Retrieves the appropriate error message given an error id
** put_error()  :  Prints error message to standard error
** exit_error() :  Frees allocated memory, prints error message and exits
*/

struct s_err	g_err[] =
{
	{ AMB_DUP, "Invalid scene: Ambient light must be declared once." },
	{ AMB_FMT, "Invalid scene: Ambient light badly formatted." },
	{ CAM_FMT, "Invalid scene: Camera badly formatted." },
	{ COLOR_FMT, "Invalid scene: Color badly formatted." },
	{ COORD_FMT, "Invalid scene: Coordinates badly formatted." },
	{ CYL_FMT, "Invalid scene: Cylinder badly formatted." },
	{ DOUBLE_FMT, "Invalid scene: Double value badly formatted." },
	{ FILENAME, "Invalid scene file format: Try 'scene.rt'." },
	{ ID_ERRR, "Invalid scene: Unknown identifier." },
	{ LIGHT_FMT, "Invalid scene: Light badly formatted." },
	{ NUM_FMT, "Invalid scene: Number badly formatted." },
	{ PLANE_FMT, "Invalid scene: Plane badly formatted." },
	{ SAVE_OPTION, "Invalid option: Try '--save'." },
	{ RES_DUP, "Invalid scene: Resolution must be declared once." },
	{ RES_NEG, "Invalid scene: Resolution width and height must be positive." },
	{ SCENE_ERR, "Invalid scene: Missing resolution or ambient light." },
	{ SCENE_FMT, "Invalid scene: Scene badly formatted." },
	{ SPHERE_FMT, "Invalid scene: Sphere badly formatted." },
	{ SQUARE_FMT, "Invalid scene: Square badly formatted." },
	{ DEFAULT_ERR, "" }
};

char		*catch_err(t_errid raised)
{
	int		i;

	i = 0;
	while (g_err[i].u_id != DEFAULT_ERR)
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
