/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:21:20 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/06 18:09:03 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				mandelbrot(t_fractol *fractol)
{
	t_complex		z;
	double			iteration;
	
	fractol->y = 0;
	
	while (fractol->y < HEIGHT)
	{
		fractol->c.im = fractol->max.im - fractol->y * fractol->factor.im;
		fractol->x = 0;
		
		while (fractol->x < WIDTH)
		{
			fractol->c.re = fractol->min.re + fractol->x * fractol->factor.re;
			z = init_complex(fractol->c.re, fractol->c.im);
			iteration = 0;

			while(iteration < fractol->max_iteration)
			{
				if(z.re * z.re + z.im * z.im >= 4)
					break;
				z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->c.re,
					2.0 * z.re * z.im + fractol->c.im);
				iteration++;
			}
				draw(fractol, iteration);
			fractol->x++;
		}
		fractol->y++;
	}
}
