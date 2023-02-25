/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:00:33 by fraqioui          #+#    #+#             */
/*   Updated: 2023/02/24 14:56:09 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

void	tokenize(char *input)
{
	char	**args;
	// char	*s;
	int		nquo;
//single quote
	nquo = cal_quo(input);
	if (even(nquo))
	{
		ft_putstr_fd("syntax error\n", 2);
		return ;
	}
	args = ft_split(input, ' ');
	for(int i = 0; args[i] ; i++)
		printf("%s\n", args[i]);
	// tree_build(args);
}
