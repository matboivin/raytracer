/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_env.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:47:22 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/08 18:02:27 by mboivin          ###   ########.fr       */
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

typedef struct		s_lstimg
{
	t_img			*img;
	struct s_lstimg	*next;
}					t_lstimg;

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

typedef struct		s_minirt
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*title;
	t_lstimg		*imgs;
	t_res			res;
	t_amb			ambient;
	int				cam_count;
	t_lstcam		*cams;
	t_lstlight		*lights;
	t_lstobj		*objs;
}					t_minirt;

t_img				create_image(t_minirt *env);
t_img				*malloc_image(t_minirt *env);
void				destroy_image(void *mlx_ptr, t_img to_destroy);
void				free_image(void *mlx_ptr, t_img *to_free);
t_lstimg			*new_lstimg(t_img *img);
void				lstimg_append(t_lstimg **imgs, t_lstimg *new_img);
void				lstimg_clear(void *mlx_ptr, t_lstimg **imgs);
void				create_circular_lstimg(t_lstimg *imgs);

void				create_ambient(t_amb *ambient);
void				create_resolution(t_res *res);

void				init_minirt(t_minirt *env, char *title);
void				quit_minirt(t_minirt *env);
int					run_loop(t_minirt *env);

#endif
