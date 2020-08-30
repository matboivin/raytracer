/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/30 19:16:39 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		render_n_images(t_minirt *env, int n)
{
	t_lstcam	*head;
	t_lstimg	*new_img;
	int			i;

	i = 0;
	head = env->cams;
	while (i < n)
	{
		new_img = new_lstimg(malloc_image(env));
		trace_ray(env, env->cams->cam, new_img->img);
		lstimg_append(&(env->imgs), new_img);
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
	ft_printf(
		"Press space bar to switch view point if there are several cameras\n");
	ft_printf("Press ESC to exit\n");
	render_n_images(env, env->cam_count);
}
