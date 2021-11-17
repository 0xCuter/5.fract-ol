/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:24:32 by scuter            #+#    #+#             */
/*   Updated: 2021/11/17 18:44:55 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*pixels;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		fractal_index;
	int		width;
	int		height;
	double	x_offset;
	double	y_offset;
	double	zoom;
	int		x;
	int		y;
	int		i;
	int		itmax;
	double	z_real;
	double	z_imag;
	double	c_real;
	double	c_imag;
	double	tmp;
	int		color;
}	t_data;

void	launch_draw(t_data *d);
void	init_mandelbrot(t_data *d);
void	draw_mandelbrot(t_data *d);
void	init_julia(t_data *d);
void	draw_julia(t_data *d);
void	init_burn(t_data *d);
void	draw_burn(t_data *d);
int		key_pressed(int key);
int		mouse_pressed(int code, int x, int y, t_data *d);
int		clean_exit(void);

#endif
