/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:47:22 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/12 00:08:29 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <errno.h>
# include <limits.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft.h"
# include "mlx.h"
# include "minimath.h"

# ifndef BONUS
#  define BONUS 0
# endif

# define WIN_TITLE "miniRT"
# define MIN_FILENAME_LEN 4
# define EXT_LEN 3
# define PIXEL_LEN 4
# define IDENTIFIER_LEN 2
# define MAX_PARS_FUNC 13
# define MIN_RES 100
# define MIN_LUM_RATIO 0.1
# define DEFAULT_VALUE 0.0
# define UNIT_VALUE 1.0
# define REVUNIT_VALUE -1.0
# define STRAIGHT_ANGLE 180.0
# define MAX_RGB 255
# define EPSILON 0.00001
# define SPECULAR_COEF 70

/*
** MLX is in BGRA so we change the order of values to RGBA
*/

# define RED_COMP 2
# define GREEN_COMP 1
# define BLUE_COMP 0
# define ALPHA_COMP 3

typedef t_vec3			t_vcolor;
typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;

# include "minirt_ray.h"
# include "minirt_camera.h"
# include "minirt_light.h"
# include "minirt_objects.h"
# include "minirt_env.h"
# include "minirt_events.h"
# include "minirt_render.h"
# include "minirt_math_utils.h"
# include "minirt_parsing.h"
# include "minirt_save.h"
# include "minirt_exit.h"
# include "minirt_debug.h"

#endif
