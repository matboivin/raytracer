/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_math_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 00:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/25 23:20:10 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MATH_UTILS_H
# define MINIRT_MATH_UTILS_H

t_vec3		get_obj_normal(t_vec3 hit_p, t_lstobj *hit_obj, t_ray *ray);
t_vec3		get_sphere_normal(t_vec3 hit_p, t_sphere *sphere);
t_vec3		get_triangle_normal(t_tri *tri);
t_vec3		get_cylinder_normal(t_vec3 hit_p, t_cyl *cylinder);
t_color		rescale_color(t_color color, double max, double min);

#endif
