/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:56:06 by jabilbo           #+#    #+#             */
/*   Updated: 2020/08/10 19:10:53 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			move(int key, t_fractol *fractol)
{
	t_complex	delta;

	delta = init_complex((fractol->max.re - fractol->min.re),
		(fractol->max.im - fractol->min.im));
	if (key == ARROW_LEFT)
	{
		fractol->min.re -= delta.re * 0.05;
		fractol->max.re -= delta.re * 0.05;
	}
	else if (key == ARROW_RIGHT)
	{
		fractol->min.re += delta.re * 0.05;
		fractol->max.re += delta.re * 0.05;
	}
	else if (key == ARROW_UP)
	{
		fractol->min.im += delta.im * 0.05;
		fractol->max.im += delta.im * 0.05;
	}
	else if (key == ARROW_DOWN)
	{
		fractol->min.im -= delta.im * 0.05;
		fractol->max.im -= delta.im * 0.05;
	}
}

void			color_key(int key, t_fractol *fractol)
{
	if (key == 85)
		fractol->i1 += 1;
	if (key == 83)
		fractol->i1 -= 1;
	if (key == 84)
		fractol->i1 = 0;
	if (key == 88)
		fractol->i2 += 1;
	if (key == 86)
		fractol->i2 -= 1;
	if (key == 87)
		fractol->i2 = 0;
	if (key == 92)
		fractol->i3 += 1;
	if (key == 89)
		fractol->i3 -= 1;
	if (key == 91)
		fractol->i3 = 0;
}

void			had(int key, t_fractol *fractol)
{
	if (key == 116 && fractol->had < 20)
		fractol->had += 0.1;
	else if (key == 121 && fractol->had > -20)
		fractol->had -= 0.1;
}

int				key_press(int key, t_fractol *fractol)
{
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == MAIN_PAD_SPACE)
		fractol->fix_jul = !fractol->fix_jul;
	if (key == MAIN_PAD_PLUS && fractol->max_iteration < 1000)
		fractol->max_iteration += 2;
	else if (key == MAIN_PAD_MINUS && fractol->max_iteration > 1)
		fractol->max_iteration -= 2;
	if (key == 116 || key == 121)
		had(key, fractol);
	if (key == 85 || key == 83 || key == 84
		|| key == 86 || key == 88 || key == 87
		|| key == 89 || key == 91 || key == 92)
		color_key(key, fractol);
	if (key == ARROW_DOWN || key == ARROW_LEFT
		|| key == ARROW_RIGHT || key == ARROW_UP)
		move(key, fractol);
	if (key == 15)
		set_defaults(fractol);
	draw(fractol);
	return (0);
}
