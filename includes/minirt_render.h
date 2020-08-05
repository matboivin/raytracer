/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_render.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:25 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/05 22:04:44 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RENDER_H
# define MINIRT_RENDER_H

void		generate_image(t_scene *scene);
void		render(t_scene *scene);

t_vec4		rasterize(t_scene *scene, int x, int y);
t_color		cast_ray(t_scene *scene, t_ray *ray);
void		reset_ray_nearest(t_ray *ray);
void		set_ray_dir(t_ray *ray, t_mat4x4 mat, t_vec4 pixel_coord);
void		set_ray_origin(t_ray *ray, t_mat4x4 mat);

t_lstobj	*trace(t_scene *scene, t_ray *ray);
bool		intersect_sphere(t_sphere *sphere, t_ray *ray, double *t);
bool		intersect(t_lstobj *objs, t_ray *ray, double *t);

t_color		get_obj_color(t_lstobj *hit_obj);
t_color		shading(t_scene *scene, t_ray *ray, t_lstobj *hit_obj);
bool		is_in_shadow(void *obj, t_ray *ray);

#endif
