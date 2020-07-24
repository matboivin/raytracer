/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/24 21:02:12 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Utils for parsing
**
** ft_coord3_range()  :  Checks if coordinate values are in a given range
** skip_whitespaces() :  Skips whitespaces
** skip_separator()   :  Skips a given separator (expected: , . -)
** skip_digits()      :  Skips digits
** skip_double()      :  Skips double number
*/

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
