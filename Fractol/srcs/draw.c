/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 11:37:44 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/03 16:49:31 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_fractol cor, t_mlx mlx)
{
	int		color;
	color = 0xFFFFFF;
	mlx_pixel_put(mlx.mlx_ptr, mlx.wim_ptr, cor.x, cor.y, color);
}