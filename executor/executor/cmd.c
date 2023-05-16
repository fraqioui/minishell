/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:31:29 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/10 16:00:36 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	bool	is_builtin(char **cmd)
{
	if (!ft_memcmp("cd", cmd[0], ft_strlen(cmd[0]) + 1))
		return (_cd_(cmd), true);
	if (!ft_memcmp("echo", cmd[0], ft_strlen(cmd[0]) + 1))
		return (_echo_(cmd), true);
	if (!ft_memcmp("env", cmd[0], ft_strlen(cmd[0]) + 1))
		return (_env_(), true);
	if (!ft_memcmp("exit", cmd[0], ft_strlen(cmd[0]) + 1))
		return (_exit_(cmd), true);
	if (!ft_memcmp("export", cmd[0], ft_strlen(cmd[0]) + 1))
		return (_export_(cmd), true);
	if (!ft_memcmp("pwd", cmd[0], ft_strlen(cmd[0]) + 1))
		return (_pwd_(), true);
	if (!ft_memcmp("unset", cmd[0], ft_strlen(cmd[0]) + 1))
		return (_unset_(cmd), true);
	return (false);
}

static	char	*find_path(char *cmd)
{
	char		**path;
	char		*ret;
	char		*keep;
	struct stat	sb;

	path = ft_split(get_env("PATH"), ':');
	if (!path)
		return (print_error(2, cmd, strerror(ENOENT)),
			exit_with_status(CMD_N_FOUND), NULL);
	keep = ft_strdup(cmd);
	ret = find_path_help(path, keep);
	if (ret)
	{
		stat(ret, &sb);
		if (S_ISDIR(sb.st_mode))
			return (ft_alloc_fail(path), free(keep), free(ret),
				print_error(2, cmd, "is a directory"),
				exit_with_status(NOT_EXEC), NULL);
	}
	ft_alloc_fail(path);
	free(keep);
	return (ret);
}

static	int	executing_cmd(t_node *root, char *path, char **env)
{
	execve(path, root->cmd, env);
	print_error(2, "execve", strerror(errno));
	if (errno == ENOENT)
		exit(CMD_N_FOUND);
	if (errno == EACCES)
		exit(NOT_EXEC);
	exit(1);
}

static	void	child_exec(t_node *root, char *path, int *status)
{
	char	**env;
	pid_t	pid;

	env = separate_env(g_gb.env);
	if (!env)
		return ;
	pid = _fork_();
	if (pid < 0)
		return ;
	if (pid == 0)
	{
		_signal_middle_exec();
		executing_cmd(root, path, env);
	}
	waitpid(pid, status, 0);
	free(env);
}

void	exec_cmd(t_node *root)
{
	int		status;
	char	*path;

	if (!_expanding_(root) || !deal_w_redir(root))
		return ;
	if (root->cmd && !root->cmd[0])
		(free(root->cmd), root->cmd = NULL);
	if (root->cmd && root->cmd[0] && !is_builtin(root->cmd))
	{
		path = find_path(root->cmd[0]);
		if (path)
		{
			child_exec(root, path, &status);
			free(path);
			exit_with_status(update_exit_st(status));
		}
	}
}
