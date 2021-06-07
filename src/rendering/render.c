/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2021/06/07 17:32:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minirt.h"

static void		render_n_images(t_minirt *env, uint32_t n)
{
	t_camera	*cursor = NULL;
	t_image		*new_img = NULL;
	uint32_t	i = 0;

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
	printf(
		"Generating %d image(s)\n\
		\rPress space bar to switch view point in case of several cameras\n\
		\rPress ESC to exit\n",
		env->cam_count);
	render_n_images(env, env->cam_count);
}
