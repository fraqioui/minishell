/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 07:49:47 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/16 11:26:54 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

// static void	print(t_node *root)
// {
// 	if (root->tok != NOT)
// 	{
// 		print(root->lchild);
// 		print(root->rchild);
// 	}
// 	if (root->tok == NOT)
// 		printf("%d\t%s\n", root->tok, root->cmd[0]);
// 	else
// 		printf("%d\n", root->tok);
// 	return ;
// }

t_node	*parsing(char *input)
{
	char	*s;
	t_node	*head;
	t_token	tok;

	s = ft_strtrim(input, " \t\n\v\r\f");
	if (!s)
		return (NULL);
	tok = check_token(s[0], s[1]);
	if (tok == OR || tok == AND)
	{
		ft_printf("bash: syntax error near unexpected token `%c%c'\n", s[0], s[1]);
		return (NULL);
	}
	else if (tok == PIPE || tok == RPR)
	{
		ft_printf("bash: syntax error near unexpected token `%c'\n", s[0]);
		return (NULL);
	}
	head = tokenize(s);
	if (!head)
		return (NULL);
	// t_node *trav = head;
	// while (trav)
	// {
	// 	if (trav->cmd)
	// 		printf("%s\t", trav->cmd[0]);
	// 	printf("%d\n", trav->tok);
	// 	trav = trav->rchild;
	// }
	// head = handle_redirections(head);
	// trav = head;
	// while (trav)
	// {
	// 	if (trav->redirections)
	// 	{
	// 		t_node *tmp = trav->redirections;
	// 		while (tmp)
	// 		{
	// 			printf(". %d\t%s\n", tmp->tok, tmp->cmd[0]);
	// 			tmp = tmp->rchild;
	// 		}
	// 	}
	// 	if (trav->cmd)
	// 		printf("cmd: %s\n", trav->cmd[0]);
	// 	printf("%d\n", trav->tok);
	// 	trav = trav->rchild;
	// }
	// head = final_cmd(head);
	// trav = head;
	// while (trav)
	// {
	// 	if (trav->cmd)
	// 		printf("%s\t%s\t", trav->cmd[0], trav->cmd[1]);
	// 	printf("- %d\n", trav->tok);
	// 	trav = trav->rchild;
	// }
	// puts("here\n");
	// exit(0);
	// head = re_order_command(&head);
	// while (head->rchild)
	// 	head = head->rchild;
	// head = list_to_tree(head);
	// print(head);
	return (head);
}

// static	int	check_redi(t_token tok)
// {
// 	return (tok == IN || tok == OUT || tok == APPEND || tok == HEREDOC);
// }

// static	void	separator(t_node **head, t_node **tmp)
// {
// 	t_node	*sep;

// 	if (!head || !*head)
// 		return ;
// 	sep = *head;
// 	if ((*head)->rchild)
// 		(*head)->rchild->lchild = (*head)->lchild;
// 	if ((*head)->lchild)
// 		(*head)->lchild->rchild = (*head)->rchild;
// 	if ((*head)->rchild)
// 		*head = (*head)->rchild;
// 	else if (!(*head)->rchild)
// 		*head = (*head)->lchild;
// 	sep->rchild = NULL;
// 	sep->lchild = NULL;
// 	list_build(tmp, sep);
// }

// t_node	*handle_redirections(t_node *head)
// {
// 	t_node	*tmp;
// 	t_node	*save;

// 	tmp = NULL;
// 	while (head)
// 	{
// 		printf("ent: %d\n", head->tok);
// 		if ((head->tok == NOT && head->rchild) || check_redi(head->tok))
// 		{
// 			if (head->tok == NOT)
// 				head = head->rchild;
// 			while (head && check_redi(head->tok))
// 				separator(&head, &tmp);
// 		}
// 		else if (head->tok != NOT)
// 		{
// 			save = head;
// 			printf("tmp: %s\n", head->lchild->cmd[0]);
// 			head->lchild->redirections = tmp;
// 			tmp = NULL;
// 			head = head->rchild;
// 		}
// 		else if (!head->rchild)
// 		{
// 			head->redirections = tmp;
// 			tmp = NULL;
// 			head = head->rchild;
// 		}
// 	}
// 	while (save->lchild)
// 		save = save->lchild;
// 	return (save);
// }

// static	void	pop(t_node **tok_s)
// {
// 	t_node	*save;

// 	ft_alloc_fail((*tok_s)->cmd);
// 	if ((*tok_s)->lchild)
// 		(*tok_s)->lchild->rchild = (*tok_s)->rchild;
// 	if ((*tok_s)->rchild)
// 		(*tok_s)->rchild->lchild = (*tok_s)->lchild;
// 	save = *tok_s;
// 	*tok_s = (*tok_s)->rchild;
// 	free(save);
// }

// t_node *final_cmd(t_node *head)
// {
// 	t_node	*trav;
// 	t_node	*save;
// 	char	**tmp;
// 	int		l;
// 	int		i;
// 	int		j;

// 	trav = head;
// 	while (trav)
// 	{0
// 		printf("check: %d\n", trav->tok);
// 		if (trav->tok == NOT)
// 		{
// 			l = 0;
// 			save = trav;
// 			while (save && save->tok == NOT)
// 			{
// 				j = 0;
// 				while (save->cmd[j++])
// 					l++;
// 				save = save->rchild;
// 			}
// 			printf("l: %d\n", l);
// 			tmp = malloc(sizeof(char *) * (l + 1));
// 			if (!tmp)
// 				return (NULL);
// 			i = 0;
// 			while (trav && trav->tok == NOT)
// 			{
// 				j = 0;
// 				while (trav->cmd[j])
// 					tmp[i++] = trav->cmd[j++];
// 				tmp[i] = 0;
// 				if (!trav->rchild || trav->rchild->tok != NOT)
// 				{
// 					puts("3here\n");
// 					ft_alloc_fail(trav->cmd);
// 					printf("klsj: %s\n", tmp[0]);
// 					trav->cmd = tmp;
// 					head = trav;
// 					trav = trav->rchild;
// 					puts("4here\n");
// 				}
// 				else
// 					{puts("1here\n");pop(&trav); puts("2here\n");}
// 			}
// 		}
// 		if (trav)
// 			trav = trav->rchild;
// 	}
// 	while (head->lchild)
// 		head = head->lchild;
// 	return (head);
// }
