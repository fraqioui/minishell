/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:02:38 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/16 11:37:23 by fraqioui         ###   ########.fr       */
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
//executing
void	executing(t_node *root);
//tree
t_node	*re_order_command(t_node **head);
t_node	*list_to_tree(t_node *root);
t_node	*node_creation_cmd(char **s, t_redir *redir, t_token tok, int precedence);
t_redir	*node_creation_redir(char *s, t_token tok);
int 	list_build_cmd(t_node **head, t_node *add);
int 	list_build_redir(t_redir **head, t_redir *add);
t_node	*handle_redirections(t_node *head);
int		check_next_quote(char *s);
int		check_rpr(char *s, int i);
int		check_spaces(char c);
char	**fill_cmd(char *s, int l, int *k, int flg);
char	*cmd_help(char *s, int l, int *k, int flg);
int		check_pre(t_token tok);
t_node *final_cmd(t_node *head);
void	push(t_node **a_head, t_node **b_head, int flg);
//builtins
//points to a string containing an ``='' character.
int		_cd_(char *path, char **env);
int		_pwd_(void);
//utils
void	ft_putstr_fd(char *s, int fd);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	**ft_alloc_fail(char **arr);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
