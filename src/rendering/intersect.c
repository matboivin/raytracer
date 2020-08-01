/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/01 18:07:09 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Check if a ray intersects any objects
*/

void		*intersect(t_scene *scene, t_ray ray)
{
	void	*nearest_obj;

	(void)ray;
	// TODO: cast color
	nearest_obj = scene->objs->obj; // tmp
	return (nearest_obj);
}
