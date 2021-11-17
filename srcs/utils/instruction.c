/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:26:49 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/18 05:32:13 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	stack->top = stack->top->prev;
}

void	rotate(t_stack *stk)
{
	if (stk->top == NULL || stk->top->next == NULL)
		return ;
	stk->top = stk->top->next;
}

t_node	*pop(t_stack *stack)
{
	t_node	*tmp_top;

	tmp_top = NULL;
	if (stack && stack->size)
	{
		if (stack->size == 1)
		{
			tmp_top = stack->top;
			stack->top = NULL;
			tmp_top->prev = NULL;
			tmp_top->next = NULL;
		}
		else
		{
			tmp_top = stack->top;
			stack->top = stack->top->next;
			tmp_top->prev->next =	tmp_top->next;
			tmp_top->next->prev =	tmp_top->prev;
			tmp_top->prev = NULL;
			tmp_top->next = NULL;
		}
		stack->size--;
	}
	return (tmp_top);
}

void	push(t_stack *stack, t_node *node)
{
	t_node *tmp_bottom;

	if (stack && node)
	{
		if (!stack->top)
		{
			stack->top = node;
			stack->top->prev = stack->top;
			stack->top->next = stack->top;
		}
		else
		{
			tmp_bottom = stack->top->prev;
			node->prev = tmp_bottom;
			tmp_bottom->next = node;
			node->next = stack->top;
			stack->top->prev = node;
			stack->top = node;
		}
		stack->size++;
	}
}

void	swap(t_stack *stk)
{
	t_node	*second;
	t_node	*prev;
	t_node	*next;

	if (stk->top == NULL || stk->top->next == NULL)
		return ;
	prev = stk->top->prev;
	second = stk->top->next;
	next = stk->top->next->next;
	prev->next = stk->top->next;
	second->prev = prev;
	stk->top->next = next;
	next->prev = stk->top;
	second->next = stk->top;
	stk->top->prev = second;
	stk->top = second;
	if (stk->size == 2)
		stk->bottom = stk->top->next;
}
