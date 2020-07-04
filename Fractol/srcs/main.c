/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 04:17:01 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/04 21:21:49 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main(int ac, char **av)
{
	t_mlx		mlx;
	char		str_m[] = "mandelbrot";
	char		str_j[] = "julia";
	mlx.mlx_ptr = mlx_init();
	mlx.wim_ptr = mlx_new_window(mlx.mlx_ptr, HEIGHT, WIDTH, "FRACTOL");
	if (ac == 2)
	{
		if (ft_strcmp(str_m, av[1]) == 0)
			mandelbrot(mlx);
		if (ft_strcmp(str_j, av[1]) == 0)
			julia(mlx);
	}
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
