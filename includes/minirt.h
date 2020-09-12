/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:47:22 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/13 00:29:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <errno.h>
# include <limits.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft.h"
# include "mlx.h"
# include "minimath.h"

# include "minirt_define.h"
# include "minirt_ray.h"
# include "minirt_camera.h"
# include "minirt_light.h"
# include "minirt_objects.h"
# include "minirt_env.h"
# include "minirt_events.h"
# include "minirt_render.h"
# include "minirt_math_utils.h"
# include "minirt_parsing.h"
# include "minirt_save.h"
# include "minirt_exit.h"
# include "minirt_debug.h"

#endif
