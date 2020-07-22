/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:29:07 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/22 21:34:15 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_resolution(t_res *res)
{
	res->is_declared = false;
	res->size_x = 0;
	res->size_y = 0;
}

void	create_ambient(t_amb *amb)
{
	amb->is_declared = false;
	amb->ratio = 0.0;
	amb->color = create_color(0, 0, 0);
}

void	create_scene(t_scene *scene)
{
	create_resolution(&scene->res);
	create_ambient(&scene->amb);
}

void	destroy_scene(t_scene *to_destroy)
{
	(void)to_destroy;
}
