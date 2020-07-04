/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 11:37:44 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/03 22:12:37 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw(t_fractol cor, t_mlx mlx, int iteration)
{
	int			color;
	color = get_color(iteration, cor);
	mlx_pixel_put(mlx.mlx_ptr, mlx.wim_ptr, cor.x, cor.y, color);
}

int				get_color(int iteration, t_fractol cor)
{
	double			color;
	double			t;
	t = (double)iteration / (double)cor.max_iteration;
	if (t == 1){
		color = 0x000000;}
	else
	{
		color = 0xFF0000 * t;
	}
	
	return (color);
}