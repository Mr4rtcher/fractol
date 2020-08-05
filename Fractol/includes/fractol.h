/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 06:11:05 by jabilbo           #+#    #+#             */
/*   Updated: 2020/08/05 22:17:48 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH				1000
# define HEIGHT				1000
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define MAIN_PAD_PLUS		24
# define MAIN_PAD_MINUS		27
# define MAIN_PAD_ESC		53
# define MAIN_PAD_SPACE		49
# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124

# define THREADS			8

# define RGB(r, g, b) (256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define COLOR_TUNDORA		0x444444

# include <libft.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>

typedef	struct		s_color
{
	int8_t			channel[4];
}					t_color;

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_image
{
	void			*image;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_fractol
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			*image;
	int				max_iteration;
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	t_complex		c;
	t_complex		k;
	double			zn;
	char			*name;
	bool			fix_jul;
	int				i1;
	int				i2;
	int				i3;
	int				start_line;
	int				finish_line;
}					t_fractol;

int					mandelbrot(t_fractol *fractol);
int					julia(t_fractol *fractol);
void				draw(t_fractol *fractol);
t_color				get_color(int iteration, t_fractol *fractol);
t_image				*init_image(void *mlx);
t_complex			init_complex(double re, double im);
void				set_defaults(t_fractol *fractol);
int					julia_motion(int x, int y, t_fractol *fractol);
int					ft_close(void *param);
int					key_press(int key, t_fractol *fractol);
int					init_fractol(t_fractol *fractol);
void				move(int key, t_fractol *fractol);
int					zoom(int key, int x, int y, t_fractol *fractol);
double				interpolate(double start, double end, double interpolation);
void				terminate(char *s);

#endif
