/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 11:37:44 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/29 18:16:56 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw(t_fractol *fractol)
{
	fractol->factor = init_complex(
		(fractol->max.re - fractol->min.re) / (WIDTH - 1),
		(fractol->max.im - fractol->min.im) / (HEIGHT - 1));
	fractol->y = 0;
	
	while (fractol->y < HEIGHT)
	{
		fractol->c.im = fractol->max.im - fractol->y * fractol->factor.im;
		fractol->x = 0;
		
		while (fractol->x < WIDTH)
		{
			fractol->c.re = fractol->min.re + fractol->x * fractol->factor.re;
			init_fractol(fractol);
			mlx_pixel_put(fractol->mlx_ptr, fractol->win_ptr, fractol->x, fractol->y, get_color(fractol));
			fractol->x++;
		}
		fractol->y++;
	}
}

int				get_color(t_fractol *fractol)
{
	double			color;
	double			continuous_index = fractol->iteration + 1 - (log(2) / fractol->zn) / log (2);
	
	if ((double)fractol->iteration / (double)fractol->max_iteration == 1){
		color = 0x000000;}
	else
	{
		
		color = RGB(((unsigned char)(sin((0.001 * 8) * continuous_index + 1 + fractol->i1) * 240 + 10)), 
			((unsigned char)(sin((0.0013 * 8) * continuous_index + 2 + fractol->i2) * 240 + 10)), 
			((unsigned char)(sin((0.0016 * 8) * continuous_index + 4 + fractol->i3) * 240 + 10)));
	}
	
	return (color);
}