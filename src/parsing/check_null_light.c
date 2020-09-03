/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_null_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/03 16:44:33 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles null light ratio and color which are replaced by
** default values
*/

void	check_null_light(t_vcolor *vcolor, double *ratio)
{
	if ((vcolor->x == 0.0 && vcolor->y == 0.0 && vcolor->z == 0.0)
		|| (*ratio < 0.1))
	{
		*vcolor = create_vec3(1.0, 1.0, 1.0);
		*ratio = 0.1;
	}
}
