/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/23 00:49:55 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Array of structures: pointers to parsing functions matching identifier
*/

struct s_parse_tab	g_parse_tab[] =
{
	{ "R " , &get_resolution },
	{ "A " , &get_ambient },
	{ "c " , &get_cam }
};

static void	call_parsing_func(t_scene *scene, char **input)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (ft_strnequ(g_parse_tab[i].u_id, *input, 2))
		{
			(*g_parse_tab[i].func)(scene, input);
			return ;
		}
		i++;
	}
	exit_error(scene, ID_ERRR);
}

/* 
Double:	0.2
Double:	0

Coord3:	5.0,3.0,2.0
Coord3:	-5.0,3.0,2.0
Coord3:	0,0,1

Color:	255,255,255

Int:	1920
*/

void		parse_scene(t_scene *scene, const char *filepath)
{
	char	*input;
	const char	*ids = "RAc";

	input = read_scene_file(scene, filepath);
	while (*input)
	{
		skip_whitespaces(&input);
		if (ft_ischarset(*input, ids) == true)
			call_parsing_func(scene, &input);
		else
			input++;
			//exit_error(scene, SCENE_FMT);
	}
	resize_window();
	// TODO: Check R, A and c not missing, and scene is not in the complete dark
}

/*
** Function: Gets the entire scene
*/

// TODO: Debug leak

char		*read_scene_file(t_scene *scene, const char *filepath)
{
	int		fd;
	int		ret_value;
	char	*line;
	char	*result;

	ret_value = 1;
	line = NULL;
	result = NULL;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		exit_error(scene, DEFAULT);
	while (ret_value)
	{
		ret_value = get_next_line(fd, &line);
		if (!(result = ft_strjoindelone(result, line)))
			exit_error(scene, DEFAULT);
		free(line);
	}
	if (ret_value == -1)
		exit_error(scene, DEFAULT);
	close(fd);
	return (result);
}
