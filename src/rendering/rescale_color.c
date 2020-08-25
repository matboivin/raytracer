/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescale_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:43:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/25 23:17:30 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		rescale_color(t_color color, double max, double min)
{
	t_color	result;

	result.x = fmin(max, fmax(min, color.x));
	result.y = fmin(max, fmax(min, color.y));
	result.z = fmin(max, fmax(min, color.z));
	return (result);
}
