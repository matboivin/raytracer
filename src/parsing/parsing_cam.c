/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/06 23:17:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function parses camera information
*/

static t_cam	*parse_camera(t_minirt *env, char **input)
{
	t_cam		*result;

	result = (t_cam *)malloc(sizeof(t_cam));
	if (!result)
		exit_error(env, DEFAULT_ERR);
	result->pos = get_vec3(env, input);
	result->dir = get_vec3(env, input);
	if (!ft_vec3_range(result->dir, REVUNIT_VALUE, UNIT_VALUE))
		exit_error(env, CAM_FMT);
	check_null_vector(
		&(result->dir),
		create_vec3(DEFAULT_VALUE, DEFAULT_VALUE, UNIT_VALUE));
	if ((result->dir.x == DEFAULT_VALUE) && (result->dir.z == DEFAULT_VALUE))
		result->dir.z = UNIT_VALUE;
	result->dir = normalize_vec3(result->dir);
	result->fov = get_integer(env, input);
	if (!ft_f_range(result->fov, DEFAULT_VALUE, STRAIGHT_ANGLE))
		exit_error(env, CAM_FMT);
	return (result);
}

/*
** This function adds camera to env
*/

void			get_camera(t_minirt *env, char **input)
{
	t_cam		*cam_data;
	t_cameras	*new_cam;

	(*input) += ID_LEN;
	cam_data = parse_camera(env, input);
	new_cam = create_cam(cam_data);
	if (!new_cam)
		exit_error(env, DEFAULT_ERR);
	append_camera(&(env->cams), new_cam);
	env->cam_count += 1;
	skip_blank(input);
}
