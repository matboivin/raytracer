/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_null_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/17 21:01:49 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles null vectors which are replaced by a default vector
*/

static bool	is_null_vector(t_vec3 to_check)
{
	if (norm_vec3(to_check) == 0)
		return (true);
	return (false);
}

void		check_null_vector(t_vec3 *to_check, t_vec3 default_vec)
{
	if (is_null_vector(*to_check) == true)
		cpy_vec3(to_check, default_vec);
}
