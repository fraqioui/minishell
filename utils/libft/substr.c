/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:40:41 by fraqioui          #+#    #+#             */
/*   Updated: 2022/10/18 17:14:48 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return ((char *)ft_calloc(1, sizeof(char)));
	if (ft_strlen(s) <= start + len)
		substr = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[start] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
