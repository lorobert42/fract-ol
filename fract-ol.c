/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:58 by lorobert          #+#    #+#             */
/*   Updated: 2022/10/26 14:54:48 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft/libft.h"
#include "fract-ol.h"

int	quit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	exit(0);
}

int key_hook(int keycode, t_vars *vars)
{
	ft_printf("Hello: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit(0);
	}
	return (0);
}

int mandelbrot(float x, float y)
{
	float x0;
	float y0;
	int i;
	float tmp;

	x0 = x / 800 * 5 - 3;
	y0 = y / 600 * 4 - 2;
	x = 0;
	y = 0;
	i = 0;
	while ((x * x) + (y * y) <= 4 && i < 255)
	{
		tmp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = tmp;
		i++;
	}
	return (i);
}

int	main()
{
	t_vars	vars;
	void	*img_ptr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	int 	color;
	int 	x;
	int 	y;
	int 	pixel;

	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 800, 600, "Fract-ol");

	img_ptr = mlx_new_image(vars.mlx_ptr, 800, 600);
	buffer = mlx_get_data_addr(img_ptr, &pixel_bits, &line_bytes, &endian);

//	if (pixel_bits != 32)
//		color = mlx_get_color_value(vars.mlx_ptr, color);
	y = 0;
	while (y < 600)
	{
		x = 0;
		while (x < 800)
		{
			color = mandelbrot((float)x, (float)y) * 10000;
			pixel = (y * line_bytes) + (x * 4);
			if (endian)
			{
				buffer[pixel + 0] = (color >> 24);
				buffer[pixel + 1] = (color >> 16) & 0xFF;
				buffer[pixel + 2] = (color >> 8) & 0xFF;
				buffer[pixel + 3] = (color) & 0xFF;
			}
			else
			{
				buffer[pixel + 0] = (color) & 0xFF;
				buffer[pixel + 1] = (color >> 8) & 0xFF;
				buffer[pixel + 2] = (color >> 16) & 0xFF;
				buffer[pixel + 3] = (color >> 24);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, img_ptr, 0, 0);

	mlx_key_hook(vars.win_ptr, key_hook, &vars);
	mlx_hook(vars.win_ptr, 17, 0, quit, &vars);
	mlx_loop(vars.mlx_ptr);
}