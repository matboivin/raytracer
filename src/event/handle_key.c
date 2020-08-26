/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:57:56 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/27 00:47:59 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles keyboard events
*/

int				handle_key(int keycode, void *param)
{
	t_minirt	*env;

	env = (t_minirt *)param;
	if (keycode == ESC_KEY)
		exit_success(env);
	if (keycode == SPC_KEY)
		switch_camera(env);
	return (0);
}
