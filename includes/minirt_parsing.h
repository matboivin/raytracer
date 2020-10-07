/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:00:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/07 20:47:07 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PARSING_H
# define MINIRT_PARSING_H

typedef	void	(*t_pars_func)(t_minirt *env, char **input);

/*
** Element identifiers associated to parsing functions
*/

typedef struct	s_parsers
{
	char		*u_id;
	int			id_len;
	t_pars_func	func;
}				t_parsers;

void			parse_scene(t_minirt *env, const char *filepath);

/*
** Global render settings
*/

void			get_resolution(t_minirt *env, char **input);
void			get_ambient(t_minirt *env, char **input);

/*
** Camera and light
*/

void			get_cameraera(t_minirt *env, char **input);
void			get_light(t_minirt *env, char **input);

/*
** Objects
*/

void			add_obj_to_scene(t_minirt *env, void *obj, t_objid type);
void			get_sphere(t_minirt *env, char **input);
void			get_plane(t_minirt *env, char **input);
void			get_square(t_minirt *env, char **input);
void			get_cylinder(t_minirt *env, char **input);
void			get_triangle(t_minirt *env, char **input);

/*
** Parsing utils
*/

int				get_integer(t_minirt *env, char **input);
double			get_double(t_minirt *env, char **input);
t_vcolor		get_color(t_minirt *env, char **input);
t_vec3			get_vec3(t_minirt *env, char **input);
bool			ft_vec3_range(t_vec3 vec, double start, double end);
void			skip_blank(char **s);
int				skip_separator(char **s, int sep);
void			skip_digits(char **s);
void			skip_double(t_minirt *env, char **s);
void			check_max_display(t_minirt *env);
void			check_null_vector(t_vec3 *to_check, t_vec3 default_vec);
void			check_null_light(t_vcolor *vcolor, double *ratio);

#endif
