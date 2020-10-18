/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/18 13:49:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		render_n_images(t_minirt *env, uint32_t n)
{
	t_camera	*cursor;
	t_image		*new_img;
	uint32_t	i;

	i = 0;
	cursor = env->cams;
	while (i < n)
	{
		new_img = malloc_image(env);
		trace_ray(env, cursor, new_img);
		append_image(&(env->imgs), new_img);
		cursor = cursor->next;
		i++;
	}
	create_circular_img_list(env->imgs);
}

void			render(t_minirt *env, bool to_bmp)
{
	if (to_bmp)
	{
		render_n_images(env, 1);
		save_bmp(env, BMP_FILENAME);
	}
	ft_printf("Generating %d image(s)\n", env->cam_count);
	ft_printf(
		"Press space bar to switch view point in case of several cameras\n");
	ft_printf("Press ESC to exit\n");
	render_n_images(env, env->cam_count);
}
