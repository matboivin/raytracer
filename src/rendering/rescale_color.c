/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescale_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:43:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/26 19:21:11 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vcolor		rescale_color(t_vcolor vcolor, double max, double min)
{
	t_vcolor	result;

	result.x = fmin(max, fmax(min, vcolor.x));
	result.y = fmin(max, fmax(min, vcolor.y));
	result.z = fmin(max, fmax(min, vcolor.z));
	return (result);
}
