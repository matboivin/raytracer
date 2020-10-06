/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/06 12:26:41 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function displays the image and dispatches events
*/

void	display_render(t_minirt *env)
{
	open_window(env);
	put_image_to_window(env);
	dispatch_events(env);
}
