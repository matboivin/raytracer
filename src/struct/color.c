/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:32:55 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/23 18:33:52 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Color
**
** create_color() :  Constructor
*/

t_color		create_color(double p_r, double p_g, double p_b)
{
	t_color	result;

	result.r = p_r;
	result.g = p_g;
	result.b = p_b;
	return (result);
}
