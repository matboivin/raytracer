/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2021/03/29 19:05:30 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "minirt.h"

/*
** This function prints an error message to standard error
*/

void	print_error(char *err_msg)
{
	ft_dprintf(STDERR_FILENO, "Error\n%s\n", err_msg);
	exit(EXIT_FAILURE);
}

/*
** This function frees allocated memory and exits
*/

int		exit_success(t_minirt *env)
{
	quit_minirt(env);
	ft_printf("EXIT\n");
	exit(EXIT_SUCCESS);
	return (0);
}

/*
** This function frees allocated memory, prints an error message and exits
*/

void	exit_error(t_minirt *env, char *err_msg)
{
	quit_minirt(env);
	print_error(err_msg);
}
