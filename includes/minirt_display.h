/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_display.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:25 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/01 01:29:10 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DISPLAY_H
# define MINIRT_DISPLAY_H

void	switch_camera(t_scene *scene);
void	open_window(void);
void	put_image_to_window(void);
void	resize_window(t_scene *scene);
void	display_rendering(t_scene *scene);

#endif
