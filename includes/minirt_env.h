/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_env.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:47:22 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/07 20:56:06 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ENV_H
# define MINIRT_ENV_H

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
** Image struct
**
** size_x: Width of the image
** size_y: Height of the image
** img_ptr: Pointer returned by the mlx_new_image() function
** pixels: Pointer to image data returned by the mlx_get_data_addr() function
** The 3 following values are obtained using mlx_get_data_addr():
** bpp: Bits per pixels
** size_line: The size (char) of a line
** endian: Endian
** next: Pointer to next image
*/

typedef struct		s_image
{
	int				size_x;
	int				size_y;
	void			*img_ptr;
	char			*pixels;
	int				bpp;
	int				size_line;
	int				endian;
	struct s_image	*next;
}					t_image;

/*
** Cameras
*/

typedef struct		s_camera
{
	t_vec3			pos;
	t_vec3			dir;
	double			fov;
	t_mat3x3		cam_to_world;
	struct s_camera	*next;
}					t_camera;

/*
** Point lights
*/

typedef struct		s_light
{
	t_vec3			pos;
	double			ratio;
	t_vcolor		vcolor;
	struct s_light	*next;
}					t_light;

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
	t_image			*imgs;
	t_res			res;
	t_amb			ambient;
	int				cam_count;
	t_camera		*cams;
	t_light			*lights;
	t_lstobj		*objs;
}					t_minirt;

void				create_ambient(t_amb *ambient);
void				create_resolution(t_res *res);

t_image				create_image(t_minirt *env);
t_image				*malloc_image(t_minirt *env);
void				destroy_image(void *mlx_ptr, t_image to_destroy);
void				free_image(void *mlx_ptr, t_image *to_free);
void				append_image(t_image **imgs, t_image *new_img);
void				delete_images(void *mlx_ptr, t_image **imgs);
void				create_circular_lstimg(t_image *imgs);

t_camera			*malloc_cam(t_minirt *env);
void				append_camera(t_camera **cams, t_camera *new_cam);
void				delete_cameras(t_camera **cams);

t_light				*malloc_light(t_minirt *en);
void				append_light(t_light **lights, t_light *new_light);
void				delete_lights(t_light **lights);

void				init_minirt(t_minirt *env, char *title);
void				quit_minirt(t_minirt *env);

#endif
