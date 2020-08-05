/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 11:37:44 by jabilbo           #+#    #+#             */
/*   Updated: 2020/08/05 22:10:16 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

static void		put_pixel(t_fractol *fractol, int x, int y, t_color color)
{
	int			i;

	i = (x * fractol->image->bits_per_pixel / 8)
		+ (y * fractol->image->size_line);
	fractol->image->data_addr[i] = color.channel[3];
	fractol->image->data_addr[++i] = color.channel[2];
	fractol->image->data_addr[++i] = color.channel[1];
	fractol->image->data_addr[++i] = color.channel[0];
}

static void		draw_fractol(t_fractol *fractol)
{
	int			y;
	int			x;
	t_color		color;

	y = fractol->start_line;
	while (y < fractol->finish_line)
	{
		fractol->c.im = fractol->max.im - y * fractol->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			fractol->c.re = fractol->min.re + x * fractol->factor.re;
			color = get_color(init_fractol(fractol), fractol);
			put_pixel(fractol, x, y, color);
			x++;
		}
		y++;
	}
}

void			draw(t_fractol *fractol)
{
	pthread_t	threads[THREADS];
	t_fractol	fractols[THREADS];
	int			i;

	fractol->factor = init_complex(
		(fractol->max.re - fractol->min.re) / (WIDTH - 1),
		(fractol->max.im - fractol->min.im) / (HEIGHT - 1));
	i = 0;
	while (i < THREADS)
	{
		fractols[i] = *fractol;
		fractols[i].start_line = i * ((HEIGHT - 1) / THREADS);
		fractols[i].finish_line = (i + 1) * (HEIGHT / THREADS);
		if (pthread_create(&threads[i], NULL,
			(void *(*)(void *))draw_fractol, (void *)&fractols[i]))
			terminate("ERROR");
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
	 		terminate("ERROR");
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->image->image, 0, 0);
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, 900, 965, COLOR_TUNDORA,
		"H - Help");
}

t_color			get_color(int iteration, t_fractol *fractol)
{
	t_color		color;
	double		continuous_index;

	if (!(iteration / fractol->max_iteration == 1))
	{
		continuous_index = iteration + 1 - (log(2) / fractol->zn) / log (2);
		color.channel[0] = 0;
		color.channel[1] =
			(int8_t)((unsigned char)(sin((0.001 * 8) * continuous_index + 1 + fractol->i1) * 240 + 10));
		color.channel[2] =
			(int8_t)((unsigned char)(sin((0.001 * 8) * continuous_index + 2 + fractol->i2) * 240 + 10));
		color.channel[3] =
			(int8_t)((unsigned char)(sin((0.001 * 8) * continuous_index + 4 + fractol->i3) * 240 + 10));
	}
	else
	{
		color.channel[0] = 0;
		color.channel[1] = 0;
		color.channel[2] = 0;
		color.channel[3] = 0;
	}
	
	return (color);
}