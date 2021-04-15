/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:29:07 by mboivin           #+#    #+#             */
/*   Updated: 2021/04/15 18:55:36 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "minirt.h"

t_light		*malloc_light(t_minirt *env)
{
	t_light	*result = NULL;

	result = malloc(sizeof(t_light));
	if (!result)
		exit_error(env, (char *)strerror(errno));
	result->pos = create_vec3(DEFAULT_VALUE, DEFAULT_VALUE, DEFAULT_VALUE);
	result->ratio = DEFAULT_VALUE;
	result->vcolor = create_vec3(DEFAULT_VALUE, DEFAULT_VALUE, DEFAULT_VALUE);
	result->next = NULL;
	return (result);
}

void		append_light(t_light **lights, t_light *new_light)
{
	t_light	*cursor;

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

void		delete_lights(t_light **lights)
{
	t_light	*cursor;
	t_light	*next_node;

	if (!lights)
		return ;
	if (*lights)
	{
		cursor = *lights;
		while (cursor)
		{
			next_node = cursor->next;
			free(cursor);
			cursor = next_node;
		}
		*lights = NULL;
	}
}
