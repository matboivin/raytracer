/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:00:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/16 18:19:37 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PARSING_H
# define MINIRT_PARSING_H

typedef	void	(*t_pars_func)(t_scene *scene, char **input);

typedef struct	s_pars_arr
{
	char		*u_id;
	t_pars_func	func;
}				t_pars_arr;

extern struct s_pars_arr	g_pars_elem[];

/*
** Scene
*/

void			parse_scene(t_scene *scene, const char *filepath);

/*
** Global render settings
*/

void			get_resolution(t_scene *scene, char **input);
void			get_ambient(t_scene *scene, char **input);

/*
** Camera and light
*/

t_cam			*create_camera(t_scene *scene, char **input);
void			get_camera(t_scene *scene, char **input);
void			create_circular_lstcam(t_lstcam *cameras);
t_light			*create_light(t_scene *scene, char **input);
void			get_light(t_scene *scene, char **input);

/*
** Objects
*/

void			add_obj_to_scene(t_scene *scene, void *obj, t_objid type);
void			get_sphere(t_scene *scene, char **input);
void			get_plane(t_scene *scene, char **input);
void			get_square(t_scene *scene, char **input);
void			get_cylinder(t_scene *scene, char **input);
void			get_triangle(t_scene *scene, char **input);

/*
** Parsing utils
*/

int				get_integer(t_scene *scene, char **input);
double			get_double(t_scene *scene, char **input);
t_color			get_color(t_scene *scene, char **input);
t_vec3			get_vec3(t_scene *scene, char **input);
bool			ft_vec3_range(t_vec3 vec, double start, double end);
void			skip_blank(char **s);
int				skip_separator(char **s, int sep);
void			skip_digits(char **s);
void			skip_double(t_scene *scene, char **s);

/*
** Checkers
*/

void			check_max_display(t_scene *scene);
void			check_null_vector(t_vec3 *to_check, t_vec3 default_vec);

#endif
