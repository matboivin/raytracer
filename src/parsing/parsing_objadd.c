/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objadd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 01:12:14 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/07 21:35:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This functions adds parsed object to env
*/

void			add_obj_to_scene(t_minirt *env, void *obj, t_objid type)
{
	t_lstobj	*new_obj;

	new_obj = new_lstobj(obj, type);
	if (!new_obj)
		exit_error(env, DEFAULT_ERR);
	lstobj_append(&(env->objs), new_obj);
}
