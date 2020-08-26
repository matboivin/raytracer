/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/27 01:30:33 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Struct: Error identifiers associated to error messages
*/

static t_err	g_errors[] =
{
	{ AMB_DUP, "Invalid scene: Ambient light must be declared once." },
	{ AMB_FMT, "Invalid scene: Ambient light badly formatted." },
	{ CAM_FMT, "Invalid scene: Camera badly formatted." },
	{ COLOR_FMT, "Invalid scene: Color badly formatted." },
	{ COORD_FMT, "Invalid scene: Coordinates badly formatted." },
	{ CYL_FMT, "Invalid scene: Cylinder badly formatted." },
	{ DOUBLE_FMT, "Invalid scene: Double value badly formatted." },
	{ FILENAME, "Invalid scene file format: Try 'scene.rt'." },
	{ ID_ERR, "Invalid scene: Unknown identifier." },
	{ LIGHT_FMT, "Invalid scene: Light badly formatted." },
	{ MISS_RA, "Invalid scene: Missing resolution or ambient light." },
	{ MISS_CAM, "Invalid scene: At least one camera is required." },
	{ MISS_LIGHT, "Invalid scene: At least one light spot is required." },
	{ MISS_OBJ, "No object declared. Rendering stopped." },
	{ NUM_FMT, "Invalid scene: Number badly formatted." },
	{ PLANE_FMT, "Invalid scene: Plane badly formatted." },
	{ SAVE_OPTION, "Invalid option: Try '--save'." },
	{ RES_DUP, "Invalid scene: Resolution must be declared once." },
	{ RES_MIN, "Resolution too low: minimum is 100x100. Rendering stopped." },
	{ RES_NEG, "Invalid scene: Resolution width and height must be positive." },
	{ SCENE_FMT, "Invalid scene: Scene badly formatted." },
	{ SPHERE_FMT, "Invalid scene: Sphere badly formatted." },
	{ SQUARE_FMT, "Invalid scene: Square badly formatted." },
	{ DEFAULT_ERR, "An error occurred." }
};

/*
** This function retrieves the appropriate error message using given error id
*/

static char	*catch_err(t_errid raised)
{
	int		i;

	i = 0;
	while (g_errors[i].u_id != DEFAULT_ERR)
	{
		if (g_errors[i].u_id == raised)
			return (g_errors[i].msg);
		i++;
	}
	return ((char *)strerror(errno));
}

/*
** This function prints an error message to standard error
*/

void		put_error(t_errid raised)
{
	char	*msg;

	msg = catch_err(raised);
	ft_dprintf(STDERR_FILENO, "Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}
