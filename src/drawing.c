/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:43:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/28 13:38:08 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Draw in image
**
** set_pixel() :  Sets the pixel in the MLX image data
** image data = char pointer
**
** To get the index of a pixel in the image data:
** (x position + width * y position) * 4
** 1 pixel = 4 char so we multiply 4 times
**
** 1 pixel = 4 char = RED, GREEN, BLUE, ALPHA
** MLX is in BGRA so we change the order of values to RGBA
** We add defined values to index for each component
*/

void	set_pixel(t_img *img, t_color color, int x, int y)
{
	int	i;

	if (
		(ft_n_range(x, 0, img->size_x) == false)
		|| (ft_n_range(y, 0, img->size_y) == false)
	)
		return ;
	i = (x + img->size_x * y) * 4;
	img->pixels[i + RED_COMP] = color.r;
	img->pixels[i + GREEN_COMP] = color.g;
	img->pixels[i + BLUE_COMP] = color.b;
	img->pixels[i + ALPHA_COMP] = color.a;
}
