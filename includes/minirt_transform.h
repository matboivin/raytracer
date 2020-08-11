/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_transform.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:25:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/12 00:05:00 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TRANSFORM_H
# define MINIRT_TRANSFORM_H

t_mat4x4	create_worldtocam(t_vec3 from, t_vec3 cam_dir, t_vec3 world_up);
t_mat4x4	create_camtoworld4(t_vec3 from, t_vec3 cam_dir, t_vec3 world_up);
t_mat3x3	create_camtoworld3(t_mat4x4 mat);
t_mat4x4	look_at(t_cam *cam);

#endif
