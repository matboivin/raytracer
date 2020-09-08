/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:29:07 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/09 00:18:27 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_ambient(t_amb *ambient)
{
	ambient->is_declared = false;
	ambient->ratio = DEFAULT_VALUE;
	ambient->vcolor = create_vec3(DEFAULT_VALUE, DEFAULT_VALUE, DEFAULT_VALUE);
}
