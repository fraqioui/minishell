/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:58:39 by fraqioui          #+#    #+#             */
/*   Updated: 2022/11/05 10:04:26 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdlib.h>
# include<unistd.h>
# include<stdarg.h>

int		ft_printf(const char *l_f_arg, ...);
void	ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putuns(unsigned int num);
int		ft_puthex(unsigned int num, char alpha);
int		ft_puthex_uns(unsigned long num);
int		ft_putptr(unsigned long ptr);

#endif
