/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/23 00:08:11 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		skip_whitespaces(char **s)
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

void		skip_integer(char **s)
{
	skip_separator(s, '-');
	while (ft_isdigit(**s) == true)
		(*s)++;
}

void		skip_double(t_scene *scene, char **s)
{
	skip_integer(s);
	if (!(skip_separator(s, '.')))
		return ;
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

static int	get_rgb_val(t_scene *scene, char **input)
{
	int		result;

	if (ft_isdigit(**input) == true)
	{
		result = get_integer(scene, input);
		if (ft_n_range(result, 0, 255) == false)
			exit_error(scene, SCENE_FMT);
		skip_integer(input);
	}
	else
		exit_error(scene, SCENE_FMT);
	return (result);
}

t_color		get_color(t_scene *scene, char **input)
{
	t_color	result;

	skip_whitespaces(input);
	result.r = get_rgb_val(scene, input);
	if (!(skip_separator(input, ',')))
		exit_error(scene, SCENE_FMT);
	result.g = get_rgb_val(scene, input);
	if (!(skip_separator(input, ',')))
		exit_error(scene, SCENE_FMT);
	result.b = get_integer(scene, input);
	return (result);
}

bool		coord3_in_range(t_coord3 coord, double start, double end)
{
	if (
		ft_f_range(coord.x, start, end) == false
		|| ft_f_range(coord.y, start, end) == false
		|| ft_f_range(coord.z, start, end) == false
	)
		return (false);
	return (true);
}

t_coord3	get_coord3(t_scene *scene, char **input)
{
	t_coord3	result;

	skip_whitespaces(input);
	result.x = get_double(scene, input);
	if (!(skip_separator(input, ',')))
		exit_error(scene, SCENE_FMT);
	result.y = get_double(scene, input);
	if (!(skip_separator(input, ',')))
		exit_error(scene, SCENE_FMT);
	result.z = get_double(scene, input);
	return (result);
}
