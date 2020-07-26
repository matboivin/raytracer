/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/27 00:11:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Utils for parsing
**
** ft_point3_range()  :  Checks if point values are in a given range
** skip_blank()       :  Skips spaces
** skip_separator()   :  Skips a given separator (expected: , . -)
** skip_digits()      :  Skips digits
** skip_double()      :  Skips double number
*/

bool	ft_point3_range(t_point3 point, double start, double end)
{
	if (
		ft_f_range(point.x, start, end) == false
		|| ft_f_range(point.y, start, end) == false
		|| ft_f_range(point.z, start, end) == false
	)
		return (false);
	return (true);
}

void	skip_blank(char **s)
{
	while (ft_isblank(**s) == true)
		(*s)++;
}

int		skip_separator(char **s, int sep)
{
	if ((**s) == sep)
	{
		(*s)++;
		return (1);
	}
	return (0);
}

void	skip_digits(char **s)
{
	while (ft_isdigit(**s) == true)
		(*s)++;
}

void	skip_double(t_scene *scene, char **s)
{
	skip_separator(s, '-');
	skip_digits(s);
	if (skip_separator(s, '.'))
	{
		if (ft_isdigit(**s) == false)
			exit_error(scene, DOUBLE_FMT);
		while (ft_isdigit(**s) == true)
			(*s)++;
		if ((**s) == '-')
			exit_error(scene, DOUBLE_FMT);
	}
}
