/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:51:48 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/27 18:10:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** MLX image
**
** create_image()  :  Constructor
** malloc_image()  :  Malloc function
** destroy_image() :  Destructor
** free_image()    :  Free function
*/

t_img		create_image(void)
{
	t_img	result;

	result.size_x = g_app->win_x;
	result.size_y = g_app->win_y;
	result.img_ptr = mlx_new_image(
		g_app->mlx_ptr,
		result.size_x,
		result.size_y
	);
	result.img_data = mlx_get_data_addr(
		result.img_ptr,
		&(result.bpp),
		&(result.size_line),
		&(result.endian)
	);
	return (result);
}

t_img		*malloc_image(void)
{
	t_img	*result;

	result = (t_img *)malloc(sizeof(t_img));
	if (result == NULL)
		put_error(DEFAULT_ERR);
	*result = create_image();
	return (result);
}

void		destroy_image(t_img to_destroy)
{
	mlx_destroy_image(g_app->mlx_ptr, to_destroy.img_ptr);
}

void		free_image(t_img *to_free)
{
	destroy_image(*to_free);
	free(to_free);
}
