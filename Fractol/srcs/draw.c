/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 11:37:44 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/27 18:18:50 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw(t_fractol *fractol)
{	
	fractol->y = 0;
	
	while (fractol->y < HEIGHT)
	{
		fractol->c.im = fractol->max.im - fractol->y * fractol->factor.im;
		fractol->x = 0;
		
		while (fractol->x < WIDTH)
		{
			fractol->c.re = fractol->min.re + fractol->x * fractol->factor.re;
			init_fractol(fractol);
			// z = init_complex(fractol->c.re, fractol->c.im);
			// fractol->iteration = 0;

			// while(fractol->iteration < fractol->max_iteration
			// 	&& pow(z.re, 2.0) + pow(z.im, 2.0) <= 4)
			// {
			// 	z = init_complex(
			// 	pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->c.re,
			// 		2.0 * z.re * z.im + fractol->c.im);
			// 	fractol->zn = sqrt(z.re * z.re + z.im * z.im);
			// 	fractol->iteration++;
			// }
			mlx_pixel_put(fractol->mlx_ptr, fractol->win_ptr, fractol->x, fractol->y, get_color(fractol));
			fractol->x++;
		}
		fractol->y++;
	}
	// mlx_pixel_put(fractol->mlx_ptr, fractol->win_ptr, fractol->x, fractol->y, get_color(fractol));
}

int				get_color(t_fractol *fractol)
{
	double			color;
	double			continuous_index = fractol->iteration + 1 - (log(2) / fractol->zn) / log (2);
	
	if ((double)fractol->iteration / (double)fractol->max_iteration == 1){
		color = 0x000000;}
	else
	{
		
		color = RGB(((unsigned char)(sin((0.001 * 8) * continuous_index + 1 + fractol->i) * 240 + 10)), 
			((unsigned char)(sin((0.0013 * 8) * continuous_index + 2 + fractol->i) * 240 + 10)), 
			((unsigned char)(sin((0.0016 * 8) * continuous_index + 4 + fractol->i) * 240 + 10)));
	}
	
	return (color);
}