/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/24 01:14:16 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_num.h"
#include "minirt.h"

/*
** This function parses camera information
*/

static void		parse_camera(t_minirt *env, char **input, t_camera *cam)
{
	cam->pos = get_vec3(env, input);
	cam->dir = get_vec3(env, input);
	if (!ft_vec3_range(cam->dir, REVUNIT_VALUE, UNIT_VALUE))
		exit_error(env, CAM_FMT);
	check_null_vector(
		&(cam->dir),
		create_vec3(DEFAULT_VALUE, DEFAULT_VALUE, UNIT_VALUE));
	if ((cam->dir.x == DEFAULT_VALUE) && (cam->dir.z == DEFAULT_VALUE))
		cam->dir.z = UNIT_VALUE;
	cam->dir = normalize_vec3(cam->dir);
	cam->fov = get_integer(env, input);
	if (!ft_f_range(cam->fov, DEFAULT_VALUE, STRAIGHT_ANGLE))
		exit_error(env, CAM_FMT);
}

/*
** This function adds camera to env
*/

void			get_camera(t_minirt *env, char **input)
{
	t_camera	*new_cam;

	(*input) += ID_LEN;
	new_cam = malloc_cam(env);
	parse_camera(env, input, new_cam);
	append_camera(&(env->cams), new_cam);
	env->cam_count += 1;
	skip_blank(input);
}
