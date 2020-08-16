/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_render.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:25 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/16 18:45:58 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RENDER_H
# define MINIRT_RENDER_H

void		generate_image(t_scene *scene);
void		render(t_scene *scene);

void		look_at(t_cam *cam);

void		set_ray_nearest(t_ray *ray);
void		set_ray_origin(t_ray *ray, t_vec3 cam_pos);
void		set_ray_dir(t_ray *ray, t_scene *scene, int x, int y);

t_color		cast_ray(t_scene *scene, t_ray *ray);

t_lstobj	*trace(t_scene *scene, t_ray *ray);

bool		intersect(t_scene *scene, t_ray *ray);
bool		intersect_sphere(t_sphere *sphere, t_ray *ray);
bool		intersect_plane(t_plane *plane, t_ray *ray);
bool		intersect_square(t_scene *scene, t_square *square, t_ray *ray);

bool		solve_quadratic(t_ray *ray, t_vec3 quad_coef);

t_color		shading(t_scene *scene, t_ray *ray, t_lstobj *hit_obj);

void		put_pixel_to_image(t_img *img, t_color color, int x, int y);

#endif
