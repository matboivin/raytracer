/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_camera.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:25:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/31 16:25:56 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_CAMERA_H
# define MINIRT_CAMERA_H

typedef struct		s_cam
{
	t_vec3			pos;
	t_vec3			rot;
	double			fov;
	double			viewplane_d;
}					t_cam;

typedef struct		s_lstcam
{
	t_cam			*cam;
	struct s_lstcam	*next;
}					t_lstcam;

t_lstcam			*new_lstcam(t_cam *cam);
void				lstcam_add_back(t_lstcam **lst, t_lstcam *new);
void				lstcam_clear(t_lstcam **lst);

#endif
