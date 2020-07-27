/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 06:11:05 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/27 18:15:17 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH				600
# define HEIGHT				600
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define MAIN_PAD_PLUS		24
# define MAIN_PAD_MINUS		27
# define MAIN_PAD_ESC		53
# define MAIN_PAD_SPACE		49

# define RGB(r, g, b) (256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

# include <libft.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_fractol
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				max_iteration;
	double			iteration;
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	t_complex		c;
	t_complex		k;
	double			x;
	double			y;
	double			zn;
	char			*name;
	bool			fix_jul;
	double			i;
}					t_fractol;

void				mandelbrot(t_fractol *fractol);
void				julia(t_fractol *fractol);
void				draw(t_fractol *fractol);
int					get_color(t_fractol *fractol);
t_complex			init_complex(double re, double im);
void				set_defaults(t_fractol *fractol);
int					julia_motion(int x, int y, t_fractol *fractol);
int					ft_close(void *param);
int					key_press(int key, t_fractol *fractol);
void				init_fractol(t_fractol *fractol);
int					zoom(int button, int x, int y, t_fractol *fractol);
double				interpolate(double start, double end, double interpolation);

#endif
