/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 22:54:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/29 17:17:12 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RAY_H
# define MINIRT_RAY_H

/*
** Ray struct
**
** origin: Origin of the ray
** dir: Direction of the ray
** t: Distance travelled by the ray
*/

typedef struct	s_ray
{
	t_vec3		origin;
	t_vec3		dir;
	double		t;
}				t_ray;

t_ray			create_ray(t_vec3 p_origin, t_vec3 p_dir, double p_t);

#endif
