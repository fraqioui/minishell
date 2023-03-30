/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:58:39 by fraqioui          #+#    #+#             */
/*   Updated: 2023/02/26 11:46:57 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static void	ft_print_format(const char *s, va_list arg_f, int *len)
{
	if (*s == 'c')
	{
		ft_putchar(va_arg(arg_f, int));
		(*len)++;
	}
	else if (*s == 's')
		*len += ft_putstr(va_arg(arg_f, char *));
	else if (*s == 'd' || *s == 'i')
		*len += ft_putnbr(va_arg(arg_f, int));
	else if (*s == 'u')
		*len += ft_putuns(va_arg(arg_f, unsigned int));
	else if (*s == 'x')
		*len += ft_puthex(va_arg(arg_f, unsigned int), 'x');
	else if (*s == 'X')
		*len += ft_puthex(va_arg(arg_f, unsigned int), 'X');
	else if (*s == 'p')
		*len += ft_putptr(va_arg(arg_f, unsigned long));
	else
	{
		ft_putchar(*s);
		(*len)++;
	}
}

int	ft_printf(const char *l_f_arg, ...)
{
	va_list	arg_f;
	int		l;

	va_start(arg_f, l_f_arg);
	l = 0;
	while (*l_f_arg)
	{
		if (*l_f_arg == '%')
		{
			l_f_arg++;
			if (!(*l_f_arg))
				return (l);
			ft_print_format(l_f_arg, arg_f, &l);
		}
		else
		{
			ft_putchar(*l_f_arg);
			l++;
		}
		l_f_arg++;
	}
	va_end(arg_f);
	return (l);
}
