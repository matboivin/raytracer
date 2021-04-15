/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2021/04/15 18:53:51 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_num.h"
#include "libft_ctype.h"
#include "libft_conv.h"
#include "minirt.h"

int				get_integer(t_minirt *env, char **input)
{
	int			result;

	skip_blank(input);
	if ((**input) == '-' || ft_isdigit(**input))
	{
		result = ft_atoi(*input);
		skip_separator(input, '-');
		skip_digits(input);
	}
	else
		exit_error(env, "Invalid scene: Number badly formatted.");
	return (result);
}

double			get_double(t_minirt *env, char **input)
{
	double		result;
	char		*endptr;

	endptr = NULL;
	skip_blank(input);
	if ((**input) == '-' || ft_isdigit(**input))
	{
		result = ft_strtod(*input, &endptr);
		free(endptr);
		skip_double(env, input);
	}
	else
		exit_error(env, "Invalid scene: Floating-point number badly formatted.");
	return (result);
}

static int		get_rgb_val(t_minirt *env, char **input)
{
	int			result;

	if (!ft_isdigit(**input))
		exit_error(env, "Invalid scene: Color badly formatted.");
	else if (ft_isdigit(**input))
	{
		result = get_integer(env, input);
		if (!ft_n_range(result, DEFAULT_VALUE, MAX_RGB))
			exit_error(env, "Invalid scene: Color badly formatted.");
		skip_digits(input);
	}
	return (result);
}

t_vcolor		get_color(t_minirt *env, char **input)
{
	t_vcolor	result;

	skip_blank(input);
	result.x = get_rgb_val(env, input);
	if (!skip_separator(input, COMMA))
		exit_error(env, "Invalid scene: Color badly formatted.");
	result.y = get_rgb_val(env, input);
	if (!skip_separator(input, COMMA))
		exit_error(env, "Invalid scene: Color badly formatted.");
	result.z = get_rgb_val(env, input);
	return (result);
}

t_vec3			get_vec3(t_minirt *env, char **input)
{
	t_vec3		result;

	skip_blank(input);
	result.x = get_double(env, input);
	if (!skip_separator(input, COMMA))
		exit_error(env, "Invalid scene: Coordinates badly formatted.");
	result.y = get_double(env, input);
	if (!skip_separator(input, COMMA))
		exit_error(env, "Invalid scene: Coordinates badly formatted.");
	result.z = get_double(env, input);
	return (result);
}
