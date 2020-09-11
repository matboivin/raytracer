/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray_to_objs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/11 21:50:31 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_lstobj		*trace_ray_to_objs(t_lstobj *objs, t_ray *ray)
{
	t_lstobj	*cursor;
	t_lstobj	*nearest_obj;
	double		t;

	t = INFINITY;
	nearest_obj = NULL;
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
