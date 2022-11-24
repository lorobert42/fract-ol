/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:52:35 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/09 11:52:40 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx/mlx.h"
#include "fractol.h"

t_color	get_color(int index)
{
	t_color	color;
	double	t;

	t = (double)index / (double)MAX_ITERATIONS;
	if (index == 1000)
	{
		color.r = (unsigned char)0;
		color.g = (unsigned char)0;
		color.b = (unsigned char)0;
		color.t = (unsigned char)0;
	}
	else
	{
		color.r = (unsigned char)(9 * (1 - t) * pow(t, 3) * 255);
		color.g = (unsigned char)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		color.b = (unsigned char)(8.5 * pow((1 - t), 3) * t * 255);
		color.t = (unsigned char)0;
	}
	return (color);
}

void	set_color(t_color c, int pixel, t_img *img, t_vars vars)
{
	int	color;

	color = (c.t << 24 | c.r << 16 | c.g << 8 | c.b);
	if (vars.img->pixel_bits != 32)
		color = mlx_get_color_value(vars.mlx_ptr, color);
	if (img->endian)
	{
		img->buffer[pixel + 0] = (char)(color >> 24);
		img->buffer[pixel + 1] = (char)((color >> 16) & 0xFF);
		img->buffer[pixel + 2] = (char)((color >> 8) & 0xFF);
		img->buffer[pixel + 3] = (char)((color) & 0xFF);
	}
	else
	{
		img->buffer[pixel + 0] = (char)((color) & 0xFF);
		img->buffer[pixel + 1] = (char)((color >> 8) & 0xFF);
		img->buffer[pixel + 2] = (char)((color >> 16) & 0xFF);
		img->buffer[pixel + 3] = (char)(color >> 24);
	}
}
