/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/24 00:31:52 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	ft_coord3_range(t_coord3 coord, double start, double end)
{
	if (
		ft_f_range(coord.x, start, end) == false
		|| ft_f_range(coord.y, start, end) == false
		|| ft_f_range(coord.z, start, end) == false
	)
		return (false);
	return (true);
}

void	skip_whitespaces(char **s)
{
	while (ft_isspace(**s) == true)
		(*s)++;
}

int		skip_separator(char **s, char sep)
{
	if ((**s) == sep)
	{
		(*s)++;
		return (1);
	}
	return (0);
}

void	skip_integer(char **s)
{
	skip_separator(s, '-');
	while (ft_isdigit(**s) == true)
		(*s)++;
}

void	skip_double(t_scene *scene, char **s)
{
	skip_integer(s);
	if (skip_separator(s, '.'))
	{
		if (ft_isdigit(**s) == false)
			exit_error(scene, SCENE_FMT);
		while (ft_isdigit(**s) == true)
			(*s)++;
	}
}
