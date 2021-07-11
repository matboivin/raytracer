/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:51:48 by mboivin           #+#    #+#             */
/*   Updated: 2021/07/11 16:27:22 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	append_image(t_image **imgs, t_image *new_img)
{
	t_image	*cursor = NULL;

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

void	delete_images(void *mlx_ptr, t_image **imgs)
{
	t_image	*cursor = NULL;
	t_image	*head = NULL;

	if (!imgs)
		return ;
	if (*imgs)
	{
		head = *imgs;
		while (*imgs)
		{
			cursor = *imgs;
			*imgs = (*imgs)->next;
			free_image(mlx_ptr, cursor);
			if (*imgs == head)
				*imgs = NULL;
		}
	}
}

void	create_circular_img_list(t_image *imgs)
{
	t_image	*head = NULL;

	head = imgs;
	while (imgs->next)
		imgs = imgs->next;
	imgs->next = head;
	imgs = imgs->next;
}
