/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:32:52 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/21 16:42:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_COLOR_H
# define MINIRT_COLOR_H

/* MLX is in BGRA so we change the order of values to RGBA */

# define RED_COMP 2
# define GREEN_COMP 1
# define BLUE_COMP 0
# define ALPHA_COMP 3

typedef struct	s_color
{
	t_uchar		r;
	t_uchar		g;
	t_uchar		b;
	t_uchar		a;
}				t_color;

t_color			create_color(t_uchar p_r, t_uchar p_g, t_uchar p_b);

#endif
