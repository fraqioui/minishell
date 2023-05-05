/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:04:12 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/04 14:45:59 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_len(long long n)
{
	int	l;

	l = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		l++;
	while (n)
	{
		l++;
		n /= 10;
	}
	return (l);
}

int	ft_putnbr(int n)
{
	unsigned int	num;
	char			*h;
	int				tmp;

	num = n;
	h = malloc(sizeof(char) * (ft_len(n) + 1));
	if (!h)
		return (0);
	if (n < 0)
	{
		num *= -1;
		h[0] = '-';
	}
	tmp = ft_len(n);
	h[tmp--] = '\0';
	if (num == 0)
		h[tmp] = '0';
	while (num)
	{
		h[tmp--] = "0123456789"[(num % 10)];
		num /= 10;
	}
	ft_putstr(h);
	return (free(h), h = NULL, ft_len(n));
}

int	ft_putuns(unsigned int num)
{
	char	*table;
	int		len;
	char	*h;
	int		tmp;

	table = "0123456789";
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
		h[tmp--] = table[(num % 10)];
		num /= 10;
	}
	ft_putstr(h);
	free(h);
	h = NULL;
	return (len);
}
