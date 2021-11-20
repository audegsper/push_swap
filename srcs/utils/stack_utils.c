/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:41:13 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/20 18:42:48 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_init(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->index = -1;
	new_node->keep_stack = FALSE;
	return (new_node);
}

void	init_all(t_stack *stack, t_cmd_lst *cmd_lst)
{
	if (stack != NULL)
	{
		stack->top = NULL;
		stack->set_idx = NULL;
		stack->bottom = NULL;
		stack->markup_head = NULL;
		stack->pairs = 0;
		stack->size = 0;
	}
	if (cmd_lst != NULL)
	{
		cmd_lst->size = 0;
		cmd_lst->head = NULL;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;
	size_t	i;

	i = 0;
	while (i++ < stack->size)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	stack->size = 0;
}
