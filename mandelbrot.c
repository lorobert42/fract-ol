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
	float	x0;
	float	y0;
	int		i;
	float	tmp;

	x0 = p.x / 800 * 5 - 3;
	y0 = p.y / 600 * 4 - 2;
	p.x = 0;
	p.y = 0;
	i = 0;
	while (p.x * p.x + p.y * p.y <= 4 && i < 1000)
	{
		tmp = p.x * p.x - p.y * p.y + x0;
		p.y = 2 * p.x * p.y + y0;
		p.x = tmp;
		i++;
	}
	return (i);
}