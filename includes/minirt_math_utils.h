/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_math_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 00:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/27 20:53:53 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MATH_UTILS_H
# define MINIRT_MATH_UTILS_H

void		get_obj_normal(t_lstobj *hit_obj, t_ray *ray, t_vec3 hit_p);
t_vec3		get_sphere_normal(t_sphere *sphere, t_vec3 hit_p);
t_vec3		get_triangle_normal(t_tri *tri);
t_vec3		get_cylinder_normal(t_cyl *cylinder, t_vec3 hit_p);
t_vcolor	rescale_color(t_vcolor vcolor, double max, double min);

#endif
