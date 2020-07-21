/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:43:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/21 18:17:07 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Function: Fill the image starting from pos (0,0) using the color parameter
*/

void	fill_image(t_color color)
{
	int	cursor_x;
	int	cursor_y;

	cursor_x = 0;
	while (cursor_x < g_app->win_x)
	{
		cursor_y = 0;
		while (cursor_y < g_app->win_y)
		{
			set_pixel(g_app->img, color, cursor_x, cursor_y);
			cursor_y++;
		}
		cursor_x++;
	}
}

/*
** Function: Set the pixel in the MLX image data
**
** Formula: x position * 4 + 4 * size_line * y position
** img->size_x = 4 * img->line
*/

void	set_pixel(t_img *img, t_color color, int x, int y)
{
	int	i;

	if (
		ft_n_range(x, 0, img->size_x) == false
		|| ft_n_range(y, 0, img->size_y) == false
	)
		return ;
	i = (x + img->size_x * y) * 4;
	img->img_data[i + RED_COMP] = color.r;
	img->img_data[i + GREEN_COMP] = color.g;
	img->img_data[i + BLUE_COMP] = color.b;
}
