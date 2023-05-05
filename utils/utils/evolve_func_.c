/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evolve_func_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:55:25 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/04 14:41:23 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

int	_chdir_(const char *path)
{
	if (!chdir(path))
		return (0);
	print_error(2, "cd", strerror(errno));
	exit_with_status(1);
	return (-1);
}

int	executing_cmd(t_node *root)
{
	char	**env;
	char	*path;

	env = separate_env(g_gb.env);
	path = find_path(root->cmd[0]);
	printf("path: %s\n", path);
	execve(path, root->cmd, env);
	puts("gh");
	//free
	if (errno == ENOENT)
		exit(CMD_N_FOUND);
	if (errno == EACCES)
		exit(NOT_EXEC);
	exit(1);
}
