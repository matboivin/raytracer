/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objadd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 01:12:14 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/17 18:36:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This functions adds parsed object to env
*/

void			add_obj_to_scene(t_minirt *env, void *obj, t_objid type)
{
	t_lstobj	*new_obj;

	new_obj = create_obj(obj, type);
	if (!new_obj)
		exit_error(env, DEFAULT_ERR);
	append_obj(&(env->objs), new_obj);
}
