/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:43:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/30 18:50:39 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function puts pixel in the MLX image data using a given color
**
** image data (image pixels) is a char pointer
**
** To get the index of a pixel in the image pixels:
** (x position + width * y position) * 4
** 1 pixel = 4 char so we multiply 4 times
*/

void			put_pixel_to_image(t_img *img, t_vcolor vcolor, int x, int y)
{
	t_uchar		r;
	t_uchar		g;
	t_uchar		b;
	int			i;

	if ((ft_n_range(x, 0, img->size_x) == false)
		|| (ft_n_range(y, 0, img->size_y) == false))
		return ;
	i = (x + img->size_x * y) * 4;
	vcolor = rescale_color(vcolor, 255.0, 0.0);
	r = vcolor.x;
	g = vcolor.y;
	b = vcolor.z;
	img->pixels[i + RED_COMP] = r;
	img->pixels[i + GREEN_COMP] = g;
	img->pixels[i + BLUE_COMP] = b;
	img->pixels[i + ALPHA_COMP] = 0;
}
