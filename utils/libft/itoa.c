/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:14:58 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/06 10:15:15 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static size_t	ft_size(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*ft_strrev(char *s)
{
	size_t	i;
	size_t	j;
	char	tmp;

	i = 0;
	tmp = 0;
	j = ft_strlen(s);
	while (i < j / 2)
	{
		tmp = s[j - i - 1];
		s[j - i -1] = s[i];
		s[i] = tmp;
		i++;
	}
	return (s);
}

static unsigned int	ft_checksign(int num)
{
	unsigned int	s;

	s = num;
	if (num < 0)
		s *= -1;
	return (s);
}

char	*ft_itoa(int n)
{
	char			*s;
	size_t			i;
	int				j;
	unsigned int	digit1;

	i = 0;
	j = 0;
	i = ft_size(n);
	digit1 = ft_checksign(n);
	s = malloc((i + 1) * sizeof(char));
	if (!s)
		return (0);
	if (n == 0)
		s[j++] = '0';
	while (digit1)
	{
		s[j++] = (digit1 % 10) + '0';
		digit1 /= 10;
	}
	if (n < 0)
		s[j++] = '-';
	s[j] = '\0';
	return (ft_strrev(s));
}
