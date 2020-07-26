/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/27 00:09:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Retrieve numeric values for parsing
**
** get_integer() :  Retrieves an integer
** get_double()  :  Retrieves a double
** get_rgb_val() :  Retrieves a RGB value: int comprised in the range (0, 255)
** get_color()   :  Retrieves a color: RGB values
** get_point3()  :  Retrieves a 3D coordinates: 3 double values
*/

int				get_integer(t_scene *scene, char **input)
{
	int			result;

	skip_blank(input);
	if ((**input) == '-' || ft_isdigit(**input) == true)
	{
		result = ft_atoi(*input);
		skip_separator(input, '-');
		skip_digits(input);
	}
	else
		exit_error(scene, NUM_FMT);
	return (result);
}

double			get_double(t_scene *scene, char **input)
{
	double		result;
	char		*endptr;

	endptr = NULL;
	skip_blank(input);
	if (**input == '-' || ft_isdigit(**input) == true)
	{
		result = ft_strtod(*input, &endptr);
		free(endptr);
		skip_double(scene, input);
	}
	else
		exit_error(scene, DOUBLE_FMT);
	return (result);
}

static int		get_rgb_val(t_scene *scene, char **input)
{
	int			result;

	if (ft_isdigit(**input) == false)
		exit_error(scene, COLOR_FMT);
	else if (ft_isdigit(**input) == true)
	{
		result = get_integer(scene, input);
		if (ft_n_range(result, 0, 255) == false)
			exit_error(scene, COLOR_FMT);
		skip_digits(input);
	}
	return (result);
}

t_color			get_color(t_scene *scene, char **input)
{
	t_color		result;

	skip_blank(input);
	result.r = get_rgb_val(scene, input);
	if (!(skip_separator(input, ',')))
		exit_error(scene, COLOR_FMT);
	result.g = get_rgb_val(scene, input);
	if (!(skip_separator(input, ',')))
		exit_error(scene, COLOR_FMT);
	result.b = get_rgb_val(scene, input);
	return (result);
}

t_point3		get_point3(t_scene *scene, char **input)
{
	t_point3	result;

	skip_blank(input);
	result.x = get_double(scene, input);
	if (!(skip_separator(input, ',')))
		exit_error(scene, COORD_FMT);
	result.y = get_double(scene, input);
	if (!(skip_separator(input, ',')))
		exit_error(scene, COORD_FMT);
	result.z = get_double(scene, input);
	return (result);
}
