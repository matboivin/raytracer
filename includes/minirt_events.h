/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_events.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:42:25 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/24 18:02:06 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_EVENTS_H
# define MINIRT_EVENTS_H

int		handle_key(int keycode, t_scene *scene);
void	dispatch_event(t_scene *scene);

#endif
