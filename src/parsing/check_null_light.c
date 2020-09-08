/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_null_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/09 01:00:57 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles null light ratio and color which are replaced by
** default values
*/

void	check_null_light(t_vcolor *vcolor, double *ratio)
{
	if (*ratio < MIN_LUM_RATIO)
		*ratio = MIN_LUM_RATIO;
	if (is_null_vec3(*vcolor))
		*vcolor = create_vec3(MAX_RGB, MAX_RGB, MAX_RGB);
}
