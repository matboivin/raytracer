/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_application.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:47:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/23 23:40:15 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_APPLICATION_H
# define MINIRT_APPLICATION_H

/*
** Struct: Application that interacts with MLX
**
** mlx_ptr: Pointer returned by the mlx_init() function
** win_ptr: Pointer to a MLX window
** win_x: Width of the window
** win_y: Height of the window
** title: Title of the window
** img: Content of the window
*/

typedef struct	s_app
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_x;
	int			win_y;
	char		*title;
	t_img		*img;
}				t_app;

void			open_app(int p_x, int p_y, char *title);
void			quit_app(void);
int				run_app(void);

#endif
