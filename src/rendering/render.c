/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/27 00:30:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		render_n_image(t_minirt *env, int n)
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
		lstimg_add_back(&(env->imgs), new_img);
		if (env->active_img == NULL)
			env->active_img = env->imgs->img;
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
		render_n_image(env, 1);
		save_bmp(env, BMP_FILENAME);
	}
	ft_printf("Generating %d image(s)\n", env->cam_count);
	render_n_image(env, env->cam_count);
}
