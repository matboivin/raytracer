/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/07 00:16:51 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Struct: Element identifiers associated to parsing functions
*/

struct s_pars_arr	g_pars_elem[] =
{
	{ "R ", &get_resolution },
	{ "A ", &get_ambient },
	{ "c ", &get_camera },
	{ "l ", &get_light },
	{ "sp", &get_sphere },
	{ "pl", &get_plane },
	{ "sq", &get_square },
	{ "cy", &get_cylinder },
	{ "tr", &get_triangle }
};

/*
** This function calls the appropriate function to parse a line
*/

static void		handle_scene_elem(t_scene *scene, char **input)
{
	int			i;

	i = 0;
	while (i < 9)
	{
		if (ft_strnequ(g_pars_elem[i].u_id, *input, 2))
		{
			(*g_pars_elem[i].func)(scene, input);
			return ;
		}
		i++;
	}
	exit_error(scene, ID_ERR);
}

/*
** This function gets the entire scene description
*/

char			*read_scene_file(t_scene *scene, const char *filepath)
{
	char		*result;
	char		buffer[BUFFER_SIZE + 1];
	int			fd;
	int			bytes_read;

	result = NULL;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		exit_error(scene, DEFAULT_ERR);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		result = ft_strjoindelone(result, buffer);
		if (result == NULL)
			exit_error(scene, DEFAULT_ERR);
	}
	close(fd);
	return (result);
}

/*
** This function iterates over the input to call functions
*/

void			parse_scene(t_scene *scene, const char *filepath)
{
	const char	*ids = "RAclspt";
	char		*input;
	char		*head;

	create_scene(scene);
	input = read_scene_file(scene, filepath);
	if (input == NULL)
		exit_error(scene, DEFAULT_ERR);
	head = input;
	while (*input)
	{
		if (*input == '\n')
			input++;
		else if (ft_ischarset(*input, ids) == true)
			handle_scene_elem(scene, &input);
		else
			exit_error(scene, SCENE_FMT);
	}
	ft_strdel(&head);
	check_scene(scene);
	check_max_display(scene);
	create_circular_lstcam(scene->cameras);
}
