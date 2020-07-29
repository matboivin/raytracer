/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:00:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/29 20:13:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PARSING_H
# define MINIRT_PARSING_H

typedef	void	(*t_pars_func)(t_scene *scene, char **input);

typedef struct	s_pars_tab
{
	char		*u_id;
	t_pars_func	func;
}				t_pars_tab;

char			*read_scene_file(t_scene *scene, const char *filepath);
void			parse_scene(t_scene *scene, const char *filepath);
void			get_resolution(t_scene *scene, char **input);
void			get_ambient(t_scene *scene, char **input);
void			get_cam(t_scene *scene, char **input);
void			get_light(t_scene *scene, char **input);
void			get_sphere(t_scene *scene, char **input);
void			get_plane(t_scene *scene, char **input);
void			get_square(t_scene *scene, char **input);
void			get_cylinder(t_scene *scene, char **input);
void			get_triangle(t_scene *scene, char **input);
int				get_integer(t_scene *scene, char **input);
double			get_double(t_scene *scene, char **input);
t_color			get_color(t_scene *scene, char **input);
t_vec3			get_vec3(t_scene *scene, char **input);
bool			ft_vec3_range(t_vec3 vec, double start, double end);
void			skip_blank(char **s);
int				skip_separator(char **s, int sep);
void			skip_digits(char **s);
void			skip_double(t_scene *scene, char **s);

#endif
