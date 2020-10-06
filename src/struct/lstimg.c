/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstimg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:51:48 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/06 23:26:51 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_images		*new_image(t_img *img)
{
	t_images	*result;

	result = (t_images *)malloc(sizeof(t_images));
	if (!result)
		return (NULL);
	result->img = img;
	result->next = NULL;
	return (result);
}

void			append_image(t_images **imgs, t_images *new_img)
{
	t_images	*cursor;

	if (!imgs || !new_img)
		return ;
	if (*imgs)
	{
		cursor = *imgs;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = new_img;
	}
	else
		*imgs = new_img;
}

void			delete_images(void *mlx_ptr, t_images **imgs)
{
	t_images	*cursor;
	t_images	*head;

	if (!imgs)
		return ;
	head = *imgs;
	while (*imgs)
	{
		cursor = *imgs;
		*imgs = (*imgs)->next;
		free_image(mlx_ptr, cursor->img);
		free(cursor);
		if (*imgs == head)
			*imgs = NULL;
	}
}

void			create_circular_lstimg(t_images *imgs)
{
	t_images	*head;

	head = imgs;
	while (imgs->next)
		imgs = imgs->next;
	imgs->next = head;
	imgs = imgs->next;
}
