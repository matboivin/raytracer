/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:16:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/21 21:52:52 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bmp_h		create_bmpfileheader(int size)
{
	t_bmp_h	result;

	ft_bzero(&result, sizeof(t_bmp_h));
	result.bmp_type[0] = 'B';
	result.bmp_type[1] = 'M';
	result.file_size = 54 + size;
	result.reserved1 = 0;
	result.reserved2 = 0;
	result.offset = 54;
	return (result);
}

t_dib_h		create_bmpdibheader(int size)
{
	t_dib_h	result;
	int		ppm;

	ppm = 96 * 39.375;
	ft_bzero(&result, sizeof(t_dib_h));
	result.size_header = sizeof(t_dib_h);
	result.width = g_app->win_x;
	result.height = g_app->win_y;
	result.planes = 1;
	result.bit_count = 24;
	result.compr = 0;
	result.img_size = 54 + size;
	result.ppm_x = ppm;
	result.ppm_y = ppm;
	result.clr_used = 0;
	result.clr_important = 0;
	return (result);
}

void		write_bmpheaders(int fd)
{
	int		size;
	t_bmp_h	file_header;
	t_dib_h	dib_header;

	size = g_app->win_x * g_app->win_y * 3;
	file_header = create_bmpfileheader(size);
	dib_header = create_bmpdibheader(size);
	write(fd, &file_header.bmp_type, 2);
	write(fd, &file_header.file_size, 4);
	write(fd, &file_header.reserved1, 2);
	write(fd, &file_header.reserved2, 2);
	write(fd, &file_header.offset, 4);
	write(fd, &dib_header.size_header, 4);
	write(fd, &dib_header.width, 4);
	write(fd, &dib_header.height, 4);
	write(fd, &dib_header.planes, 2);
	write(fd, &dib_header.bit_count, 2);
	write(fd, &dib_header.compr, 4);
	write(fd, &dib_header.img_size, 4);
	write(fd, &dib_header.ppm_x, 4);
	write(fd, &dib_header.ppm_y, 4);
	write(fd, &dib_header.clr_used, 4);
	write(fd, &dib_header.clr_important, 4);
}

void		write_bmpdata(t_scene *scene, int fd)
{
	int		x;
	int		y;
	int		*pixel;
	int		i;

	y = 0;
	while (y < g_app->win_y)
	{
		x = 0;
		while (x < g_app->win_x)
		{
			i = (4 * g_app->win_x * (g_app->win_y - 1 - y)) + (4 * x);
			pixel = (int *)(g_app->img->img_data + i);
			if (write(fd, pixel, 3) < 0)
				exit_error(scene, DEFAULT);
			x++;
		}
		y++;
	}
}

void		save_bmp(t_scene *scene, const char *filename)
{
	int		fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		exit_error(scene, DEFAULT);
	write_bmpheaders(fd);
	write_bmpdata(scene, fd);
	close(fd);
	ft_dprintf(STDOUT_FILENO, "Rendered image save in bmp format.\n");
	exit_success(scene);
}
