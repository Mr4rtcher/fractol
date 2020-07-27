/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:56:06 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/27 17:34:58 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			key_press(int key, t_fractol *fractol)
{
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == MAIN_PAD_SPACE)
		fractol->fix_jul = !fractol->fix_jul;
	if (key == MAIN_PAD_PLUS)
	{
		fractol->max_iteration++;
		init_fractol(fractol);
	}
	else if (key == MAIN_PAD_MINUS)
	{
		fractol->max_iteration--;
		init_fractol(fractol);
	}
	if (key == 78 || key == 69)
	{	
		if (key == 78)
			fractol->i = fractol->i + 1;
		else if (key == 69)
			fractol->i = fractol->i - 1;
		init_fractol(fractol);
	}
	printf("%d", key);
	return (0);
}