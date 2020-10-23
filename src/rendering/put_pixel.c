/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:43:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/24 01:14:04 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_num.h"
#include "minirt.h"

/*
** This function puts pixel in the MLX image data using a given color
**
** image data (image pixels) is a char pointer
**
** To get the index of a pixel in the image pixels:
** (x position + width * y position) * 4
**
** 1 pixel = 4 char = RED, GREEN, BLUE, ALPHA
** MLX is in BGRA so we change the order of values to RGBA
** We add defined values to index for each component
*/

void		put_pixel_to_image(t_image *img, t_vcolor vcolor, int x, int y)
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
	int		i;

	if (!ft_n_range(x, DEFAULT_VALUE, img->size_x)
		|| !ft_n_range(y, DEFAULT_VALUE, img->size_y))
		return ;
	i = (x + img->size_x * y) * PIXEL_LEN;
	vcolor = rescale_color(vcolor, DEFAULT_VALUE, MAX_RGB);
	red = vcolor.x;
	green = vcolor.y;
	blue = vcolor.z;
	img->pixels[i + RED_COMP] = red;
	img->pixels[i + GREEN_COMP] = green;
	img->pixels[i + BLUE_COMP] = blue;
	img->pixels[i + ALPHA_COMP] = 0;
}
