/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:36:23 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/09 12:37:41 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MAX_ITERATIONS 50
# define WIDTH 800
# define HEIGHT 600

typedef struct s_point {
	double	x;
	double	y;
}	t_point;

typedef struct s_img {
	void	*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
}	t_img;

typedef struct s_vars {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	t_img	*prev;
	t_img	*next;
	void	(*type)(struct s_vars *vars);
	t_point	max;
	t_point	min;
	t_point	factor;
	t_point	offset;
}	t_vars;

typedef struct s_color {
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	t;
}	t_color;

void	compute_fractal(t_vars *vars);

// Fractal types
void	init_mandelbrot(t_vars *vars);
void	compute_mandelbrot(t_vars *vars);
int		mandelbrot(t_point p);
void	init_julia(double x, double y, t_vars *vars);
void	compute_julia(t_vars *vars);
int		julia(t_point p, t_vars *vars);

// Colors
t_color	get_color(int color);
void	set_color(t_color color, int pixel, t_vars *vars);

// Hooks
void	hook(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		scroll_hook(int keycode, int x, int y, t_vars *vars);
int		quit(t_vars *vars);
void	move_fractal(int keycode, t_vars *vars);

// Math
double	ft_atof(char *nbr);

#endif
