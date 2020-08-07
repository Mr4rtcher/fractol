/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:21:20 by jabilbo           #+#    #+#             */
/*   Updated: 2020/08/07 16:59:32 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					mandelbrot(t_fractol *fractol)
{
	t_complex		z;
	int				iteration;

	z = init_complex(fractol->c.re, fractol->c.im);
	iteration = 0;
	while (iteration < fractol->max_iteration
		&& pow(z.re, 2.0) + pow(z.im, 2.0) <= 4)
	{
		z = init_complex(
		pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->c.re,
			2.0 * z.re * z.im + fractol->c.im);
		fractol->zn = sqrt(z.re * z.re + z.im * z.im);
		iteration++;
	}
	return (iteration);
}
