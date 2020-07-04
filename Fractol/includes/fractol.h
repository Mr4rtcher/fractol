/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 06:11:05 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/04 21:34:13 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH		1400
# define HEIGHT		1400

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

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*wim_ptr;
}					t_mlx;

void				mandelbrot(t_mlx mlx);
void				julia(t_mlx mlx);
void				draw(t_fractol cor, t_mlx mlx, int iteration);
int					get_color(int iteration, t_fractol cor);
t_complex			init_complex(double re, double im);

#endif
