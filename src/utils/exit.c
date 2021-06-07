/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2021/06/07 17:34:20 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "minirt.h"

/*
** This function prints an error message to standard error
*/

void	print_error(char *err_msg)
{
	dprintf(STDERR_FILENO, "Error\n%s\n", err_msg);
	exit(EXIT_FAILURE);
}

/*
** This function frees allocated memory and exits
*/

int		exit_success(t_minirt *env)
{
	quit_minirt(env);
	printf("EXIT\n");
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
