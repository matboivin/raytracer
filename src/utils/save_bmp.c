/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:16:21 by mboivin           #+#    #+#             */
/*   Updated: 2021/05/20 15:15:09 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft_mem.h"
#include "libft_printf.h"
#include "minirt.h"

/*
** This function fills the file header structure
*/

static void	create_bmpfileheader(t_bmp_h *header, int size)
{
	ft_bzero(header, sizeof(t_bmp_h));
	header->bmp_type[0] = 'B';
	header->bmp_type[1] = 'M';
	header->file_size = HEADER_BYTES + size;
	header->reserved1 = UNUSED;
	header->reserved2 = UNUSED;
	header->offset = HEADER_BYTES;
}

/*
** This function fills the DIB header structure
*/

static void	create_bmpdibheader(t_minirt *env, t_dib_h *header, int size)
{
	int		ppm;

	ppm = DEFAULT_DPI * PPM_CONV_FACTOR;
	ft_bzero(header, sizeof(t_dib_h));
	header->size_header = sizeof(t_dib_h);
	header->width = env->res.size_x;
	header->height = env->res.size_y;
	header->planes = DEFAULT_BIPLANES;
	header->bit_count = TRUE_COLOR;
	header->compr = UNUSED;
	header->img_size = HEADER_BYTES + size;
	header->ppm_x = ppm;
	header->ppm_y = ppm;
	header->clr_used = UNUSED;
	header->clr_important = UNUSED;
}

/*
** This function writes headers to the file
*/

static void	write_bmpheaders(t_minirt *env, int fd)
{
	t_bmp_h	file_header;
	t_dib_h	dib_header;
	int		size;

	size = env->res.size_x * env->res.size_y * RGB_LEN;
	create_bmpfileheader(&file_header, size);
	create_bmpdibheader(env, &dib_header, size);
	write(fd, &(file_header.bmp_type), 2);
	write(fd, &(file_header.file_size), 4);
	write(fd, &(file_header.reserved1), 2);
	write(fd, &(file_header.reserved2), 2);
	write(fd, &(file_header.offset), 4);
	write(fd, &(dib_header.size_header), 4);
	write(fd, &(dib_header.width), 4);
	write(fd, &(dib_header.height), 4);
	write(fd, &(dib_header.planes), 2);
	write(fd, &(dib_header.bit_count), 2);
	write(fd, &(dib_header.compr), 4);
	write(fd, &(dib_header.img_size), 4);
	write(fd, &(dib_header.ppm_x), 4);
	write(fd, &(dib_header.ppm_y), 4);
	write(fd, &(dib_header.clr_used), 4);
	write(fd, &(dib_header.clr_important), 4);
}

/*
** This function writes pixels to the file
*/

static void	write_bmpdata(t_minirt *env, int fd)
{
	int		x, y;
	int		*pixel = NULL;
	int		i;
	int		progress;

	y = env->res.size_y - 1;
	while (y > -1)
	{
		x = 0;
		while (x < env->res.size_x)
		{
			i = (x + env->res.size_x * y) * PIXEL_LEN;
			pixel = (int *)(env->imgs->pixels + i);
			if (write(fd, pixel, RGB_LEN) < 0)
				exit_error(env, (char *)strerror(errno));
			x++;
		}
		progress = ft_percent((env->res.size_y - y), env->res.size_y);
		ft_printf("\rSaving rendered image in BMP format... %d%%", progress);
		y--;
	}
	ft_printf("\nImage saved as 'minirt.bmp' in working dir.\n");
}

/*
** This function carries out file saving to BMP format
*/

void		save_bmp(t_minirt *env, const char *filename)
{
	int		fd = 0;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMISSIONS);
	if (!fd)
		exit_error(env, (char *)strerror(errno));
	write_bmpheaders(env, fd);
	write_bmpdata(env, fd);
	close(fd);
	exit_success(env);
}
