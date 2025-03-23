/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:06:49 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/23 19:49:03 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_H
# define DRAWING_H
# include "../includes/cub3d.h"
# include "../includes/params.h"
# include "../includes/color.h"
# include "../includes/coords.h"

void	draw_grid(t_params *params);
void	draw_square(mlx_image_t *img, t_coords pos, int side, int color);
#endif
