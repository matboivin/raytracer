/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_events.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:42:25 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/27 00:47:54 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_EVENTS_H
# define MINIRT_EVENTS_H

int		handle_key(int keycode, void *param);
void	dispatch_event(t_minirt *env);

#endif
