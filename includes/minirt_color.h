/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:32:52 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/20 21:34:57 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_COLOR_H
# define MINIRT_COLOR_H

typedef unsigned char	t_uchar;

typedef struct	s_color
{
	t_uchar		r;
	t_uchar		g;
	t_uchar		b;
}				t_color;

t_color			create_color(t_uchar p_r, t_uchar p_g, t_uchar p_b);

#endif
