/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_transform.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:25:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/04 23:41:41 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TRANSFORM_H
# define MINIRT_TRANSFORM_H

t_mat4x4	create_camtoworld(t_vec3 from, t_vec3 to, t_vec3 world_up);
t_mat4x4	look_at(t_cam *cam);

void		cam_rotation_x(t_mat4x4 *mat, double x);
void		cam_rotation_y(t_mat4x4 *mat, double y);
void		cam_rotation_z(t_mat4x4 *mat, double z);
t_mat4x4	rotate_cam(t_vec3 dir);

double		degrees_to_radians(double deg_angle);
double		radians_to_degrees(double rad_angle);

#endif
