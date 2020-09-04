/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:59:42 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/28 13:26:44 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_isdigit_base(char c, int base)
{
	char	*digits1;
	char	*digits2;
	int		i;

	i = 0;
	digits1 = "0123456789ABCDEF";
	digits2 = "0123456789abcdef";
	while (i < base)
	{
		if (digits1[i] == c || digits2[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, int base)
{
	unsigned int	result;
	int				i;

	result = 0;
	i = 2;
	while (ft_isdigit_base(str[i], base) >= 0)
		result = result * base + ft_isdigit_base(str[i++], base);
	return ((int)result);
}
