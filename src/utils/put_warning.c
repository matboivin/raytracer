/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_warning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/16 18:04:53 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function warns the user if the resolution is too low
*/

void	put_warn_res(void)
{
	ft_printf("WARNING\nLow resolution: ");
	ft_printf("A minimum size of 400x400 is recommended.\n\n");
}
