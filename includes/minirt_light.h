/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_light.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:25:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/06 23:27:56 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_LIGHT_H
# define MINIRT_LIGHT_H

/*
** Point lights
*/

typedef struct		s_light
{
	t_vec3			pos;
	double			ratio;
	t_vcolor		vcolor;
}					t_light;

typedef struct		s_lights
{
	t_light			*light;
	struct s_lights	*next;
}					t_lights;

t_lights			*create_light(t_light *light);
void				append_light(t_lights **lights, t_lights *new_light);
void				delete_lights(t_lights **lights);

#endif
