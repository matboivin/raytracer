/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/14 02:06:44 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function parses Resolution
*/

void	get_resolution(t_minirt *env, char **input)
{
	if (env->res.is_declared)
		exit_error(env, RES_DUP);
	env->res.is_declared = true;
	(*input) += IDENTIFIER_LEN;
	env->res.size_x = get_integer(env, input);
	env->res.size_y = get_integer(env, input);
	if ((env->res.size_x < MIN_RES) || (env->res.size_y < MIN_RES))
		exit_error(env, RES_LOW);
	skip_blank(input);
}
