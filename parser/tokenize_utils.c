/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:07:32 by fraqioui          #+#    #+#             */
/*   Updated: 2023/02/24 09:01:00 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

int	even(int quo)
{
	return (quo % 2);
}

int	cal_quo(char *s)
{
	int	n;

	n = 0;
	while (*s)
	{
		if (*s == '"')
			n++;
		s++;
	}
	return (n);
}

char	*eliminate_quo(char *s, int l)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(s) - l + 1));
	if (!ret)
		return (NULL);
	while (*s)
	{
		while (*s == '"')
			s++;
		ret[i++] = *s++;
	}
	ret[i] = '\0';
	return (ret);
}
