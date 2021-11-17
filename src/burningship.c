/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:43:38 by scuter            #+#    #+#             */
/*   Updated: 2021/11/17 18:44:22 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_burn(t_data *d)
{
	d->fractal_index = 2;
	d->width = 1280;
	d->height = 720;
	d->zoom = 200;
	d->x_offset = -3.25;
	d->y_offset = -2.25;
	d->i = 0;
	d->itmax = 63;
}

static void	iterate_burn(t_data *d)
{
	d->z_real = 0;
	d->z_imag = 0;
	while (d->z_real * d->z_real + d->z_imag * d->z_imag < 4 && d->i < d->itmax)
	{
		d->tmp = d->z_real;
		d->z_real = fabs(d->z_real * d->z_real - \
				d->z_imag * d->z_imag + d->c_real);
		d->z_imag = fabs(2 * d->tmp * d->z_imag + d->c_imag);
		d->i++;
	}
}

static void	colorize_burn(t_data *d)
{
	if (d->i == d->itmax)
		d->i = 0;
	if (d->i < 32)
		d->color = 0x00000000 + d->i * 0x00000800;
	else
		d->color = 0x0000FF00 + (d->i - 32) * 0x00080000;
	ft_memmove(d->pixels + (4 * (d->width * d->y + d->x)), \
				&d->color, sizeof(int));
}

void	draw_burn(t_data *d)
{
	d->y = 0;
	while (d->y < d->height)
	{
		d->x = 0;
		d->c_imag = d->y / d->zoom + d->y_offset;
		while (d->x < d->width)
		{
			d->c_real = d->x / d->zoom + d->x_offset;
			iterate_burn(d);
			colorize_burn(d);
			d->i = 0;
			d->x++;
		}
		d->y++;
	}
	mlx_put_image_to_window(d->mlx, d-> win, d->img, 0, 0);
}
