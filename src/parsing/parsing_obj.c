/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 01:12:14 by mboivin           #+#    #+#             */
/*   Updated: 2021/03/29 19:09:41 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "minirt.h"

/*
** These functions parse objects
*/

void			get_sphere(t_minirt *env, char **input)
{
	t_sphere	*result;

	result = malloc(sizeof(t_sphere));
	if (!result)
		exit_error(env, (char *)strerror(errno));
	(*input) += ID_OBJ_LEN;
	result->center = get_vec3(env, input);
	result->radius = get_double(env, input) * HALF_DIV;
	result->vcolor = get_color(env, input);
	add_obj_to_render(env, result, SPHERE);
	skip_blank(input);
}

void			get_plane(t_minirt *env, char **input)
{
	t_plane		*result;

	result = malloc(sizeof(t_plane));
	if (!result)
		exit_error(env, (char *)strerror(errno));
	(*input) += ID_OBJ_LEN;
	result->center = get_vec3(env, input);
	result->dir = get_vec3(env, input);
	if (!ft_vec3_range(result->dir, REVUNIT_VALUE, UNIT_VALUE))
		exit_error(env, "Invalid scene: Plane badly formatted.");
	check_null_vector(
		&(result->dir),
		create_vec3(DEFAULT_VALUE, UNIT_VALUE, DEFAULT_VALUE));
	result->dir = normalize_vec3(result->dir);
	result->vcolor = get_color(env, input);
	add_obj_to_render(env, result, PLANE);
	skip_blank(input);
}

void			get_square(t_minirt *env, char **input)
{
	t_square	*result;

	result = malloc(sizeof(t_square));
	if (!result)
		exit_error(env, (char *)strerror(errno));
	(*input) += ID_OBJ_LEN;
	result->center = get_vec3(env, input);
	result->dir = get_vec3(env, input);
	if (!ft_vec3_range(result->dir, REVUNIT_VALUE, UNIT_VALUE))
		exit_error(env, "Invalid scene: Square badly formatted.");
	check_null_vector(
		&(result->dir),
		create_vec3(DEFAULT_VALUE, UNIT_VALUE, DEFAULT_VALUE));
	result->dir = normalize_vec3(result->dir);
	result->side = get_double(env, input);
	result->vcolor = get_color(env, input);
	add_obj_to_render(env, result, SQUARE);
	skip_blank(input);
}

void			get_cylinder(t_minirt *env, char **input)
{
	t_cyl		*result;

	result = malloc(sizeof(t_cyl));
	if (!result)
		exit_error(env, (char *)strerror(errno));
	(*input) += ID_OBJ_LEN;
	result->base1 = get_vec3(env, input);
	result->dir = get_vec3(env, input);
	if (!ft_vec3_range(result->dir, REVUNIT_VALUE, UNIT_VALUE))
		exit_error(env, "Invalid scene: Cylinder badly formatted.");
	check_null_vector(
		&(result->dir),
		create_vec3(DEFAULT_VALUE, UNIT_VALUE, DEFAULT_VALUE));
	result->dir = normalize_vec3(result->dir);
	result->radius = get_double(env, input) * HALF_DIV;
	result->height = get_double(env, input);
	result->vcolor = get_color(env, input);
	result->base2 = add_vec3(
		result->base1,
		scale_vec3(result->height, result->dir));
	add_obj_to_render(env, result, CYLINDER);
	skip_blank(input);
}

void			get_triangle(t_minirt *env, char **input)
{
	t_tri		*result;

	result = malloc(sizeof(t_tri));
	if (!result)
		exit_error(env, (char *)strerror(errno));
	(*input) += ID_OBJ_LEN;
	result->vertex1 = get_vec3(env, input);
	result->vertex2 = get_vec3(env, input);
	result->vertex3 = get_vec3(env, input);
	result->vcolor = get_color(env, input);
	result->normal = get_triangle_normal(result);
	add_obj_to_render(env, result, TRIANGLE);
	skip_blank(input);
}
