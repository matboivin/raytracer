/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_render.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:25 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/24 19:44:53 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RENDER_H
# define MINIRT_RENDER_H

void		render(t_scene *scene, bool to_bmp);

void		look_at(t_cam *cam);
void		set_ray_origin(t_ray *ray, t_vec3 cam_pos);
void		set_ray_dir(t_ray *ray, t_scene *scene, int x, int y);

t_color		trace_ray(t_scene *scene, t_ray *ray);

t_vec3		get_hit_point(t_vec3 origin, double t, t_vec3 dir);
bool		intersect(t_lstobj *objs, t_ray *ray);
bool		intersect_sphere(t_sphere *sphere, t_ray *ray);
bool		intersect_obj_plane(t_vec3 pos, t_vec3 dir, t_ray *ray, double *t);
bool		intersect_plane(t_plane *plane, t_ray *ray);
bool		intersect_square(t_square *square, t_ray *ray);
bool		intersect_cylinder(t_cyl *cylinder, t_ray *ray);
bool		intersect_triangle(t_tri *triangle, t_ray *ray);
t_vec3		get_quad_coef(t_vec3 a, t_vec3 b, double radius);
bool		get_quad_roots(double *root1, double *root2, t_vec3 quad_coef);

t_color		get_obj_color(t_lstobj *hit_obj);

void		put_pixel_to_image(t_img *img, t_color color, int x, int y);

#endif
