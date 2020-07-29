/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 04:17:01 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/29 16:35:31 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					ft_close(void *param)
{
	(void)param;
	exit(0);
}

void				init_fractol(t_fractol *fractol)
{
	char			str_m[] = "mandelbrot";
	char			str_j[] = "julia";

	if (ft_strcmp(str_m, fractol->name) == 0)
		mandelbrot(fractol);
	else if (ft_strcmp(str_j, fractol->name) == 0)
		julia(fractol);
	else
		exit(0);
}

static void			start(char *name)
{
	t_fractol		*fractol;
	
	if (!(fractol = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		exit(1);
	fractol->name = name;
	fractol->mlx_ptr = mlx_init();
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, HEIGHT, WIDTH, fractol->name);
	set_defaults(fractol);
	mlx_hook(fractol->win_ptr, 2, 0, key_press, fractol);
	mlx_hook(fractol->win_ptr, 17, 0, ft_close, fractol);
	mlx_hook(fractol->win_ptr, 6, 0, julia_motion, fractol);
	mlx_hook(fractol->win_ptr, 4, 0, zoom, fractol);
	draw(fractol);
	mlx_loop(fractol->mlx_ptr);
}

int					main(int ac, char **av)
{
	if (ac == 2)
		start(av[1]);
	return (0);
}
