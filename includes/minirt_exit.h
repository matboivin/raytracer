/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_exit.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:48:40 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/16 18:04:10 by mboivin          ###   ########.fr       */
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
	MISS_RA,
	MISS_CAM,
	MISS_LIGHT,
	MISS_OBJ,
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

extern struct s_err	g_err[];

void			check_params(int argc, char **argv);
void			put_warn_res(void);
void			put_error(t_errid raised);
void			exit_error(t_scene *scene, t_errid raised);
int				exit_success(t_scene *scene);

#endif
