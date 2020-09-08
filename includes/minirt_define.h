/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:49:09 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/09 01:00:49 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DEFINE_H
# define MINIRT_DEFINE_H

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
typedef uint32_t		t_color;
typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;

/*
** Event masks
** 42 Norm doesn't allow the following:
** # define KEYPRESSMASK (1L << 0)
** # define DESTROYNOTIFYMASK (1L << 17)
*/

typedef enum	e_emask
{
	KEYPRESSMASK = 1L << 0,
	STRUCTURENOTIFYMASK = 1L << 17
}				t_emask;

/*
** Event types
*/

# define KEYPRESS 2
# define DESTROYNOTIFY 17
# define MAPNOTIFY 19

/*
** Keys
*/

# define ESC_KEY 65307
# define SPC_KEY 32

#endif
