/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_camera.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:25:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/26 22:23:27 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_CAMERA_H
# define MINIRT_CAMERA_H

typedef struct		s_cam
{
	t_vec3			pos;
	t_vec3			dir;
	double			fov;
	t_mat3x3		cam_to_world3;
	t_mat4x4		cam_to_world4;
}					t_cam;

typedef struct		s_lstcam
{
	t_cam			*cam;
	struct s_lstcam	*next;
}					t_lstcam;

t_lstcam			*new_lstcam(t_cam *cam);
void				lstcam_add_back(t_lstcam **cams, t_lstcam *new);
void				lstcam_clear(t_lstcam **cams);

#endif
