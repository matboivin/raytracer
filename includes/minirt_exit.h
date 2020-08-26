/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_exit.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:48:40 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/27 01:47:10 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_EXIT_H
# define MINIRT_EXIT_H

typedef enum	e_errid
{
	AMB_DUP,
	AMB_FMT,
	CAM_FMT,
	COLOR_FMT,
	COORD_FMT,
	CYL_FMT,
	DOUBLE_FMT,
	FILENAME,
	ID_ERR,
	LIGHT_FMT,
	NO_AMB,
	NO_CAM,
	NO_LIGHT,
	NO_OBJ,
	NO_RES,
	NUM_FMT,
	PLANE_FMT,
	SAVE_OPTION,
	RES_DUP,
	RES_MIN,
	RES_NEG,
	SCENE_FMT,
	SPHERE_FMT,
	SQUARE_FMT,
	DEFAULT_ERR
}				t_errid;

typedef struct	s_err
{
	t_errid		u_id;
	char		*msg;
}				t_err;

void			check_params(int argc, char **argv, bool *to_bmp);
void			put_error(t_errid raised);
void			exit_error(t_minirt *env, t_errid raised);
int				exit_success(t_minirt *env);

#endif
