/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:43:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/21 22:06:09 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Function: Fills the image starting from pos (0,0) using the color parameter
*/

void	fill_image(t_color color)
{
	int	x;
	int	y;
 
	y = 0;
	while (y < g_app->win_y)
	{
		x = 0;
		while (x < g_app->win_x)
		{
			set_pixel(g_app->img, color, x, y);
			x++;
		}
		y++;
	}
}

/*
** Function: Sets the pixel in the MLX image data
*/

void	set_pixel(t_img *img, t_color color, int x, int y)
{
	int	i;

	if (
		ft_n_range(x, 0, img->size_x) == false
		|| ft_n_range(y, 0, img->size_y) == false
	)
		return ;
	i = (y + img->size_y * x) * 4;
	img->img_data[i + RED_COMP] = color.r;
	img->img_data[i + GREEN_COMP] = color.g;
	img->img_data[i + BLUE_COMP] = color.b;
}