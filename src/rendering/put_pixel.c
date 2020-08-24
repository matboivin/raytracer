/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:43:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/25 01:38:08 by mboivin          ###   ########.fr       */
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

static uint32_t	rgb_to_int(t_color color)
{
	t_uchar		r;
	t_uchar		g;
	t_uchar		b;

	r = fmin(255.0, fmax(0.0, color.x));
	g = fmin(255.0, fmax(0.0, color.y));
	b = fmin(255.0, fmax(0.0, color.z));
	return (r << 16 | g << 8 | b);
}

void			put_pixel_to_image(t_img *img, t_color color, int x, int y)
{
	uint32_t	pixel;
	int			i;

	if ((ft_n_range(x, 0, img->size_x) == false)
		|| (ft_n_range(y, 0, img->size_y) == false))
		return ;
	i = (x + img->size_x * y) * 4;
	pixel = rgb_to_int(color);
	img->pixels[i + RED_COMP] = (pixel >> 16) & ALPHA;
	img->pixels[i + GREEN_COMP] = (pixel >> 8) & ALPHA;
	img->pixels[i + BLUE_COMP] = (pixel) & ALPHA;
	img->pixels[i + ALPHA_COMP] = 0;
}
