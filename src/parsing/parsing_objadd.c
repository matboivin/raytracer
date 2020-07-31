/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objadd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 01:12:14 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/31 17:26:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Add parsed object to scene
*/

void			add_obj_to_scene(t_scene *scene, void *obj, char *type)
{
	t_lstobj	*new_obj;

	new_obj = new_lstobj(obj, type);
	if (new_obj == NULL)
		exit_error(scene, DEFAULT_ERR);
	lstobj_add_back(&(scene->objs), new_obj);
}
