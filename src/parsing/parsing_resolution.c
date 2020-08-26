/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/26 23:08:58 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function parses Resolution
*/

void	get_resolution(t_minirt *env, char **input)
{
	if (env->res.is_declared == true)
		exit_error(env, RES_DUP);
	env->res.is_declared = true;
	(*input) += 2;
	env->res.size_x = get_integer(env, input);
	env->res.size_y = get_integer(env, input);
	if ((env->res.size_x < 1) || (env->res.size_y < 1))
		exit_error(env, RES_NEG);
	if ((env->res.size_x < 100) || (env->res.size_y < 100))
		exit_error(env, RES_MIN);
	skip_blank(input);
}
