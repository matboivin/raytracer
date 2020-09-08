/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescale_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:43:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/08 23:27:06 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vcolor		rescale_color(t_vcolor vcolor, double min, double max)
{
	t_vcolor	result;

	result.x = fmax(min, fmin(max, vcolor.x));
	result.y = fmax(min, fmin(max, vcolor.y));
	result.z = fmax(min, fmin(max, vcolor.z));
	return (result);
}
