/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 01:12:14 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/31 17:07:55 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Parse objects
*/

void			add_object(t_scene *scene, void *obj_data, char *type)
{
	t_lstobj	*new_obj;

	new_obj= new_lstobj(obj_data, type);
	if (new_obj== NULL)
		exit_error(scene, DEFAULT_ERR);
	lstobj_add_back(&(scene->objs), new_obj);
}

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
	add_object(scene, result, "sp");
	skip_blank(input);
}

void	get_plane(t_scene *scene, char **input)
{
	t_plane	*result;

	result = (t_plane *)malloc(sizeof(t_plane));
	if (result == NULL)
		exit_error(scene, DEFAULT_ERR);
	(*input) += 2;
	result->pos = get_vec3(scene, input);
	result->rot = get_vec3(scene, input);
	if (ft_vec3_range(result->rot, -1.0, 1.0) == false)
		exit_error(scene, PLANE_FMT);
	result->color = get_color(scene, input);
	add_object(scene, result, "pl");
	skip_blank(input);
}

void	get_square(t_scene *scene, char **input)
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
	add_object(scene, result, "sq");
	skip_blank(input);
}

void	get_cylinder(t_scene *scene, char **input)
{
	t_cyl	*result;

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
	add_object(scene, result, "cy");
	skip_blank(input);
}

void	get_triangle(t_scene *scene, char **input)
{
	t_tri	*result;

	result = (t_tri *)malloc(sizeof(t_tri));
	if (result == NULL)
		exit_error(scene, DEFAULT_ERR);
	(*input) += 2;
	result->point1 = get_vec3(scene, input);
	result->point2 = get_vec3(scene, input);
	result->vec3 = get_vec3(scene, input);
	result->color = get_color(scene, input);
	add_object(scene, result, "tr");
	skip_blank(input);
}
