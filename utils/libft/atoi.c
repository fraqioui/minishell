/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:19:05 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/07 21:53:07 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static char	*ft_checksign(const char *s, int *c)
{
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		*c = -1;
		s++;
	}
	return ((char *)s);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	res;
	long long	prev;
	char		*s;
	char		*save;

	sign = 1;
	res = 0;
	save = (char *)str;
	while (*str != '\0' && (*str == ' ' || *str == '\n' || *str == '\t'
			||*str == '\f' || *str == '\r' || *str == '\v'))
		str++;
	s = ft_checksign(str, &sign);
	while (*s >= '0' && *s <= '9')
	{
		prev = res;
		res = res * 10 + (*s - 48);
		if (prev != res / 10)
			(ft_putstr_fd("exit\n", 2), print_error(3, "exit", save,
					"numeric argument required"), exit_with_status(255),
				exit(-1));
		s++;
	}
	return (sign * res);
}
