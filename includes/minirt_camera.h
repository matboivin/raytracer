/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_camera.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:25:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/06 23:25:22 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_CAMERA_H
# define MINIRT_CAMERA_H

typedef struct			s_cam
{
	t_vec3				pos;
	t_vec3				dir;
	double				fov;
	t_mat3x3			cam_to_world;
}						t_cam;

typedef struct			s_cameras
{
	t_cam				*cam;
	struct s_cameras	*next;
}						t_cameras;

t_cameras				*create_cam(t_cam *cam);
void					append_camera(t_cameras **cams, t_cameras *new_cam);
void					delete_cameras(t_cameras **cams);

#endif
