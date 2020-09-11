/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_events.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:49:09 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/12 00:08:00 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_EVENTS_H
# define MINIRT_EVENTS_H

/*
** Keys
*/

# define ESC_KEY 65307
# define SPC_KEY 32

/*
** Event types
*/

# define KEYPRESS 2
# define DESTROYNOTIFY 17
# define MAPNOTIFY 19

/*
** Event masks
** 42 Norm doesn't allow the following:
** # define KEYPRESSMASK (1L << 0)
** # define DESTROYNOTIFYMASK (1L << 17)
*/

typedef enum	e_emask
{
	KEYPRESSMASK = 1L << 0,
	STRUCTURENOTIFYMASK = 1L << 17
}				t_emask;

int				handle_key(int keycode, void *param);
void			dispatch_event(t_minirt *env);

#endif
