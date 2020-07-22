/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 01:12:14 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/23 01:34:33 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_sphere(t_scene *scene, char **input)
{
	(*input) += 2;
	scene->sphere.pos = get_coord3(scene, input);
	scene->sphere.diameter = get_double(scene, input);
	scene->sphere.color = get_color(scene, input);
	skip_whitespaces(input);
}

void	get_plane(t_scene *scene, char **input)
{
	(*input) += 2;
	scene->plane.pos = get_coord3(scene, input);
	scene->plane.rot = get_coord3(scene, input);
	if (ft_coord3_range(scene->plane.rot, -1.0, 1.0) == false)
		exit_error(scene, PLANE_FMT);
	scene->plane.color = get_color(scene, input);
	skip_whitespaces(input);
}

void	get_square(t_scene *scene, char **input)
{
	(*input) += 2;
	scene->square.pos = get_coord3(scene, input);
	scene->square.rot = get_coord3(scene, input);
	if (ft_coord3_range(scene->square.rot, -1, 1) == false)
		exit_error(scene, SQUARE_FMT);
	scene->square.side = get_double(scene, input);
	scene->square.color = get_color(scene, input);
	skip_whitespaces(input);
}

void	get_cylinder(t_scene *scene, char **input)
{
	(*input) += 2;
	scene->cylinder.pos = get_coord3(scene, input);
	scene->cylinder.rot = get_coord3(scene, input);
	if (ft_coord3_range(scene->cylinder.rot, -1, 1) == false)
		exit_error(scene, TRI_FMT);
	scene->cylinder.diameter = get_double(scene, input);
	scene->cylinder.side = get_double(scene, input);
	scene->cylinder.color = get_color(scene, input);
	skip_whitespaces(input);
}

void	get_triangle(t_scene *scene, char **input)
{
	(*input) += 2;
	scene->triangle.point1 = get_coord3(scene, input);
	scene->triangle.point2 = get_coord3(scene, input);
	scene->triangle.point3 = get_coord3(scene, input);
	scene->triangle.color = get_color(scene, input);
	skip_whitespaces(input);
}
