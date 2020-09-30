/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:47:22 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/30 14:44:01 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DEFINE_H
# define MINIRT_DEFINE_H

# define WIN_TITLE "miniRT"
# define SAVE_OPT "--save"
# define MIN_FILENAME_LEN 4
# define DEFAULT_EXT ".rt"
# define EXT_LEN 3
# define PIXEL_LEN 4
# define ID_LEN 1
# define ID_OBJ_LEN 2
# define MAX_PARS_FUNC 13
# define MIN_RES 300
# define MIN_LUM_RATIO 0.1
# define DEFAULT_VALUE 0.0
# define UNIT_VALUE 1.0
# define REVUNIT_VALUE -1.0
# define STRAIGHT_ANGLE 180.0
# define MAX_RGB 255
# define HALF_PIXEL 0.5
# define EPSILON 0.00001
# define SPECULAR_COEF 70
# define NEWLINE '\n'
# define MINUS '-'
# define DOT '.'
# define COMMA ','

/*
** MLX is in BGRA so we change the order of components to RGBA
*/

# define RED_COMP 2
# define GREEN_COMP 1
# define BLUE_COMP 0
# define ALPHA_COMP 3

typedef t_vec3			t_vcolor;
typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;

#endif
