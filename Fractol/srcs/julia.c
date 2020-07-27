/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 21:22:21 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/27 18:15:30 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				julia(t_fractol *fractol)
{
	t_complex		z;
	
	fractol->y = 0;

	while (fractol->y < HEIGHT)
	{
		fractol->c.im = fractol->max.im - fractol->y * fractol->factor.im;
		fractol->x = 0;
		
		while (fractol->x < WIDTH)
		{
			fractol->c.re = fractol->min.re + fractol->x * fractol->factor.re;
			z = init_complex(fractol->c.re, fractol->c.im);
			fractol->iteration = 0;

			while(fractol->iteration < fractol->max_iteration
				&& (pow(z.re, 2.0) + pow(z.im, 2.0)) <= 4)
			{
				z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->k.re,
					2.0 * z.re * z.im + fractol->k.im);
				fractol->zn = sqrt(pow(z.re, 2.0) + pow(z.im, 2.0));
				fractol->iteration++;
			}
				draw(fractol);
			fractol->x++;
		}
		fractol->y++;
	}
}

int					julia_motion(int x, int y, t_fractol *fractol)
{
	if (!fractol->fix_jul)
	{
	fractol->k = init_complex(
		4 * ((double)x / WIDTH - 0.5),
		4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		julia(fractol);
	}
	return (0);
}