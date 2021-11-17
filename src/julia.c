/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:52:46 by scuter            #+#    #+#             */
/*   Updated: 2021/11/17 18:45:56 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_data *d)
{
	d->fractal_index = 0;
	d->width = 1280;
	d->height = 720;
	d->zoom = 200;
	d->x_offset = -3.25;
	d->y_offset = -1.75;
	d->i = 0;
	d->itmax = 127;
}

static void	iterate_julia(t_data *d)
{
	while (d->z_real * d->z_real + d->z_imag * d->z_imag < 4 && d->i < d->itmax)
	{
		d->tmp = d->z_real;
		d->z_real = d->z_real * d->z_real - d->z_imag * d->z_imag + d->c_real;
		d->z_imag = 2 * d->tmp * d->z_imag + d->c_imag;
		d->i++;
	}
}

static void	colorize_julia(t_data *d)
{
	if (d->i == d->itmax)
		d->i = 0;
	if (d->i < 64)
		d->color = 0x00000000 + d->i * 0x00010204;
	else
		d->color = 0x004080FF + (d->i - 64) * 0x00010200;
	ft_memmove(d->pixels + (4 * (d->width * d->y + d->x)), \
				&d->color, sizeof(int));
}

void	draw_julia(t_data *d)
{
	d->y = 0;
	while (d->y < d->height)
	{
		d->x = 0;
		while (d->x < d->width)
		{
			d->z_real = d->x / d->zoom + d->x_offset;
			d->z_imag = d->y / d->zoom + d->y_offset;
			iterate_julia(d);
			colorize_julia(d);
			d->i = 0;
			d->x++;
		}
		d->y++;
	}
	mlx_put_image_to_window(d->mlx, d-> win, d->img, 0, 0);
}
