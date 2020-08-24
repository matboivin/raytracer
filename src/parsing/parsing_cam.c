/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/24 18:49:17 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function parses camera information
*/

static t_cam	*create_camera(t_scene *scene, char **input)
{
	t_cam		*result;

	result = (t_cam *)malloc(sizeof(t_cam));
	if (result == NULL)
		exit_error(scene, DEFAULT_ERR);
	result->pos = get_vec3(scene, input);
	result->dir = get_vec3(scene, input);
	if (ft_vec3_range(result->dir, -1.0, 1.0) == false)
		exit_error(scene, CAM_FMT);
	check_null_vector(&(result->dir), create_vec3(0.0, 0.0, 1.0));
	result->dir = normalize_vec3(result->dir);
	result->fov = get_integer(scene, input);
	if (ft_n_range(result->fov, 0, 180) == false)
		exit_error(scene, CAM_FMT);
	result->img = NULL;
	return (result);
}

/*
** This function adds camera to scene
*/

void			get_camera(t_scene *scene, char **input)
{
	t_cam		*cam_data;
	t_lstcam	*new_cam;

	(*input) += 2;
	cam_data = create_camera(scene, input);
	new_cam = new_lstcam(cam_data);
	if (new_cam == NULL)
		exit_error(scene, DEFAULT_ERR);
	lstcam_add_back(&(scene->cameras), new_cam);
	scene->cam_count += 1;
	skip_blank(input);
}
