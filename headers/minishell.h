/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:02:38 by fraqioui          #+#    #+#             */
/*   Updated: 2023/03/31 08:46:57 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include"minishell_defines.h"

//parser
t_node	*parsing(char *s);
t_node	*tokenize(char *input);
void	*ft_calloc(size_t count, size_t size);
t_token	check_token(char c1, char c2);
int		check_syntax(t_token tok, char *s);
//tree
t_node	*re_order_command(t_node **head);
t_node	*list_to_tree(t_node *head);
t_node	*node_creation(char **s, t_token tok, int precedence);
void	list_build(t_node **head, t_node *add);
int		check_next_quote(char *s);
int		check_rpr(char *s, int i);
int		check_spaces(char c);
char	**fill_cmd(char *s, int l, int *k);

//utils
void	ft_putstr_fd(char *s, int fd);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	**free_2d(char **arr);
int		ft_strcmp(char *s1, char *s2);

#endif
