/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:51:48 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/11 23:35:09 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_img		create_image(t_minirt *env)
{
	t_img	result;

	result.size_x = env->res.size_x;
	result.size_y = env->res.size_y;
	result.img_ptr = mlx_new_image(
		env->mlx_ptr,
		result.size_x,
		result.size_y);
	result.pixels = mlx_get_data_addr(
		result.img_ptr,
		&(result.bpp),
		&(result.size_line),
		&(result.endian));
	return (result);
}

t_img		*malloc_image(t_minirt *env)
{
	t_img	*result;

	result = (t_img *)malloc(sizeof(t_img));
	if (!result)
		print_error(DEFAULT_ERR);
	*result = create_image(env);
	return (result);
}

void		destroy_image(void *mlx_ptr, t_img to_destroy)
{
	mlx_destroy_image(mlx_ptr, to_destroy.img_ptr);
}

void		free_image(void *mlx_ptr, t_img *to_free)
{
	destroy_image(mlx_ptr, *to_free);
	free(to_free);
}
