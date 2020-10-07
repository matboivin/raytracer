/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_render.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:25 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/07 20:47:07 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RENDER_H
# define MINIRT_RENDER_H

void		render(t_minirt *env, bool to_bmp);

/*
** Set ray
*/

void		look_at(t_camera *cam);
void		set_ray_origin(t_ray *ray, t_vec3 cam_pos);
void		set_ray_dir(t_camera *cam, t_ray *ray, t_vec3 pixel_coord);
t_vec3		get_pixel_coord(double fov, t_res res, int x, int y);

/*
** Intersections
*/

void		trace_ray(t_minirt *env, t_camera *cam, t_image *img);
t_lstobj	*trace_ray_to_objs(t_lstobj *objs, t_ray *ray);
void		trace_ray_to_lights(t_minirt *env, t_ray *ray);
bool		hit(t_lstobj *objs, t_ray *ray, double *t);
bool		hit_sphere(t_sphere *sphere, t_ray *ray, double *t);
bool		hit_obj_plane(t_vec3 pos, t_vec3 dir, t_ray *ray, double *t);
bool		hit_plane(t_plane *plane, t_ray *ray, double *t);
bool		hit_square(t_square *square, t_ray *ray, double *t);
bool		hit_cylinder(t_cyl *cylinder, t_ray *ray, double *t);
bool		hit_triangle(t_tri *triangle, t_ray *ray, double *t);
t_vec3		get_quad_coef(t_vec3 dir, t_vec3 oc, double radius);
bool		get_quad_roots(double *root1, double *root2, t_vec3 quad_coef);
t_vec3		get_hit_point(t_vec3 origin, double t, t_vec3 dir);
void		get_obj_color(t_lstobj *hit_obj, t_ray *ray);
double		get_specular(
	t_ray *ray, t_light *light, t_vec3 light_dir, double angle);

/*
** Put pixel to image
*/

void		put_pixel_to_image(t_image *img, t_vcolor vcolor, int x, int y);
t_vcolor	rescale_color(t_vcolor vcolor, double min, double max);

/*
** Display
*/

void		switch_camera(t_minirt *env);
void		open_window(t_minirt *env);
void		put_image_to_window(t_minirt *env);
int			reload_image(t_minirt *env);
void		display_render(t_minirt *env);

#endif
