/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:02:38 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/10 14:32:24 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include"minishell_defines.h"

void	_cd_(char **cmd);
void	_echo_(char **cmd);
void	_env_(void);
void	_exit_(char **cmd);
void	_export_(char **cmd);
void	_pwd_(void);
void	_unset_(char **cmd);
void	_and_(t_node *root);
void	_or_(t_node *root);
void	_pipe_(t_node *root);
void	exec_cmd(t_node *root);
void	executing(t_node *root);
int		_chdir_(const char *path);
void	initialize(char **env, int *fd_in, int *fd_out);
t_node	*tokenize(char *s);
t_node	*parsing(char *input);
t_token	check_token(char c1, char c2);
char	*cmd_help(char *s, ssize_t l, ssize_t *k, bool flg);
char	**fill_cmd(char *s, ssize_t l, ssize_t *k, bool flg);
bool	check_tok_syntax(t_token tok, char *s, ssize_t *i, ssize_t *par);
t_node	*which_token_2(char	*s, t_token tok, ssize_t *i);
bool	check_syntax(t_token tok, char *s);
void	_signal_start(void);
void	_signal_middle_exec(void);
bool	update_pwd(char *pwd);
bool	update_oldpwd(char *old_pwd);

bool	_expanding_(t_node *node);
char	**parse_cmd(char *s);
char	*parse_redir(t_redir *red, char *s, bool *flg);
ssize_t	inside_quo(char *s, ssize_t *i);
ssize_t	look_for_quo(char *s, ssize_t *i, char c);
ssize_t	var_len(char *s);
char	*expand_var(char *s, ssize_t *i);
bool	is_identifier(int c);
void	replace_cmd(char *ret, char *s);
char	**handle_wildcard_cmd(char **args);
void	checking(char *s, int *flg);
char	*new_cmd(char *s, bool *flg);
bool	check_patterns(char *d_name, char *pattern);
char	**separate_env(t_env *env);
char	*find_path_help(char **to_sear, char *cmd);
int		handle_redirections(t_node *root);
bool	check_tok(char *s);
bool	check_true(t_token tok);
bool	check_spaces(char c);
bool	choose_str(char c, bool flg);
int		check_pre(t_token tok);
void	print_error(int n, ...);
void	exit_with_status(int exit_status);
ssize_t	check_next_quote(char *s, char c);
ssize_t	check_rpr(char *s, ssize_t i);
ssize_t	not_len(char *s, ssize_t i, bool flg);
int		pipe_sc(int ends[2]);
pid_t	_fork_(void);
int		dup_2(int fild1, int fild2);
int		_close_(int n, ...);
int		_open_(const char *path, int oflag, mode_t mode);

t_node	*re_order_command(t_node **head);
void	push(t_node **a_head, t_node **b_head, bool flg);
t_node	*list_to_tree(t_node *root);
int		list_build_cmd(t_node **head, t_node *add);
int		list_build_redir(t_redir **head, t_redir *add);
t_node	*node_creation_cmd(char *s, t_redir *redir,
			t_token tok, int precedence);
t_redir	*node_creation_redir(char **s, t_token tok);
t_env	*node_creation_env(char *env, char *var, char *value);

void	ft_putstr_fd(char *s, int fd);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	**ft_alloc_fail(char **arr);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		num_words(const char *s2, char c);
void	*ft_calloc(size_t count, size_t size);
bool	ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strdup(const char *s);
void	lstadd_front_env(t_env **lst, t_env *new);
void	lstadd_back_env(t_env **lst, t_env *new);
char	*get_env(const char *name);
ssize_t	calc_args(char **av);
int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	find_c(char *s, char c);
void	_export_var(char *s, char c);
bool	identifier_front(int c);
void	_free_(t_env *env);
void	ret_mem_back(t_node *root);
void	free_env(void);
int		ret_fd_in(t_node *node);
int		ret_fd_out(t_node *node);
void	*malloc_error(int errnum);
void	set_in_out(int in, int out);
int		update_exit_st(int status);
char	*ft_itoa(int n);
void	_free_head(t_node *head);
void	free_space(void);
ssize_t	_write_(int fildes, const char *buf, size_t nbyte);
void	calc_files(char *s, ssize_t *l);
void	should_expnd(bool *flg);
bool	deal_w_redir(t_node *root);

#endif
