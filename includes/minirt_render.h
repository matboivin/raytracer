/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_render.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:25 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/14 00:36:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RENDER_H
# define MINIRT_RENDER_H

void		generate_image(t_scene *scene);
void		render(t_scene *scene);

t_mat4x4	create_worldtocam(t_vec3 from, t_vec3 cam_dir, t_vec3 world_up);
t_mat4x4	create_camtoworld4(t_vec3 from, t_vec3 cam_dir, t_vec3 world_up);
t_mat3x3	create_camtoworld3(t_mat4x4 mat);
void		look_at(t_cam *cam);

t_vec3		get_pixel_coord(double fov, t_res res, int x, int y);
void		reset_ray_nearest(t_ray *ray);
void		set_ray_origin(t_ray *ray, t_vec3 cam_pos);
void		set_ray_dir(t_ray *ray, t_scene *scene, int x, int y);
t_color		cast_ray(t_scene *scene, t_ray *ray);

t_lstobj	*trace(t_scene *scene, t_ray *ray);
bool		intersect(t_scene *scene, t_ray *ray);
bool		intersect_sphere(t_sphere *sphere, t_ray *ray);
bool		intersect_plane(t_plane *plane, t_ray *ray);
bool		intersect_square(t_scene *scene, t_square *square, t_ray *ray);
bool		solve_quadratic(t_ray *ray, t_vec3 quad_coef);

t_color		get_obj_color(t_lstobj *hit_obj);
t_color		shading(t_scene *scene, t_ray *ray, t_lstobj *hit_obj);
bool		is_in_shadow(void *obj, t_ray *ray);

#endif
