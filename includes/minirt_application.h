/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_application.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:47:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/20 14:23:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_APPLICATION_H
# define MINIRT_APPLICATION_H

typedef struct	s_app
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_x;
	int			win_y;
	char		*title;
	t_img		*img;
}				t_app;

void			start_application(int p_x, int p_y, char *title);
void			quit_application(void);

#endif
