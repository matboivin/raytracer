/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:25:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/20 16:59:09 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_SCENE_H
# define MINIRT_SCENE_H

typedef struct	s_res
{
	bool		is_declared;
	int			size_x;
	int			size_y;
}				t_res;

typedef struct	s_scene
{
	t_res		res;
}				t_scene;

void			create_resolution(t_res *res);
void			create_scene(t_scene *scene);
void			destroy_scene(t_scene *to_destroy);

#endif