/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ambient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/26 19:19:53 by mboivin          ###   ########.fr       */
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
	scene->amb.vcolor = get_color(scene, input);
	scene->amb.vcolor = scale_vec3(scene->amb.ratio, scene->amb.vcolor);
	skip_blank(input);
}
