/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/22 18:23:47 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function displays the image and dispatches events
*/

void	display_render(t_scene *scene)
{
	open_window();
	put_image_to_window();
	dispatch_event(scene);
}
