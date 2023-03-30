/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:58:39 by fraqioui          #+#    #+#             */
/*   Updated: 2023/02/26 11:47:04 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putchar(char c)
{
	write(2, &c, 1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		write(2, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		len++;
		write(2, s++, 1);
	}
	return (len);
}
