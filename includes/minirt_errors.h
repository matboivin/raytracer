/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_errors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:48:40 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/22 22:21:17 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ERRORS_H
# define MINIRT_ERRORS_H

typedef enum	e_errid
{
	AMB_DUP,
	FILENAME,
	ID_ERRR,
	MALLOC_APP,
	MALLOC_IMG,
	SAVE_OPTION,
	RES_DUP,
	RES_NEG,
	SCENE_FMT,
	DEFAULT
}				t_errid;

typedef struct	s_err
{
	t_errid		u_id;
	char		*msg;
}				t_err;

extern struct s_err	g_err[];

void			put_usage(void);
void			*catch_err(t_errid raised);
void			put_error(t_errid raised);
void			exit_error(t_scene *scene, t_errid raised);
int				exit_success(t_scene *scene);

#endif
