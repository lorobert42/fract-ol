/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:58 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/09 12:32:35 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx/mlx.h"
#include "libft/libft.h"
#include "fractol.h"

int	quit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	ft_printf("Hello: %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit(0);
	}
	return (0);
}

int	scroll_hook(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == 4)
		ft_printf("Scroll up\n");
	else if (keycode == 5)
		ft_printf("Scroll down\n");
	return (0);
}

void	hook(t_vars *vars)
{
	mlx_key_hook(vars->win_ptr, key_hook, vars);
	mlx_hook(vars->win_ptr, 17, 0, quit, vars);
	mlx_mouse_hook(vars->win_ptr, scroll_hook, vars);
}

int	main(void)
{
	t_vars	vars;
	t_point	p;
	int		color;
	int		pixel;

	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 800, 600, "Fract-ol");
	vars.img_ptr->addr = mlx_new_image(vars.mlx_ptr, 800, 600);
	vars.img_ptr->buffer = mlx_get_data_addr(vars.img_ptr->addr, \
			&vars.img_ptr->pixel_bits, &vars.img_ptr->line_bytes, \
			&vars.img_ptr->endian);
	p.y = 0;
	while (p.y < 600)
	{
		p.x = 0;
		while (p.x < 800)
		{
			color = mandelbrot(p);
			color = get_color(color, vars);
			pixel = ((int)p.y * vars.img_ptr->line_bytes) + ((int)p.x * 4);
			set_color(color, pixel, vars.img_ptr);
			p.x++;
		}
		p.y++;
	}
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, \
			vars.img_ptr->addr, 0, 0);
	hook(&vars);
	mlx_loop(vars.mlx_ptr);
}
