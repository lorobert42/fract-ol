/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:20:47 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/14 09:46:53 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fractol.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static double	ft_atof_decimal(char *nbr)
{
	double	res;
	double	factor;
	int		i;

	i = 0;
	while (nbr[i] != '.')
		i++;
	i++;
	res = 0;
	factor = 10.0;
	while (ft_isdigit(nbr[i]))
	{
		res += ((double)nbr[i] - '0') / factor;
		factor *= 10.0;
		i++;
	}
	return (res);
}

double	ft_atof(char *nbr)
{
	double	res;
	int		i;
	int		sign;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(nbr[i]))
		i++;
	if (nbr[i] == '+')
		i++;
	else if (nbr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(nbr[i]) && nbr[i] != '.')
	{
		res = (res * 10) + (nbr[i] - '0');
		i++;
	}
	if (nbr[i] == '.')
		res += ft_atof_decimal(nbr);
	res *= sign;
	return (res);
}
