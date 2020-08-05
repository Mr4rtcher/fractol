/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 21:22:21 by jabilbo           #+#    #+#             */
/*   Updated: 2020/08/05 20:47:57 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					julia(t_fractol *fractol)
{
	t_complex		z;
	int				iteration;

	z = init_complex(fractol->c.re, fractol->c.im);
	iteration = 0;
	while(iteration < fractol->max_iteration
		&& (pow(z.re, 2.0) + pow(z.im, 2.0)) <= 4)
	{
		z = init_complex(
		pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->k.re,
					2.0 * z.re * z.im + fractol->k.im);
		fractol->zn = sqrt(pow(z.re, 2.0) + pow(z.im, 2.0));
		iteration++;
	}
	return (iteration);
}