/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffalo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:23:07 by jabilbo           #+#    #+#             */
/*   Updated: 2020/08/10 18:52:36 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				buffalo(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < fractol->max_iteration)
	{
		z = init_complex(
			fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + fractol->c.re,
			-fractol->had * z.re * fabs(z.im) + fractol->c.im);
		fractol->zn = sqrt(z.re * z.re + z.im * z.im);
		iteration++;
	}
	return (iteration);
}
