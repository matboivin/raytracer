/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:25:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/13 21:47:15 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_SCENE_H
# define MINIRT_SCENE_H

# include "minirt_camera.h"
# include "minirt_light.h"
# include "minirt_objects.h"

typedef struct	s_res
{
	bool		is_declared;
	int			size_x;
	int			size_y;
}				t_res;

typedef struct	s_amb
{
	bool		is_declared;
	double		ratio;
	t_color		color;
}				t_amb;

typedef struct	s_scene
{
	t_res		res;
	t_amb		amb;
	t_lstcam	*cameras;
	t_cam		*main_cam;
	t_lstlight	*lights;
	t_lstobj	*objs;
	double		aspect_ratio;
}				t_scene;

void			create_resolution(t_res *res);
void			create_ambient(t_amb *amb);
void			create_scene(t_scene *scene);
void			destroy_scene(t_scene *to_destroy);

t_plane			*create_plane(
	t_scene *scene, t_vec3 p_pos, t_vec3 p_rot, t_color p_color);

#endif
