/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_image.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:52:11 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/21 17:16:23 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_IMAGE_H
# define MINIRT_IMAGE_H

/*
** MLX image struct
**
** size_x: Width of the image
** size_y: Height of the image
** img_ptr: Pointer returned by the mlx_new_image() function
** img_data: Pointer returned by the mlx_get_data_addr() function: image pixels
** Following values are obtained using mlx_get_data_addr()
** bpp: bits per pixels
** size_line: the size (char) of a line
** endian: endian
*/

typedef struct	s_img
{
	int			size_x;
	int			size_y;
	void		*img_ptr;
	char		*img_data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

t_img			create_image(int p_x, int p_y);
t_img			*malloc_image(int p_x, int p_y);
void			destroy_image(t_img to_destroy);
void			free_image(t_img *to_free);

#endif
