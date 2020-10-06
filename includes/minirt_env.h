/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_env.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:47:22 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/06 23:25:09 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ENV_H
# define MINIRT_ENV_H

/*
** Image struct
**
** size_x: Width of the image
** size_y: Height of the image
** img_ptr: Pointer returned by the mlx_new_image() function
** pixels: Pointer to image data returned by the mlx_get_data_addr() function
** Following values are obtained using mlx_get_data_addr()
** bpp: bits per pixels
** size_line: the size (char) of a line
** endian: endian
*/

typedef struct		s_img
{
	int				size_x;
	int				size_y;
	void			*img_ptr;
	char			*pixels;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_images
{
	t_img			*img;
	struct s_images	*next;
}					t_images;

/*
** Global render settings
*/

typedef struct		s_amb
{
	bool			is_declared;
	double			ratio;
	t_vcolor		vcolor;
}					t_amb;

typedef struct		s_res
{
	bool			is_declared;
	int				size_x;
	int				size_y;
}					t_res;

/*
** miniRT controler
**
** mlx_ptr: Pointer returned by the mlx_init() function
** win_ptr: Pointer to the window
** title: Title of the window
** imgs: Rendered images
** res: Resolution (width and height) of the window
** ambient: Ambient light parameters
** cam_count: Number of cameras in scene
** cams: Cameras in scene
** lights: Point lights in scene
** objs: Objects in scene
** img: Content of the window
*/

typedef struct		s_minirt
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*title;
	t_images		*imgs;
	t_res			res;
	t_amb			ambient;
	int				cam_count;
	t_cameras		*cams;
	t_lights		*lights;
	t_lstobj		*objs;
}					t_minirt;

t_img				create_image(t_minirt *env);
t_img				*malloc_image(t_minirt *env);
void				destroy_image(void *mlx_ptr, t_img to_destroy);
void				free_image(void *mlx_ptr, t_img *to_free);
t_images			*new_image(t_img *img);
void				append_image(t_images **imgs, t_images *new_img);
void				delete_images(void *mlx_ptr, t_images **imgs);
void				create_circular_lstimg(t_images *imgs);

void				create_ambient(t_amb *ambient);
void				create_resolution(t_res *res);

void				init_minirt(t_minirt *env, char *title);
void				quit_minirt(t_minirt *env);

#endif
