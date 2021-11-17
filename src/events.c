/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:28:06 by scuter            #+#    #+#             */
/*   Updated: 2021/11/16 17:53:47 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_pressed(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

int	mouse_pressed(int code, int x, int y, t_data *d)
{
	if (code == 1 || code == 4)
	{
		d->y_offset += (y / d->zoom) - (y / (d->zoom * 1.25));
		d->x_offset += (x / d->zoom) - (x / (d->zoom * 1.25));
		d->zoom *= 1.25;
	}
	else if (code == 2 || code == 5)
	{
		d->y_offset += (y / d->zoom) - (y / (d->zoom / 1.25));
		d->x_offset += (x / d->zoom) - (x / (d->zoom / 1.25));
		d->zoom /= 1.25;
	}
	launch_draw(d);
	return (0);
}

int	clean_exit(void)
{
	exit(0);
}
