/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:00:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/22 16:24:08 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PARSING_H
# define MINIRT_PARSING_H

void	parse_scene(t_scene *scene, const char *filepath);
char	*read_scene_file(t_scene *scene, const char *filepath);

#endif
