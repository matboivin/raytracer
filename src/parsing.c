/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/22 16:36:29 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* 
Double:	0.2
Coord3:	-50.0,0,20	/	0,0,1
Color:	255,255,255
Num:	1920
*/

void		parse_scene(t_scene *scene, const char *filepath)
{
	char	*to_parse;

	to_parse = read_scene_file(scene, filepath);
	free(to_parse);
	// TODO: Check R, A and c not missing, and scene is not in the complete dark
}

/*
** Function: Gets the entire scene
*/

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
		result = ft_strjoindelone(result, line);
		if (result == NULL)
			exit_error(scene, DEFAULT);
		free(line);
	}
	if (ret_value == -1)
		exit_error(scene, DEFAULT);
	close(fd);
	return (result);
}
