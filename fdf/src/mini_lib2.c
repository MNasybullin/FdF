/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lib2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:26:06 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/28 13:17:20 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *p;

	p = (unsigned char*)b;
	while (len)
	{
		*(p++) = (unsigned char)c;
		len--;
	}
	return (b);
}

void	*ft_memalloc(size_t size)
{
	void	*str;

	str = (void *)mem(size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}

void	ft_strdel(char **as)
{
	if (as != NULL && *as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

int		ft_getnbr(char *str)
{
	int	result;

	if (*str == '-')
		return (-ft_getnbr(str + 1));
	if (*str == '+')
		return (ft_getnbr(str + 1));
	result = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		result *= 10;
		result = result + *str - '0';
		str++;
	}
	return (result);
}
