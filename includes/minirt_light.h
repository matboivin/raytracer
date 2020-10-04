/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_light.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:25:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/04 13:37:30 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_LIGHT_H
# define MINIRT_LIGHT_H

/*
** Point lights
*/

typedef struct			s_light
{
	t_vec3				pos;
	double				ratio;
	t_vcolor			vcolor;
}						t_light;

typedef struct			s_lstlight
{
	t_light				*light;
	struct s_lstlight	*next;
}						t_lstlight;

t_lstlight				*new_lstlight(t_light *light);
void					lstlight_append(
	t_lstlight **lights, t_lstlight *new_light);
void					lstlight_clear(t_lstlight **lights);

#endif
