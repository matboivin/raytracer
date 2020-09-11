/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/11 23:35:09 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function frees allocated memory and exits
*/

int			exit_success(t_minirt *env)
{
	quit_minirt(env);
	ft_printf("EXIT\n");
	exit(EXIT_SUCCESS);
	return (0);
}

/*
** This function frees allocated memory, prints an error message and exits
*/

void		exit_error(t_minirt *env, t_errid raised)
{
	quit_minirt(env);
	print_error(raised);
}
