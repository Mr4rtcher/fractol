/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:21:20 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/03 17:50:37 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				mandelbrot(t_mlx mlx)
{
	t_complex		z;
	t_fractol		cor;
	double			n;
	bool			stop;
	cor.min.re = -2.0;
	cor.max.re = 2.0;
	cor.min.im = -2.0;
	cor.max.im = cor.min.im + (cor.max.re - cor.min.re) * 500 / 500;
	cor.factor.re = (cor.max.re - cor.min.re) / (500 - 1);
	cor.factor.im = (cor.max.im - cor.min.im) / (500 - 1);
	cor.max_iteration = 50;
	cor.y = 0;
	
	while (cor.y < 500)
	{
		cor.c.im = cor.max.im - cor.y * cor.factor.im;
		cor.x = 0;
		
		while (cor.x < 500)
		{
			cor.c.re = cor.min.re + cor.x * cor.factor.re;
			z.re = cor.c.re;
			z.im = cor.c.im;
			stop = true;
			n = 0;

			while(n < cor.max_iteration)
			{
				if(z.re * z.re + z.im * z.im > 4)
				{
					stop = false;
					break;
				}
				z.im = 2 * z.re * z.im + cor.c.im;
				z.re = z.re * z.re - z.im * z.im + cor.c.re;
				n++;
			}
			if (stop)
				draw(cor, mlx);
			cor.x++;
		}
		cor.y++;
	}
}