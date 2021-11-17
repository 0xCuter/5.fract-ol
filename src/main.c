/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:41:34 by scuter            #+#    #+#             */
/*   Updated: 2021/11/17 18:40:09 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	select_fractal(t_data *d, char *param)
{
	if (ft_strcmp(param, "mandelbrot") == 0)
		init_mandelbrot(d);
	else if (ft_strcmp(param, "burningship") == 0)
		init_burn(d);
	else if (ft_strcmp(param, "julia") == 0)
	{
		init_julia(d);
		d->c_real = -0.56;
		d->c_imag = 0.52;
	}
	else if (ft_strcmp(param, "julia2") == 0)
	{
		init_julia(d);
		d->c_real = 0.285;
		d->c_imag = -0.01;
	}
	else if (ft_strcmp(param, "julia3") == 0)
	{
		init_julia(d);
		d->c_real = -0.835;
		d->c_imag = -0.2321;
	}
	else
		return (0);
	return (1);
}

void	launch_draw(t_data *d)
{
	if (d->fractal_index == 0)
		draw_julia(d);
	else if (d->fractal_index == 1)
		draw_mandelbrot(d);
	else if (d->fractal_index == 2)
		draw_burn(d);
}

static void	init(t_data *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->width, d->height, "fract-ol");
	d->img = mlx_new_image(d->mlx, d->width, d->height);
	d->pixels = mlx_get_data_addr(d->img, \
				&d->bits_per_pixel, &d->size_line, &d->endian);
	launch_draw(d);
	mlx_key_hook(d->win, key_pressed, NULL);
	mlx_mouse_hook(d->win, mouse_pressed, d);
	mlx_hook(d->win, 17, 0, clean_exit, NULL);
	mlx_loop(d->mlx);
}

int	main(int argc, char **argv)
{
	t_data	d;

	if ((argc != 2) || !(select_fractal(&d, argv[1])))
	{
		ft_putstr_fd("usage: ./fractol [julia]/[julia2]/\
[julia3]/[mandelbrot]/[burningship]\n", 2);
		return (1);
	}
	init(&d);
	return (0);
}
