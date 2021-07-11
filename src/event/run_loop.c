/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 18:59:27 by mboivin           #+#    #+#             */
/*   Updated: 2021/07/11 16:25:17 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function runs a loop that listens to events
*/

int	run_loop(t_minirt *env)
{
	mlx_loop(env->mlx_ptr);
	return (EXIT_SUCCESS);
}
