/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:29:07 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/06 23:26:27 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_lights		*create_light(t_light *light)
{
	t_lights	*result;

	result = (t_lights *)malloc(sizeof(t_lights));
	if (!result)
		return (NULL);
	result->light = light;
	result->next = NULL;
	return (result);
}

void			append_light(t_lights **lights, t_lights *new_light)
{
	t_lights	*cursor;

	if (!lights || !new_light)
		return ;
	if (*lights)
	{
		cursor = *lights;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = new_light;
	}
	else
		*lights = new_light;
}

void			delete_lights(t_lights **lights)
{
	t_lights	*cursor;
	t_lights	*next_node;

	if (!lights)
		return ;
	if (*lights)
	{
		cursor = *lights;
		while (cursor)
		{
			next_node = cursor->next;
			free(cursor->light);
			free(cursor);
			cursor = next_node;
		}
		*lights = NULL;
	}
}
