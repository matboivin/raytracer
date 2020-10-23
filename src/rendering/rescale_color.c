/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescale_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:43:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/24 01:17:21 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

t_vcolor		rescale_color(t_vcolor vcolor, double min, double max)
{
	t_vcolor	result;

	result.x = fmax(min, fmin(max, vcolor.x));
	result.y = fmax(min, fmin(max, vcolor.y));
	result.z = fmax(min, fmin(max, vcolor.z));
	return (result);
}
