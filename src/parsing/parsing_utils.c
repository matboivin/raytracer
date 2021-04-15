/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2021/04/15 18:54:05 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_num.h"
#include "libft_ctype.h"
#include "minirt.h"

/*
** This function skips spaces and horizontal tabs
*/

void	skip_blank(char **s)
{
	while (ft_isblank(**s))
		(*s)++;
}

/*
** This function skips a given separator (expected: , . -)
*/

int		skip_separator(char **s, int sep)
{
	if ((**s) == sep)
	{
		(*s)++;
		return (1);
	}
	return (0);
}

/*
** This function skips digits
*/

void	skip_digits(char **s)
{
	while (ft_isdigit(**s))
		(*s)++;
}

/*
** This function skips double number
*/

void	skip_double(t_minirt *env, char **s)
{
	skip_separator(s, '-');
	skip_digits(s);
	if (skip_separator(s, DOT))
	{
		if (!ft_isdigit(**s))
			exit_error(env, "Invalid scene: Floating-point number badly formatted.");
		while (ft_isdigit(**s))
			(*s)++;
		if ((**s) == '-')
			exit_error(env, "Invalid scene: Floating-point number badly formatted.");
	}
}

/*
** This function checks whether vector values are in a given range
*/

bool	ft_vec3_range(t_vec3 vec, double start, double end)
{
	return (
		(ft_f_range(vec.x, start, end))
		&& (ft_f_range(vec.y, start, end))
		&& (ft_f_range(vec.z, start, end)));
}
