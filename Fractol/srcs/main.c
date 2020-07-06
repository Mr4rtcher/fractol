/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 04:17:01 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/06 18:09:20 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				set_defaults(t_fractol *fractol)
{
	fractol->max_iteration = 50;
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im + (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
		fractol->factor = init_complex(
		(fractol->max.re - fractol->min.re) / (WIDTH - 1),
		(fractol->max.im - fractol->min.im) / (HEIGHT - 1));
	fractol->k = init_complex(-0.4, 0.6);
}

static void			start(char *name)
{
	t_fractol		*fractol;

	if (!(fractol = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		exit(1);
	char			str_m[] = "mandelbrot";
	char			str_j[] = "julia";
	fractol->mlx_ptr = mlx_init();
	fractol->wim_ptr = mlx_new_window(fractol->mlx_ptr, HEIGHT, WIDTH, name);
	set_defaults(fractol);
	if (ft_strcmp(str_m, name) == 0)
		mandelbrot(fractol);
	if (ft_strcmp(str_j, name) == 0)
		julia(fractol);
	mlx_loop(fractol->mlx_ptr);
}

int				main(int ac, char **av)
{
	if (ac == 2)
		start(av[1]);
	return (0);
}
