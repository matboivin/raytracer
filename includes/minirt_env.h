/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_env.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:47:22 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/07 21:33:25 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ENV_H
# define MINIRT_ENV_H

/*
** Global render settings: Resolution and Ambient light
*/

/*
** Resolution
**
** is_declared: Checks whether Resolution is declared and not duplicated
**              (Default: false)
** size_x: Width of the image
** size_y: Height of the image
*/

typedef struct		s_res
{
	bool			is_declared;
	int				size_x;
	int				size_y;
}					t_res;

/*
** Ambient light
**
** is_declared: Checks whether Ambient light is declared and not duplicated
**              (Default: false)
** ratio: Ambient lighting ratio in range [0.0,1.0]
** vcolor: R,G,B colors in range [0.0,1.0]
*/

typedef struct		s_amb
{
	bool			is_declared;
	double			ratio;
	t_vcolor		vcolor;
}					t_amb;

/*
** Camera
**
** pos: x,y,z coordinates of the light point
** dir: 3D-normalized orientation vector in range [-1,1] for each x,y,z axis
** fov: Horizontal field of view in degrees in range [0,180]
** cam_to_world: Camera Space to World Space 3D matrix
** next: Pointer to next camera
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
** Point light
**
** pos: x,y,z coordinates of the view point
** ratio: Light brightness ratio in range [0.0,1.0]
** vcolor: R,G,B colors in range [0.0,1.0]
** next: Pointer to next light
*/

typedef struct		s_light
{
	t_vec3			pos;
	double			ratio;
	t_vcolor		vcolor;
	struct s_light	*next;
}					t_light;

/*
** Image
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

/*
** Global render settings
*/

void				create_resolution(t_res *res);
void				create_ambient(t_amb *ambient);

/*
** Camera
*/

t_camera			*malloc_cam(t_minirt *env);
void				append_camera(t_camera **cams, t_camera *new_cam);
void				delete_cameras(t_camera **cams);

/*
** Point light
*/

t_light				*malloc_light(t_minirt *en);
void				append_light(t_light **lights, t_light *new_light);
void				delete_lights(t_light **lights);

/*
** Image
*/

t_image				create_image(t_minirt *env);
t_image				*malloc_image(t_minirt *env);
void				destroy_image(void *mlx_ptr, t_image to_destroy);
void				free_image(void *mlx_ptr, t_image *to_free);
void				append_image(t_image **imgs, t_image *new_img);
void				delete_images(void *mlx_ptr, t_image **imgs);
void				create_circular_lstimg(t_image *imgs);

/*
** miniRT controler
*/

void				init_minirt(t_minirt *env, char *title);
void				quit_minirt(t_minirt *env);

#endif
