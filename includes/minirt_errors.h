/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_errors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:48:40 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/23 19:24:18 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ERRORS_H
# define MINIRT_ERRORS_H

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
	ID_ERRR,
	LIGHT_FMT,
	MALLOC_APP,
	MALLOC_IMG,
	NUM_FMT,
	PLANE_FMT,
	SAVE_OPTION,
	RES_DUP,
	RES_NEG,
	SCENE_FMT,
	SPHERE_FMT,
	SQUARE_FMT,
	TRI_FMT,
	DEFAULT
}				t_errid;

typedef struct	s_err
{
	t_errid		u_id;
	char		*msg;
}				t_err;

extern struct s_err	g_err[];

void			put_usage(void);
char			*catch_err(t_errid raised);
void			put_error(t_errid raised);
void			exit_error(t_scene *scene, t_errid raised);
int				exit_success(t_scene *scene);

#endif
