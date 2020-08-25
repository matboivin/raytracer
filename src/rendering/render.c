/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/26 01:36:17 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	render_n_image(t_scene *scene, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		scene->cameras->cam->img = malloc_image();
		raytrace(scene, scene->cameras->cam);
		if (g_app->img == NULL)
			g_app->img = scene->cameras->cam->img;
		scene->cameras = scene->cameras->next;
		i++;
	}
}

void		render(t_scene *scene, bool to_bmp)
{
	if (to_bmp == true)
	{
		render_n_image(scene, 1);
		save_bmp(scene, BMP_FILENAME);
	}
	ft_printf("Generating %d image(s)\n", scene->cam_count);
	render_n_image(scene, scene->cam_count);
}
