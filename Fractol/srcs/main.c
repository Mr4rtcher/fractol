/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 04:17:01 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/01 08:59:43 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fractol.h>

int			main(int ac, char **av)
{
	char	str_m[10];
	char	str_j[5];

	if (ac == 2)
	{
		str_m = "Mandelbrot";
		str_j = "Julia";
		if (ft_strcmp(str_m, av[1]) == 0)
		{
		}
		else if (ft_strcmp(str_j, av[1]) == 0)
		{
		}
	}
	return (0);
}
