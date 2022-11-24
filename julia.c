/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:27:40 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/09 12:27:42 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_point p)
{
	float	x0;
	float	y0;
	int		i;
	float	tmp;

	x0 = p.x / WIDTH * 4 - 2;
	y0 = p.y / HEIGHT * 4 - 2;
	i = 0;
	while (x0 * x0 + y0 * y0 < 4 && i < 1000)
	{
		tmp = x0 * x0 - y0 * y0;
		y0 = (float)(2 * x0 * y0 + 0.11301);
		x0 = (float)(tmp + -0.74543);
		i++;
	}
	return (i);
}