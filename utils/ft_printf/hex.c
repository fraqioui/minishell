/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:05:14 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/04 14:45:17 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_len(unsigned long n)
{
	int	l;

	l = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		l++;
		n /= 16;
	}
	return (l);
}

int	ft_puthex(unsigned int num, char alpha)
{
	char	*table;
	int		capital;
	char	*h;
	int		len;
	int		tmp;

	table = "0123456789abcdef0123456789ABCDEF";
	capital = 0;
	len = ft_len(num);
	h = malloc(sizeof(char) * (len + 1));
	if (!h)
		return (0);
	if (alpha == 'X')
		capital = 16;
	tmp = len;
	h[tmp--] = '\0';
	if (num == 0)
		h[tmp] = table[0];
	while (num)
	{
		h[tmp--] = table[(num % 16) + capital];
		num /= 16;
	}
	ft_putstr(h);
	return (free(h), h = NULL, len);
}

int	ft_puthex_uns(unsigned long num)
{
	char	*table;
	char	*h;
	int		len;
	int		tmp;

	table = "0123456789abcdef";
	len = ft_len(num);
	h = malloc(sizeof(char) * (len + 1));
	if (!h)
		return (0);
	tmp = len;
	h[tmp--] = '\0';
	if (num == 0)
		h[tmp] = table[0];
	while (num)
	{
		h[tmp--] = table[(num % 16)];
		num /= 16;
	}
	ft_putstr(h);
	free(h);
	h = NULL;
	return (len);
}

int	ft_putptr(unsigned long ptr)
{
	int	len;

	len = 0;
	ft_putstr("0x");
	len += 2;
	len += ft_puthex_uns(ptr);
	return (len);
}
