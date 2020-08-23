/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:32:52 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/23 20:18:12 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_COLOR_H
# define MINIRT_COLOR_H

/*
** MLX is in BGRA so we change the order of values to RGBA
*/

# define RED_COMP 2
# define GREEN_COMP 1
# define BLUE_COMP 0
# define ALPHA_COMP 3

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
}				t_color;

t_color			create_color(double p_r, double p_g, double p_b);

#endif
