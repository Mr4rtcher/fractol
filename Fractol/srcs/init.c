/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 18:09:50 by jabilbo           #+#    #+#             */
/*   Updated: 2020/08/10 18:59:32 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image			*init_image(void *mlx)
{
	t_image		*image;

	if (!(image = (t_image *)ft_memalloc(sizeof(t_image))))
		terminate("ERROR");
	if (!(image->image = mlx_new_image(mlx, WIDTH, HEIGHT)))
		terminate("ERROR");
	image->data_addr = mlx_get_data_addr(
		image->image,
		&(image->bits_per_pixel),
		&(image->size_line),
		&(image->endian));
	return (image);
}

t_complex		init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void			set_defaults(t_fractol *fractol)
{
	fractol->max_iteration = 50;
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im
		+ (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
	fractol->k = init_complex(-0.4, 0.6);
	fractol->i1 = 0;
	fractol->i2 = 0;
	fractol->i3 = 0;
	fractol->had = 2.0;
}
