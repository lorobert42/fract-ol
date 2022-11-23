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

int	get_color(int color, t_vars vars)
{
	if (color == 255)
		color = 0x000000;
	else
		color = (int)pow(color, 5);
	if (vars.img_ptr->pixel_bits != 32)
		color = (int)mlx_get_color_value(vars.mlx_ptr, color);
	return (color);
}

void	set_color(int color, int pixel, t_img *img)
{
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