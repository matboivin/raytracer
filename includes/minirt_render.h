/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_render.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:25 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/30 20:35:29 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RENDER_H
# define MINIRT_RENDER_H

void		render(t_minirt *env, bool to_bmp);

void		look_at(t_cam *cam);
void		set_ray_origin(t_ray *ray, t_vec3 cam_pos);
void		set_ray_dir(t_minirt *env, t_ray *ray, int x, int y);

void		trace_ray(t_minirt *env, t_cam *cam, t_img *img);
t_lstobj	*trace_ray_to_objs(t_lstobj *objs, t_ray *ray);
void		trace_ray_to_lights(t_minirt *env, t_ray *ray);

bool		hit(t_lstobj *objs, t_ray *ray);
bool		hit_sphere(t_sphere *sphere, t_ray *ray);
bool		hit_obj_plane(t_vec3 pos, t_vec3 dir, t_ray *ray, double *t);
bool		hit_plane(t_plane *plane, t_ray *ray);
bool		hit_square(t_square *square, t_ray *ray);
bool		hit_cylinder(t_cyl *cylinder, t_ray *ray);
bool		hit_triangle(t_tri *triangle, t_ray *ray);
t_vec3		get_quad_coef(t_vec3 a, t_vec3 b, double radius);
bool		get_quad_roots(double *root1, double *root2, t_vec3 quad_coef);

t_vec3		get_hit_point(t_vec3 origin, double t, t_vec3 dir);
t_vcolor	get_obj_color(t_lstobj *hit_obj);

void		put_pixel_to_image(t_img *img, t_vcolor vcolor, int x, int y);

#endif
