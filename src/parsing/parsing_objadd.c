/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objadd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 01:12:14 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/21 15:05:47 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This functions adds parsed object to env
*/

void		add_obj_to_render(t_minirt *env, void *to_add, t_objid obj_id)
{
	t_obj	*new_obj;

	new_obj = create_obj(to_add, obj_id);
	if (!new_obj)
		exit_error(env, ERRNO_TO_STR);
	append_obj(&(env->objs), new_obj);
}
