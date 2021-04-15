/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:51:48 by mboivin           #+#    #+#             */
/*   Updated: 2021/04/15 18:55:32 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "minirt.h"

t_image		create_image(t_minirt *env)
{
	t_image	result;

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
	result.next = NULL;
	return (result);
}

t_image		*malloc_image(t_minirt *env)
{
	t_image	*result = NULL;

	result = malloc(sizeof(t_image));
	if (!result)
		exit_error(env, (char *)strerror(errno));
	*result = create_image(env);
	return (result);
}

void		destroy_image(void *mlx_ptr, t_image to_destroy)
{
	mlx_destroy_image(mlx_ptr, to_destroy.img_ptr);
}

void		free_image(void *mlx_ptr, t_image *to_free)
{
	destroy_image(mlx_ptr, *to_free);
	free(to_free);
}
