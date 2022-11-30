/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:55:48 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/09 11:55:51 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_point p)
{
	float	zx;
	float	zy;
	int		i;

	zx = p.x;
	zy = p.y;
	i = 0;
	while (zx * zx + zy * zy <= 4 && i < MAX_ITERATIONS)
	{
		zx = zx * zx - zy * zy + p.x;
		zy = 2.0 * zx * zy + p.y;
		i++;
	}
	return (i);
}