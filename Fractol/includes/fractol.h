/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 06:11:05 by jabilbo           #+#    #+#             */
/*   Updated: 2020/07/01 09:01:24 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <libft.h>
# include <mlx.h>

typedef	struct		s_color
{
	int8_t			channel[4];
}					t_color;

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

#endif
