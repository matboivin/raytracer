/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray_to_objs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2021/05/20 15:26:32 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

t_obj		*trace_ray_to_objs(t_obj *objs, t_ray *ray)
{
	t_obj	*cursor;
	t_obj	*nearest_obj = NULL;
	double	t = INFINITY;

	cursor = objs;
	while (cursor)
	{
		if (hit(cursor, ray, &t))
		{
			if (t < ray->t_nearest)
			{
				ray->t_nearest = t;
				nearest_obj = cursor;
			}
		}
		cursor = cursor->next;
	}
	return (nearest_obj);
}
