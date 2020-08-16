/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_null_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/16 18:23:36 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles null vectors which are replaced by a default vector
*/

static bool	is_null_vector(t_vec3 *to_check)
{
	if ((to_check->x == 0.0) && (to_check->y == 0.0) && (to_check->z == 0.0))
		return (true);
	return (false);
}

void		check_null_vector(t_vec3 *to_check, t_vec3 default_vec)
{
	if (is_null_vector(to_check) == true)
		cpy_vec3(to_check, default_vec);
}
