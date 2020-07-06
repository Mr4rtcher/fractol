/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 06:11:05 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/06 21:22:37 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH		1000
# define HEIGHT		1000

# include <libft.h>
# include <mlx.h>
# include <stdio.h>

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_fractol
{
	void			*mlx_ptr;
	void			*wim_ptr;
	int				max_iteration;
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	t_complex		c;
	t_complex		k;
	double			x;
	double			y;
	int				color_shift;
}					t_fractol;

void				mandelbrot(t_fractol *fractol);
int					julia(int x, int y, t_fractol *fractol);
void				draw(t_fractol *fractol, int iteration);
int					get_color(int iteration, t_fractol *fractol);
t_complex			init_complex(double re, double im);
void				set_defaults(t_fractol *fractol);

#endif
