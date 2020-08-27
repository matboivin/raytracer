/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/28 01:23:49 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		render_n_images(t_minirt *env, int n)
{
	t_lstcam	*head;
	t_img		*new_img;
	int			i;

	i = 0;
	head = env->cams;
	while (i < n)
	{
		new_img = malloc_image(env);
		trace_ray(env, env->cams->cam, new_img);
		lstimg_add_back(&(env->imgs), new_img);
		env->cams = env->cams->next;
		i++;
	}
	env->cams = head;
	create_circular_lstimg(env->imgs);
}

void			render(t_minirt *env, bool to_bmp)
{
	if (to_bmp == true)
	{
		render_n_images(env, 1);
		save_bmp(env, BMP_FILENAME);
	}
	ft_printf("Generating %d image(s)\n", env->cam_count);
	render_n_images(env, env->cam_count);
}
