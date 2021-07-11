/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2021/07/11 16:28:01 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft_str.h"
#include "minirt.h"

/*
** This function prints an error message to standard error
*/

void	put_err(const char *err_msg)
{
	write(STDERR_FILENO, "Error: ", 7);
	if (err_msg && *err_msg)
		write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
	exit(EXIT_FAILURE);
}

/*
** This function frees allocated memory and exits
*/

int	exit_success(t_minirt *env)
{
	quit_minirt(env);
	write(STDOUT_FILENO, "EXIT\n", 5);
	exit(EXIT_SUCCESS);
	return (0);
}

/*
** This function frees allocated memory, prints an error message and exits
*/

void	exit_error(t_minirt *env, const char *err_msg)
{
	quit_minirt(env);
	put_err(err_msg);
}
