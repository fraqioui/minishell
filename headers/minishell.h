/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:02:38 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/28 13:01:47 by fraqioui         ###   ########.fr       */
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
t_node	*which_token_2(char	*s, t_token tok, int *i);
int	check_tok_syntax(t_token tok, char *s, int *i, int *par);
int	check_true(t_token tok);
//executing
int	executing(t_node *root);
//tree
t_node	*re_order_command(t_node **head);
t_node	*list_to_tree(t_node *root);
t_node	*node_creation_cmd(char *s, t_redir *redir, t_token tok, int precedence);
t_redir	*node_creation_redir(char **s, t_token tok);
int 	list_build_cmd(t_node **head, t_node *add);
int 	list_build_redir(t_redir **head, t_redir *add);
int	check_next_quote(char *s, char c);
int		check_rpr(char *s, int i);
int		check_spaces(char c);
char	**fill_cmd(char *s, int l, int *k, int flg);
char	*cmd_help(char *s, int l, int *k, int flg);
int		check_pre(t_token tok);
int	choose_str(char c, int flg);
int	not_len(char *s, int i, int flg);
void	push(t_node **a_head, t_node **b_head, int flg);
//builtins
//points to a string containing an ``='' character.
int		_cd_(char *path, char **env);
int		_pwd_(void);
int     _and_(t_node *root);
int     _or_(t_node *root);
int     _pipe_(t_node *root);
int     exec_cmd(t_node *root);
int 	_expanding_(t_node *node);
char	**eliminate_quotes(char *s);
int	var_c(char c);
//utils
void	ft_putstr_fd(char *s, int fd);
char	*ft_strtrim(char const *s1, char const *set);
int	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	**ft_alloc_fail(char **arr);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int 	num_words(const char *s2, char c);

int	num_args(char **s);
int	check_var(char *s, int *l);
int	look_for_quo(char *s, int *i, char c);
int	analy_var(char *s, int *i, int *l);
char    *expand_var(char *s, int *i);
int	is_identifier(int c);
int	var_len(char *s);
int	inside_quo(char *s, int *i);
#endif
