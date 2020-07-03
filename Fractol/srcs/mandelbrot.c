/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:21:20 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/03 21:30:32 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				mandelbrot(t_mlx mlx)
{
	t_complex		z;
	t_fractol		cor;
	double			iteration;
	bool			stop;
	
	cor.max.re = 2.0;
	cor.min = init_complex(-2.0, -2.0);
	cor.max.im = cor.min.im + (cor.max.re - cor.min.re) * HEIGHT / WIDTH;
	cor.factor = init_complex(
		(cor.max.re - cor.min.re) / (WIDTH - 1),
		(cor.max.im - cor.min.im) / (HEIGHT - 1));
	
	cor.max_iteration = 60;
	
	cor.y = 0;
	
	while (cor.y < HEIGHT)
	{
		cor.c.im = cor.max.im - cor.y * cor.factor.im;
		cor.x = 0;
		
		while (cor.x < WIDTH)
		{
			cor.c.re = cor.min.re + cor.x * cor.factor.re;
			z = init_complex(cor.c.re, cor.c.im);
			stop = true;
			iteration = 0;

			while(iteration < cor.max_iteration)
			{
				if(z.re * z.re + z.im * z.im >= 4)
				{
					stop = false;
					break;
				}
				z = init_complex(
                	pow(z.re, 2.0) - pow(z.im, 2.0) + cor.c.re,
    				2.0 * z.re * z.im + cor.c.im);
				iteration++;
			}
				draw(cor, mlx, iteration);	
			cor.x++;
		}
		cor.y++;
	}
}
