/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 01:12:14 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/14 23:54:09 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** These functions parse objects
*/

void			get_sphere(t_minirt *env, char **input)
{
	t_sphere	*result;

	result = (t_sphere *)malloc(sizeof(t_sphere));
	if (!result)
		exit_error(env, DEFAULT_ERR);
	(*input) += ID_OBJ_LEN;
	result->center = get_vec3(env, input);
	result->radius = get_double(env, input) * 0.5;
	result->vcolor = get_color(env, input);
	add_obj_to_scene(env, result, SPHERE);
	skip_blank(input);
}

void			get_plane(t_minirt *env, char **input)
{
	t_plane		*result;

	result = (t_plane *)malloc(sizeof(t_plane));
	if (!result)
		exit_error(env, DEFAULT_ERR);
	(*input) += ID_OBJ_LEN;
	result->center = get_vec3(env, input);
	result->dir = get_vec3(env, input);
	if (!ft_vec3_range(result->dir, REVUNIT_VALUE, UNIT_VALUE))
		exit_error(env, PLANE_FMT);
	check_null_vector(
		&(result->dir),
		create_vec3(DEFAULT_VALUE, UNIT_VALUE, DEFAULT_VALUE));
	result->dir = normalize_vec3(result->dir);
	result->vcolor = get_color(env, input);
	add_obj_to_scene(env, result, PLANE);
	skip_blank(input);
}

void			get_square(t_minirt *env, char **input)
{
	t_square	*result;

	result = (t_square *)malloc(sizeof(t_square));
	if (!result)
		exit_error(env, DEFAULT_ERR);
	(*input) += ID_OBJ_LEN;
	result->center = get_vec3(env, input);
	result->dir = get_vec3(env, input);
	if (!ft_vec3_range(result->dir, REVUNIT_VALUE, UNIT_VALUE))
		exit_error(env, SQUARE_FMT);
	check_null_vector(
		&(result->dir),
		create_vec3(DEFAULT_VALUE, UNIT_VALUE, DEFAULT_VALUE));
	result->dir = normalize_vec3(result->dir);
	result->side = get_double(env, input);
	result->vcolor = get_color(env, input);
	add_obj_to_scene(env, result, SQUARE);
	skip_blank(input);
}

void			get_cylinder(t_minirt *env, char **input)
{
	t_cyl		*result;

	result = (t_cyl *)malloc(sizeof(t_cyl));
	if (!result)
		exit_error(env, DEFAULT_ERR);
	(*input) += ID_OBJ_LEN;
	result->base1 = get_vec3(env, input);
	result->dir = get_vec3(env, input);
	if (!ft_vec3_range(result->dir, REVUNIT_VALUE, UNIT_VALUE))
		exit_error(env, CYL_FMT);
	check_null_vector(
		&(result->dir),
		create_vec3(DEFAULT_VALUE, UNIT_VALUE, DEFAULT_VALUE));
	result->dir = normalize_vec3(result->dir);
	result->radius = get_double(env, input) * 0.5;
	result->height = get_double(env, input);
	result->vcolor = get_color(env, input);
	result->base2 = add_vec3(
		result->base1,
		scale_vec3(result->height, result->dir));
	add_obj_to_scene(env, result, CYLINDER);
	skip_blank(input);
}

void			get_triangle(t_minirt *env, char **input)
{
	t_tri		*result;

	result = (t_tri *)malloc(sizeof(t_tri));
	if (!result)
		exit_error(env, DEFAULT_ERR);
	(*input) += ID_OBJ_LEN;
	result->vertex1 = get_vec3(env, input);
	result->vertex2 = get_vec3(env, input);
	result->vertex3 = get_vec3(env, input);
	result->vcolor = get_color(env, input);
	result->normal = get_triangle_normal(result);
	add_obj_to_scene(env, result, TRIANGLE);
	skip_blank(input);
}
