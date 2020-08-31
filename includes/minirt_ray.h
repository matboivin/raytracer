/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 22:54:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/31 22:32:13 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RAY_H
# define MINIRT_RAY_H

/*
** Ray struct
**
** origin: Origin of the ray
** dir: Direction of the ray
** t_nearest: Scaling factor that modifies the distance travelled by the ray
**            Expected default: max double value
**            Keeps track of the nearest distance between the ray origin and the
**            intersection point while we iterate over the objects
*/

typedef struct	s_ray
{
	t_vec3		origin;
	t_vec3		dir;
	double		t_nearest;
	t_vcolor	vcolor;
	t_vec3		hit_p;
	t_vec3		normal;
}				t_ray;

t_ray			create_ray(t_vec3 p_origin, t_vec3 p_dir, double p_tnear);

#endif
