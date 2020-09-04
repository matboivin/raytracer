/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_render.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:25 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/04 17:08:08 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RENDER_H
# define MINIRT_RENDER_H

void		render(t_minirt *env, bool to_bmp);

void		look_at(t_cam *cam);
t_mat3x3	rotate_cam(t_vec3 dir);
void		set_ray_origin(t_ray *ray, t_vec3 cam_pos);
void		set_ray_dir(t_cam *cam, t_ray *ray, t_vec3 pixel_coord);
t_vec3		get_pixel_coord(double fov, t_res res, int x, int y);

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
t_vec3		get_quad_coef(t_vec3 dir, t_vec3 oc, double radius);
bool		get_quad_roots(double *root1, double *root2, t_vec3 quad_coef);

t_vec3		get_hit_point(t_vec3 origin, double t, t_vec3 dir);
t_vcolor	get_obj_color(t_lstobj *hit_obj);
double		get_specular(
	t_ray *ray, t_light *light, t_vec3 light_dir, double angle);

void		put_pixel_to_image(t_img *img, t_vcolor vcolor, int x, int y);

#endif
