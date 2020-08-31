/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/31 22:26:52 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Struct: Element identifiers associated to parsing functions
*/

static t_parsers	g_parsers[] =
{
	{ "R ", &get_resolution },
	{ "A ", &get_ambient },
	{ "c ", &get_camera },
	{ "l ", &get_light },
	{ "R\t", &get_resolution },
	{ "A\t", &get_ambient },
	{ "c\t", &get_camera },
	{ "l\t", &get_light },
	{ "sp", &get_sphere },
	{ "pl", &get_plane },
	{ "sq", &get_square },
	{ "cy", &get_cylinder },
	{ "tr", &get_triangle }
};

/*
** This function calls the appropriate function to parse a line
*/

static void		handle_scene_elem(t_minirt *env, char **input)
{
	int			i;

	i = 0;
	while (i < MAX_PARS)
	{
		if (ft_strncmp(g_parsers[i].u_id, *input, 2) == 0)
		{
			(*g_parsers[i].func)(env, input);
			return ;
		}
		i++;
	}
	exit_error(env, ID_ERR);
}

/*
** This function gets the entire scene description
*/

static char		*read_scene_file(t_minirt *env, const char *filepath)
{
	char		*result;
	char		buffer[BUFFER_SIZE + 1];
	int			fd;
	int			bytes_read;

	result = NULL;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		exit_error(env, DEFAULT_ERR);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		result = ft_strjoindelone(result, buffer);
		if (result == NULL)
			exit_error(env, DEFAULT_ERR);
	}
	close(fd);
	return (result);
}

/*
** This function checks whether the scene description is valid
*/

static void		check_scene(t_minirt *env)
{
	if (env->res.is_declared == false)
		exit_error(env, NO_RES);
	if (env->ambient.is_declared == false)
		exit_error(env, NO_AMB);
	if (env->cams == NULL)
		exit_error(env, NO_CAM);
	if (env->lights == NULL)
		exit_error(env, NO_LIGHT);
	if (env->objs == NULL)
		exit_error(env, NO_OBJ);
}

/*
** This function iterates over the input to call functions
*/

void			parse_scene(t_minirt *env, const char *filepath)
{
	const char	*ids = "RAclspt";
	char		*input;
	char		*head;

	input = read_scene_file(env, filepath);
	if (input == NULL)
		exit_error(env, DEFAULT_ERR);
	head = input;
	while (*input)
	{
		if (*input == '\n')
			input++;
		else if (ft_ischarset(*input, ids) == true)
			handle_scene_elem(env, &input);
		else
			exit_error(env, SCENE_FMT);
	}
	ft_strdel(&head);
	check_scene(env);
	check_max_display(env);
}
