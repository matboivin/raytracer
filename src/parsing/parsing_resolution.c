/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/22 18:19:23 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function parses Resolution
*/

void	get_resolution(t_scene *scene, char **input)
{
	if (scene->res.is_declared == true)
		exit_error(scene, RES_DUP);
	scene->res.is_declared = true;
	(*input) += 2;
	scene->res.size_x = get_integer(scene, input);
	scene->res.size_y = get_integer(scene, input);
	if ((scene->res.size_x < 1) || (scene->res.size_y < 1))
		exit_error(scene, RES_NEG);
	if ((scene->res.size_x < 100) || (scene->res.size_y < 100))
		exit_error(scene, RES_MIN);
	skip_blank(input);
}
