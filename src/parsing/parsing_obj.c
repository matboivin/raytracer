/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 01:12:14 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/04 14:45:36 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Parse objects
*/

void			get_sphere(t_scene *scene, char **input)
{
	t_sphere	*result;

	result = (t_sphere *)malloc(sizeof(t_sphere));
	if (result == NULL)
		exit_error(scene, DEFAULT_ERR);
	(*input) += 2;
	result->pos = get_vec3(scene, input);
	result->diameter = get_double(scene, input);
	result->color = get_color(scene, input);
	add_obj_to_scene(scene, result, SPHERE);
	skip_blank(input);
}

void			get_plane(t_scene *scene, char **input)
{
	t_plane		*result;

	result = (t_plane *)malloc(sizeof(t_plane));
	if (result == NULL)
		exit_error(scene, DEFAULT_ERR);
	(*input) += 2;
	result->pos = get_vec3(scene, input);
	result->rot = get_vec3(scene, input);
	if (ft_vec3_range(result->rot, -1.0, 1.0) == false)
		exit_error(scene, PLANE_FMT);
	result->color = get_color(scene, input);
	add_obj_to_scene(scene, result, PLANE);
	skip_blank(input);
}

void			get_square(t_scene *scene, char **input)
{
	t_square	*result;

	result = (t_square *)malloc(sizeof(t_square));
	if (result == NULL)
		exit_error(scene, DEFAULT_ERR);
	(*input) += 2;
	result->pos = get_vec3(scene, input);
	result->rot = get_vec3(scene, input);
	if (ft_vec3_range(result->rot, -1.0, 1.0) == false)
		exit_error(scene, SQUARE_FMT);
	result->side = get_double(scene, input);
	result->color = get_color(scene, input);
	add_obj_to_scene(scene, result, SQUARE);
	skip_blank(input);
}

void			get_cylinder(t_scene *scene, char **input)
{
	t_cyl		*result;

	result = (t_cyl *)malloc(sizeof(t_cyl));
	if (result == NULL)
		exit_error(scene, DEFAULT_ERR);
	(*input) += 2;
	result->pos = get_vec3(scene, input);
	result->rot = get_vec3(scene, input);
	if (ft_vec3_range(result->rot, -1.0, 1.0) == false)
		exit_error(scene, CYL_FMT);
	result->diameter = get_double(scene, input);
	result->side = get_double(scene, input);
	result->color = get_color(scene, input);
	add_obj_to_scene(scene, result, CYLINDER);
	skip_blank(input);
}

void			get_triangle(t_scene *scene, char **input)
{
	t_tri		*result;

	result = (t_tri *)malloc(sizeof(t_tri));
	if (result == NULL)
		exit_error(scene, DEFAULT_ERR);
	(*input) += 2;
	result->vertex1 = get_vec3(scene, input);
	result->vertex2 = get_vec3(scene, input);
	result->vertex3 = get_vec3(scene, input);
	result->color = get_color(scene, input);
	add_obj_to_scene(scene, result, TRIANGLE);
	skip_blank(input);
}
