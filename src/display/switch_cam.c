/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/07 00:24:35 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function switches camera when user presses space bar, renders image, and
** displays it in window
*/

void	switch_camera(t_scene *scene)
{
	scene->cameras = scene->cameras->next;
	scene->main_cam = scene->cameras->cam;
	render(scene);
	put_image_to_window();
}
