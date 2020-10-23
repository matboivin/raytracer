/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/24 01:26:07 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "libft_printf.h"
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
	{ FLOAT_FMT, "Invalid scene: Floating-point number badly formatted." },
	{ FILENAME_ERR, "Invalid scene file: Use the '.rt' extension." },
	{ ID_ERR, "Invalid scene: Unknown identifier." },
	{ LIGHT_FMT, "Invalid scene: Light badly formatted." },
	{ NO_AMB, "No ambient light declared. Rendering stopped." },
	{ NO_CAM, "No camera declared. Rendering stopped." },
	{ NO_LIGHT, "No light declared. Rendering stopped." },
	{ NO_OBJ, "No object declared. Rendering stopped." },
	{ NO_RES, "No resolution declared. Rendering stopped." },
	{ NUM_FMT, "Invalid scene: Number badly formatted." },
	{ OPT_ERR, "Invalid option: Try '--save'." },
	{ PLANE_FMT, "Invalid scene: Plane badly formatted." },
	{ RES_DUP, "Invalid scene: Resolution must be declared once." },
	{ RES_LOW, "Resolution too low: minimum is 300x300. Rendering stopped." },
	{ SCENE_FMT, "Invalid scene: Scene badly formatted." },
	{ SPHERE_FMT, "Invalid scene: Sphere badly formatted." },
	{ SQUARE_FMT, "Invalid scene: Square badly formatted." }
};

/*
** This function retrieves the appropriate error message using given error id
*/

static char	*get_error_msg(t_errid raised)
{
	if (raised != ERRNO_TO_STR)
		return (g_errors[raised].msg);
	return ((char *)strerror(errno));
}

/*
** This function prints an error message to standard error
*/

void		print_error(t_errid raised)
{
	char	*msg;

	msg = get_error_msg(raised);
	ft_dprintf(STDERR_FILENO, "Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}
