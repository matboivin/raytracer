/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:49:09 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/29 20:12:32 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DEFINE_H
# define MINIRT_DEFINE_H

/*
** Default window title
*/

# define WIN_TITLE "miniRT"

typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;

/*
** Event masks
*/

/*
** 42 Norm doesn't allow the following:
** # define KEYPRESSMASK (1L << 0)
** # define KEYRELEASEMASK (1L << 1)
** # define DESTROYNOTIFYMASK (1L << 17)
*/

typedef enum	e_emask
{
	KEYPRESSMASK = 1L << 0,
	KEYRELEASEMASK = 1L << 1,
	DESTROYNOTIFYMASK = 1L << 17
}				t_emask;

/*
** Event types
*/

# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define ENTERNOTIFY 7
# define LEAVENOTIFY 8
# define FOCUSIN 9
# define FOCUSOUT 10
# define KEYMAPNOTIFY 11
# define EXPOSE 12
# define GRAPHICSSEXPOSE 13
# define NOEXPOSE 14
# define VISIBILITYNOTIFY 15
# define CREATENOTIFY 16
# define DESTROYNOTIFY 17
# define UNMAPNOTIFY 18
# define MAPNOTIFY 19
# define MAPREQUEST 20
# define REPARENTNOTIFY 21
# define CONFIGURENOTIFY 22
# define CONFIGUREREQUEST 23
# define GRAVITYNOTIFY 24

/*
** Keys
*/

# define ESC_KEY 65307
# define SPC_KEY 32

#endif
