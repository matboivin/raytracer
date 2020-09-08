/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstimg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:51:48 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/08 18:03:57 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_lstimg		*new_lstimg(t_img *img)
{
	t_lstimg	*result;

	result = (t_lstimg *)malloc(sizeof(t_lstimg));
	if (!result)
		return (NULL);
	result->img = img;
	result->next = NULL;
	return (result);
}

void			lstimg_append(t_lstimg **imgs, t_lstimg *new_img)
{
	t_lstimg	*cursor;

	if (!imgs || !new_img)
		return ;
	cursor = *imgs;
	if (*imgs)
	{
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = new_img;
	}
	else
		*imgs = new_img;
}

void			lstimg_clear(void *mlx_ptr, t_lstimg **imgs)
{
	t_lstimg	*cursor;
	t_lstimg	*head;

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

void			create_circular_lstimg(t_lstimg *imgs)
{
	t_lstimg	*head;

	head = imgs;
	while (imgs->next)
		imgs = imgs->next;
	imgs->next = head;
	imgs = imgs->next;
}
