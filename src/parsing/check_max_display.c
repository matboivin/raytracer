/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2021/05/20 15:16:09 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles render size if bigger than screen size
*/

void		check_max_display(t_minirt *env)
{
	int		max_x, max_y;

	mlx_get_screen_size(env->mlx_ptr, &max_x, &max_y);
	if (env->res.size_x > max_x)
		env->res.size_x = max_x;
	if (env->res.size_y > max_y)
		env->res.size_y = max_y;
}
