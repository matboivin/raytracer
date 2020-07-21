/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:32:55 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/20 21:36:05 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		create_color(t_uchar p_r, t_uchar p_g, t_uchar p_b)
{
	t_color	result;

	result.r = p_r;
	result.g = p_g;
	result.b = p_b;
	return (result);
}