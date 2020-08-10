/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:07:03 by jabilbo           #+#    #+#             */
/*   Updated: 2020/08/10 18:52:27 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				burning_ship(t_fractol *fractol)
{
	t_complex	z;
	int			iteration;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < fractol->max_iteration)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->c.re,
			-fractol->had * fabs(z.re * z.im) + fractol->c.im);
		fractol->zn = sqrt(z.re * z.re + z.im * z.im);
		iteration++;
	}
	return (iteration);
}
