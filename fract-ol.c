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
#include <math.h>
#include "mlx/mlx.h"
#include "libft/libft.h"
#include "fractol.h"

int	quit(t_vars *vars)
{
	mlx_destroy_image(vars->mlx_ptr, vars->img->addr);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	free(vars->img);
	exit(0);
}

void	move_fractal(int keycode, t_vars *vars)
{
	if (keycode == 65361)
	{
		vars->min.x -= fabs(vars->min.x) * vars->factor.x * 10;
		vars->max.x -= fabs(vars->min.x) * vars->factor.x * 10;
	}
	else if (keycode == 65363)
	{
		vars->min.x += fabs(vars->min.x) * vars->factor.x * 10;
		vars->max.x += fabs(vars->min.x) * vars->factor.x * 10;
	}
	else if (keycode == 65362)
	{
		vars->min.y += fabs(vars->min.y) * vars->factor.y * 10;
		vars->max.y += fabs(vars->min.y) * vars->factor.y * 10;
	}
	else if (keycode == 65364)
	{
		vars->min.y -= fabs(vars->min.y) * vars->factor.y * 10;
		vars->max.y -= fabs(vars->min.y) * vars->factor.y * 10;
	}
	vars->type(vars);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
		vars->img->addr, 0, 0);
}

void	print_help(void)
{
	ft_printf("Usage: ./fractol [type] [parameters]");
	exit(0);
}

void	parse_args(int argc, char **argv, t_vars *vars)
{
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		init_mandelbrot(vars);
	else if (!ft_strncmp(argv[1], "julia", 5))
	{
		if (argc != 4)
			init_julia(0.3, 0.5, vars);
		else
			init_julia(ft_atof(argv[2]), ft_atof(argv[3]), vars);
	}
	else if (!ft_strncmp(argv[1], "burning_ship", 10))
		init_burning_ship(vars);
	else if (!ft_strncmp(argv[1], "cos", 10))
	{
		if (argc != 4)
			init_cos(0.3, 0.5, vars);
		else
			init_cos(ft_atof(argv[2]), ft_atof(argv[3]), vars);
	}
	else
		print_help();
}

int	main(int argc, char **argv)
{
	t_vars		vars;

	if (argc == 1)
		print_help();
	parse_args(argc, argv, &vars);
	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	vars.img = malloc(sizeof(t_img));
	vars.img->addr = mlx_new_image(vars.mlx_ptr, WIDTH, HEIGHT);
	vars.img->buffer = mlx_get_data_addr(vars.img->addr, \
			&vars.img->pixel_bits, &vars.img->line_bytes, \
			&vars.img->endian);
	vars.type(&vars);
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, \
			vars.img->addr, 0, 0);
	hook(&vars);
	mlx_loop(vars.mlx_ptr);
}
