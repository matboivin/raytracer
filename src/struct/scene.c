/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:29:07 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/02 00:07:16 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Initialize scene elements
**
** create_resolution() :  Constructor for Resolution
** create_ambient()    :  Constructor for Ambient Light
** create_scene()      :  Constructor for all scene elements
** destroy_scene()     :  Destructor for all scene elements
*/

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
	create_resolution(&(scene->res));
	create_ambient(&(scene->amb));
	scene->cameras = NULL;
	scene->main_cam = NULL;
	scene->lights = NULL;
	scene->lights_head = NULL;
	scene->objs = NULL;
	scene->objs_head = NULL;
}

void	destroy_scene(t_scene *to_destroy)
{
	lstcam_clear(&(to_destroy->cameras));
	lstlight_clear(&(to_destroy->lights_head));
	lstobj_clear(&(to_destroy->objs_head));
}
