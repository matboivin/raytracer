/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:29:07 by mboivin           #+#    #+#             */
/*   Updated: 2021/05/20 15:06:21 by mboivin          ###   ########.fr       */
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
	t_light	*cursor = NULL;

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
	t_light	*cursor = NULL;
	t_light	*next_node = NULL;

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
