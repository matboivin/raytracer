/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:47:22 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/24 18:54:53 by mboivin          ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "libft.h"
# include "mlx.h"
# include "minimath.h"

# include "minirt_define.h"
# include "minirt_color.h"
# include "minirt_ray.h"
# include "minirt_image.h"
# include "minirt_scene.h"
# include "minirt_application.h"
# include "minirt_events.h"
# include "minirt_render.h"
# include "minirt_parsing.h"
# include "minirt_display.h"
# include "minirt_save.h"
# include "minirt_exit.h"

extern struct s_app			*g_app;

#endif
