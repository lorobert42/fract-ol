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
	double	i;

	if (index == MAX_ITERATIONS)
	{
		color.r = (unsigned char)0;
		color.g = (unsigned char)0;
		color.b = (unsigned char)0;
		color.t = (unsigned char)0;
	}
	else
	{
		i = (double)index / (double)MAX_ITERATIONS;
		color.r = (unsigned char)(sin(20 * i) * 127.5 + 127.5);
		color.g = (unsigned char)(sin(20 * i + 2) * 127.5 + 127.5);
		color.b = (unsigned char)(sin(20 * i + 4.3) * 127.5 + 127.5);
		color.t = (unsigned char)0;
	}
	return (color);
}

void	set_color(t_color c, int pixel, t_vars *vars)
{
	int	color;

	color = (c.t << 24 | c.r << 16 | c.g << 8 | c.b);
	if (vars->img->pixel_bits != 32)
		color = mlx_get_color_value(vars->mlx_ptr, color);
	if (vars->img->endian)
	{
		vars->img->buffer[pixel + 0] = (char)(color >> 24);
		vars->img->buffer[pixel + 1] = (char)((color >> 16) & 0xFF);
		vars->img->buffer[pixel + 2] = (char)((color >> 8) & 0xFF);
		vars->img->buffer[pixel + 3] = (char)((color) & 0xFF);
	}
	else
	{
		vars->img->buffer[pixel + 0] = (char)((color) & 0xFF);
		vars->img->buffer[pixel + 1] = (char)((color >> 8) & 0xFF);
		vars->img->buffer[pixel + 2] = (char)((color >> 16) & 0xFF);
		vars->img->buffer[pixel + 3] = (char)(color >> 24);
	}
}
