/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 11:37:44 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/06 18:11:43 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw(t_fractol *fractol, int iteration)
{
	int			color;
	color = get_color(iteration, fractol);
	mlx_pixel_put(fractol->mlx_ptr, fractol->wim_ptr, fractol->x, fractol->y, color);
}

int				get_color(int iteration, t_fractol *fractol)
{
	double			color;
	double			t;
	t = (double)iteration / (double)fractol->max_iteration;
	if (t == 1){
		color = 0x000000;}
	else
	{
		color = 0xCCCCCC * t / 4;
	}
	
	return (color);
}