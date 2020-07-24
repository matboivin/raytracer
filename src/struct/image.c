/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:51:48 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/24 17:07:48 by mboivin          ###   ########.fr       */
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

t_img		create_image(int p_x, int p_y)
{
	t_img	result;

	result.size_x = p_x;
	result.size_y = p_y;
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

t_img		*malloc_image(int p_x, int p_y)
{
	t_img	*result;

	result = (t_img *)malloc(sizeof(t_img));
	if (result == NULL)
		put_error(DEFAULT_ERR);
	*result = create_image(p_x, p_y);
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
