/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:49:09 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/31 01:32:17 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DEFINE_H
# define MINIRT_DEFINE_H

# ifndef BONUS
#  define BONUS 0
# endif

# define WIN_TITLE "miniRT"
# define BMP_FILENAME "minirt.bmp"
# define PARS_FUNC 13

/*
** MLX is in BGRA so we change the order of values to RGBA
*/

# define RED_COMP 2
# define GREEN_COMP 1
# define BLUE_COMP 0
# define ALPHA_COMP 3

# define SPECULAR 70

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
