/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evolve_func_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:55:25 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/02 17:58:25 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

int	_chdir_(const char *path)
{
	if (!chdir(path))
		return (0);
	print_error("cd", strerror(errno), 1, 1);
	return (-1);
}

int	executing_cmd(t_node *root)
{
	char	**env;

	env = separate_env(g_gb.env);
	execve(find_path(root->cmd[0]), root->cmd, env);
	//free
	if (errno == ENOENT)
		exit(CMD_N_FOUND);
	if (errno == EACCES)
		exit(NOT_EXEC);
	exit(1);
}
