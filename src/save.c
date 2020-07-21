/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:16:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/21 14:04:53 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bmp_h		create_bmpfileheader(t_scene *scene)
{
	t_bmp_h	result;
	int		image_size;

	(void)scene;
	// TODO: replace by scene window x and y
	image_size = RENDER_X * RENDER_Y;
	ft_bzero(&result, sizeof(t_bmp_h));
	result.bmp_type[0] = 'B';
	result.bmp_type[1] = 'M';
	result.file_size = 54 + (3 * image_size);
	result.reserved1 = 0;
	result.reserved2 = 0;
	result.offset = 54;
	return (result);
}

void		write_bmpfileheader(t_scene *scene, int fd)
{
	t_bmp_h	header;

	header = create_bmpfileheader(scene);
	write(fd, &header.bmp_type, 2);
	write(fd, &header.file_size, 4);
	write(fd, &header.reserved1, 2);
	write(fd, &header.reserved2, 2);
	write(fd, &header.offset, 4);
}

t_dib_h		create_bmpdibheader(t_scene *scene)
{
	t_dib_h	result;
	int		ppm;

	(void)scene;
	ppm = 72 * 39.375;
	ft_bzero(&result, sizeof(t_dib_h));
	result.size_header = sizeof(t_dib_h);
	// TODO: replace by scene window x and y
	result.width = RENDER_X;
	result.height = RENDER_Y;
	result.planes = 1;
	result.bit_count = 24;
	result.compr = 0;
	result.img_size = result.width * result.height;
	result.ppm_x = ppm;
	result.ppm_y = ppm;
	result.clr_used = 0;
	result.clr_important = 0;
	return (result);
}

void		write_bmpdibheader(t_scene *scene, int fd)
{
	t_dib_h	header;

	header = create_bmpdibheader(scene);
	write(fd, &header.size_header, 4);
	write(fd, &header.width, 4);
	write(fd, &header.height, 4);
	write(fd, &header.planes, 2);
	write(fd, &header.bit_count, 2);
	write(fd, &header.compr, 4);
	write(fd, &header.img_size, 4);
	write(fd, &header.ppm_x, 4);
	write(fd, &header.ppm_y, 4);
	write(fd, &header.clr_used, 4);
	write(fd, &header.clr_important, 4);
}

void		write_bmpdata(t_scene *scene, int fd)
{
	int		y;
	int		x;
	int		pixel;

	y = 0;
	// TODO: Replace by actual value
	pixel = 600;
	while (y < g_app->win_y)
	{
		x = 0;
		while (x < g_app->win_x)
		{
			if (write(fd, &pixel, 3) < 0)
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
	write_bmpfileheader(scene, fd);
	write_bmpdibheader(scene, fd);
	write_bmpdata(scene, fd);
	close(fd);
	ft_dprintf(STDOUT_FILENO, "Rendered image save in bmp format.\n");
	exit_success(scene);
}
