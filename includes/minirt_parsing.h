/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:00:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/23 00:23:02 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PARSING_H
# define MINIRT_PARSING_H

typedef	void		(*t_parse_func)(t_scene *scene, char **input);

typedef struct		s_parse_tab
{
	char			*u_id;
	t_parse_func	func;
}					t_parse_tab;

char		*read_scene_file(t_scene *scene, const char *filepath);
void		parse_scene(t_scene *scene, const char *filepath);

void		get_resolution(t_scene *scene, char **input);
void		get_ambient(t_scene *scene, char **input);
void		get_cam(t_scene *scene, char **input);

void		skip_whitespaces(char **s);
int			skip_separator(char **s, char sep);
void		skip_integer(char **s);
void		skip_double(t_scene *scene,char **s);
int			get_integer(t_scene *scene, char **input);
double		get_double(t_scene *scene, char **input);
t_color		get_color(t_scene *scene, char **input);
t_coord3	get_coord3(t_scene *scene, char **input);
bool		ft_coord3_range(t_coord3 coord, double start, double end);

#endif
