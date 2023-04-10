/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:41:35 by fraqioui          #+#    #+#             */
/*   Updated: 2023/03/30 15:29:12 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

t_node	*list_to_tree(t_node *root)
{
	printf("--%d\n", root->tok);
	if (root->tok != NOT)
	{
		root->lchild = list_to_tree(root->rchild);
		root->rchild = list_to_tree(root->rchild);
		printf("ret: %d\n", root->tok);
	}
	if (root->tok == NOT)
	{
		if (root->lchild && root->rchild)
		{
			root->lchild->rchild = root->rchild;
			root->rchild->lchild = root->lchild;
			if (root->lchild->lchild)
				root->rchild->lchild = root->lchild->lchild;
		}
		root->rchild = NULL;
		root->lchild = NULL;
	}
	return (root);
}
//heredoc: /dev/null
