/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 21:22:21 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/06 18:09:11 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				julia(t_fractol *fractol)
{
	t_complex		z;
	double			iteration;
	
	fractol->y = 0;
	
	while (fractol->y < HEIGHT)
	{
		fractol->k.im = fractol->max.im - fractol->y * fractol->factor.im;
		fractol->x = 0;
		
		while (fractol->x < WIDTH)
		{
			fractol->k.re = fractol->min.re + fractol->x * fractol->factor.re;
			z = init_complex(fractol->k.re, fractol->k.im);
			iteration = 0;

			while(iteration < fractol->max_iteration)
			{
				if(z.re * z.re + z.im * z.im >= 4)
					break;
				z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->k.re,
					2.0 * z.re * z.im + fractol->k.im);
				iteration++;
			}
				draw(fractol, iteration);
			fractol->x++;
		}
		fractol->y++;
	}
}