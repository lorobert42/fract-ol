/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:58 by lorobert          #+#    #+#             */
/*   Updated: 2022/10/26 14:54:48 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

typedef struct s_img {
	void	*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
} t_img;

typedef	struct s_vars {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img 	*img_ptr;
} t_vars;

#endif
