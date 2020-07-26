/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 00:57:27 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/27 00:09:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Initialize objects
**
** create_sphere()
** create_plane()
** create_square()
** create_cylinder()
** create_triangle()
*/

void	create_sphere(t_sphere *sphere)
{
	sphere->pos = create_point3(0.0, 0.0, 0.0);
	sphere->diameter = 0.0;
	sphere->color = create_color(0.0, 0.0, 0.0);
}

void	create_plane(t_plane *plane)
{
	plane->pos = create_point3(0.0, 0.0, 0.0);
	plane->rot = create_point3(0.0, 0.0, 0.0);
	plane->color = create_color(0.0, 0.0, 0.0);
}

void	create_square(t_square *square)
{
	square->pos = create_point3(0.0, 0.0, 0.0);
	square->rot = create_point3(0.0, 0.0, 0.0);
	square->side = 0.0;
	square->color = create_color(0.0, 0.0, 0.0);
}

void	create_cylinder(t_cyl *cylinder)
{
	cylinder->pos = create_point3(0.0, 0.0, 0.0);
	cylinder->rot = create_point3(0.0, 0.0, 0.0);
	cylinder->diameter = 0.0;
	cylinder->side = 0.0;
	cylinder->color = create_color(0.0, 0.0, 0.0);
}

void	create_triangle(t_tri *triangle)
{
	triangle->point1 = create_point3(0.0, 0.0, 0.0);
	triangle->point2 = create_point3(0.0, 0.0, 0.0);
	triangle->point3 = create_point3(0.0, 0.0, 0.0);
	triangle->color = create_color(0.0, 0.0, 0.0);
}
