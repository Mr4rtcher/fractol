/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:56:06 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/20 13:23:44 by jabilbo          ###   ########.fr       */
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
		fractol->max_iteration++;
	else if (key == MAIN_PAD_MINUS)
		fractol->max_iteration--;
	printf("%d", key);
	return (0);
}