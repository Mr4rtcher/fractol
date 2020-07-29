/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 21:22:21 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/29 15:46:00 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				julia(t_fractol *fractol)
{
	t_complex		z;
	
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
}