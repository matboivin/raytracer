/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/22 21:29:35 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		skip_whitespaces(char **s)
{
	while (ft_isspace(**s) == true)
		(*s)++;
}

void		skip_integer(char **s)
{
	if ((**s) == '-')
			(*s)++;
	while (ft_isdigit(**s) == true)
		(*s)++;
}

void		skip_double(t_scene *scene, char **s)
{
	skip_integer(s);
	if ((**s) != '.')
		return ;
	(*s)++;
	if (ft_isdigit(**s) == false)
		exit_error(scene, SCENE_FMT);
	while (ft_isdigit(**s) == true)
		(*s)++;
}

int			get_integer(t_scene *scene, char **input)
{
	int		result;

	skip_whitespaces(input);
	if ((**input) == '-' || ft_isdigit(**input) == true)
	{
		result = ft_atoi(*input);
		skip_integer(input);
	}
	else
		exit_error(scene, SCENE_FMT);
	return (result);
}

double		get_double(t_scene *scene, char **input)
{
	double	result;
	char	*endptr;

	endptr = NULL;
	skip_whitespaces(input);
	if (**input == '-' || ft_isdigit(**input) == true)
	{
		result = ft_strtod(*input, &endptr);
		free(endptr);
		skip_double(scene, input);
	}
	else
		exit_error(scene, SCENE_FMT);
	return (result);
}

t_color		get_color(t_scene *scene, char **input)
{
	t_color	result;

	skip_whitespaces(input);
	if ((ft_isdigit(**input) == true))
	{
		result.r = get_integer(scene, input);
		skip_integer(input);
		if ((**input) != '.')
			(*input)++;
		result.g = get_integer(scene, input);
		skip_integer(input);
		if ((**input) != '.')
			(*input)++;
		result.b = get_integer(scene, input);
		skip_integer(input);
	}
	else
		exit_error(scene, SCENE_FMT);
	return (result);
}
