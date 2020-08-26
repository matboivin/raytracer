/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:25:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/26 19:17:04 by mboivin          ###   ########.fr       */
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
	t_vcolor	vcolor;
}				t_amb;

typedef struct	s_scene
{
	t_res		res;
	t_amb		amb;
	int			cam_count;
	t_lstcam	*cameras;
	t_lstlight	*lights;
	t_lstobj	*objs;
}				t_scene;

void			create_resolution(t_res *res);
void			create_ambient(t_amb *amb);
void			create_scene(t_scene *scene);
void			destroy_scene(t_scene *to_destroy);

#endif
