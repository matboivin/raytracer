/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ambient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/22 18:19:36 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function parses Ambient light
*/

void	get_ambient(t_scene *scene, char **input)
{
	if (scene->amb.is_declared == true)
		exit_error(scene, AMB_DUP);
	scene->amb.is_declared = true;
	(*input) += 2;
	scene->amb.ratio = get_double(scene, input);
	if (ft_f_range(scene->amb.ratio, 0.0, 1.0) == false)
		exit_error(scene, AMB_FMT);
	scene->amb.color = get_color(scene, input);
	skip_blank(input);
}
