/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_drawing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:43:26 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/21 17:09:21 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DRAWING_H
# define MINIRT_DRAWING_H

void	fill_image(t_color color);
void	set_pixel(t_img *img, t_color color, int x, int y);

#endif
