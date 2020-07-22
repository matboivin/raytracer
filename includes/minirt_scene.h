/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:25:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/23 00:11:36 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_SCENE_H
# define MINIRT_SCENE_H

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

typedef struct	s_cam
{
	t_coord3	pos;
	t_coord3	rot;
	double		fov;
}				t_cam;

typedef struct	s_scene
{
	t_res		res;
	t_amb		amb;
	t_cam		cam;
}				t_scene;

void			create_resolution(t_res *res);
void			create_ambient(t_amb *amb);
void			create_cam(t_cam *cam);
void			create_scene(t_scene *scene);
void			destroy_scene(t_scene *to_destroy);

#endif