/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_exit.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:48:40 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/06 12:31:44 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_EXIT_H
# define MINIRT_EXIT_H

/*
** Error identifiers
*/

typedef enum	e_errid
{
	DEFAULT_ERR = -1,
	AMB_DUP,
	AMB_FMT,
	CAM_FMT,
	COLOR_FMT,
	COORD_FMT,
	CYL_FMT,
	FLOAT_FMT,
	FILENAME_ERR,
	ID_ERR,
	LIGHT_FMT,
	NO_AMB,
	NO_CAM,
	NO_LIGHT,
	NO_OBJ,
	NO_RES,
	NUM_FMT,
	OPT_ERR,
	PLANE_FMT,
	RES_DUP,
	RES_LOW,
	SCENE_FMT,
	SPHERE_FMT,
	SQUARE_FMT
}				t_errid;

/*
** Error identifiers associated to error messages
*/

typedef struct	s_err
{
	t_errid		u_id;
	char		*msg;
}				t_err;

void			check_params(int argc, char **argv, bool *to_bmp);
void			print_error(t_errid raised);
void			exit_error(t_minirt *env, t_errid raised);
int				exit_success(t_minirt *env);

#endif
