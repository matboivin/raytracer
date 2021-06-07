/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_exit.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:48:40 by mboivin           #+#    #+#             */
/*   Updated: 2021/03/29 19:05:43 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_EXIT_H
# define MINIRT_EXIT_H

void	check_params(int argc, char **argv, bool *to_bmp);
void	print_error(char *err_msg);
void	exit_error(t_minirt *env, char *err_msg);
int		exit_success(t_minirt *env);

#endif
