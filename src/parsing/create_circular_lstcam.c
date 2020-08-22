/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_circular_lstcam.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/22 18:21:00 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function creates a circular linked list to switch between cameras
*/

void			create_circular_lstcam(t_lstcam *cameras)
{
	t_lstcam	*head;

	head = cameras;
	while (cameras->next)
		cameras = cameras->next;
	cameras->next = head;
}
