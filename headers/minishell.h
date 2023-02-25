/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:02:38 by fraqioui          #+#    #+#             */
/*   Updated: 2023/02/25 11:48:36 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include"minishell_defines.h"

//parser
void	tokenize(char *s);
int		even(int quo);
int		cal_quo(char *s);
char	*eliminate_quo(char *s, int l);

//tree
void	tree_build(char **args);

//utils
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s);
char	**free_2d(char **arr);
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);

#endif
