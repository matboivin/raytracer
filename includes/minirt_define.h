/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:47:22 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/21 15:07:54 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DEFINE_H
# define MINIRT_DEFINE_H

# define MIN_ARGC 2
# define MAX_ARGC 3
# define WIN_TITLE "miniRT"
# define SAVE_OPT "--save"
# define DEFAULT_EXT ".rt"
# define EXT_LEN 3
# define MIN_FILENAME_LEN 4
# define PIXEL_LEN 4
# define MIN_RES 300
# define MIN_LUM_RATIO 0.1
# define MAX_RGB 255
# define HALF_PIXEL 0.5
# define HALF_DIV 0.5
# define DBL_UNIT 2.0
# define QUAD_UNIT 4.0
# define EPSILON 0.00001
# define SPECULAR_COEF 70

/*
** Position of image in window
*/

# define UPPER_LEFT_CORNER 0

/*
** Parsing
*/

# define MAX_PARS_FUNC 9
# define ID_OBJ_LEN 2
# define SPHERE_ID "sp"
# define PLANE_ID "pl"
# define SQUARE_ID "sq"
# define CYLINDER_ID "cy"
# define TRIANGLE_ID "tr"
# define ID_LEN 1
# define RES_ID "R"
# define AMBIENT_ID "A"
# define CAM_ID "c"
# define LIGHT_ID "l"

/*
** MLX is in BGRA so we change the order of components to RGBA
*/

# define RED_COMP 2
# define GREEN_COMP 1
# define BLUE_COMP 0
# define ALPHA_COMP 3

typedef t_vec3	t_vcolor;

#endif
