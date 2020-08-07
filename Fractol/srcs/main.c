/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 04:17:01 by jabilbo           #+#    #+#             */
/*   Updated: 2020/08/07 18:20:12 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					ft_close(void *param)
{
	(void)param;
	exit(0);
}

void				terminate(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}

int					init_fractol(t_fractol *fractol)
{
	if (ft_strcmp("mandelbrot", fractol->name) == 0)
		return (mandelbrot(fractol));
	if (ft_strcmp("julia", fractol->name) == 0)
		return (julia(fractol));
	if (ft_strcmp("burning_ship", fractol->name) == 0)
		return (burning_ship(fractol));
	if (ft_strcmp("mandelbar", fractol->name) == 0)
		return (mandelbar(fractol));
	if (ft_strcmp("buffalo", fractol->name) == 0)
		return (buffalo(fractol));
	else
		terminate("ERROR");
	return (0);
}

static void			start(char *name)
{
	t_fractol		*fractol;

	if (!(fractol = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		terminate("ERROR");
	fractol->name = name;
	fractol->mlx_ptr = mlx_init();
	if (!(fractol->win_ptr = mlx_new_window(
		fractol->mlx_ptr, HEIGHT, WIDTH, fractol->name)))
		terminate("ERROR");
	fractol->image = init_image(fractol->mlx_ptr);
	fractol->fix_jul = true;
	set_defaults(fractol);
	mlx_hook(fractol->win_ptr, 2, 0, key_press, fractol);
	mlx_hook(fractol->win_ptr, 17, 0, ft_close, fractol);
	mlx_hook(fractol->win_ptr, 4, 0, zoom, fractol);
	if (ft_strequ(name, "julia"))
		mlx_hook(fractol->win_ptr, 6, 0, julia_motion, fractol);
	draw(fractol);
	mlx_loop(fractol->mlx_ptr);
}

int					main(int ac, char **av)
{
	if (ac == 2)
		start(av[1]);
	return (0);
}
