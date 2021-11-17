/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:26:49 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/17 05:03:16 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	// t_node	*tmp_second;
	// t_node	*last;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	stack->top = stack->top->prev;
	// tmp_second = stack->top;
	// last = stack->bottom->prev;
	// last->next = stack->bottom;
	// stack->bottom->next = tmp_second;
	// tmp_second->prev = stack->bottom;
	// stack->bottom->prev = last;
	// stack->top = stack->bottom;
	// stack->bottom = last;
	// print(a_stack, b_stack);
	// printf("------rrotate--------\n");
}

void	rotate(t_stack *stk)
{
	// t_node	*tmp_bottom;

	if (stk->top == NULL || stk->top->next == NULL)
		return ;
	stk->top = stk->top->next;
	// tmp_bottom = stk->top;
	// stk->top = stk->top->next;
	// stk->top->prev = tmp_bottom;
	// tmp_bottom->next = stk->top;
	// tmp_bottom->prev = stk->bottom;
	// stk->bottom->next = tmp_bottom;
	// stk->bottom = tmp_bottom;
	// print(a_stack, b_stack);
	// printf("-------rotate-------\n");
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
	// if (first_stack->top == NULL)
	// 	return ;
	// tmp_top = first_stack->top;
	// first_stack->top = first_stack->top->next;
	// if (first_stack->top != NULL)
	// 	first_stack->top->prev = first_stack->bottom;
	// if (second_stack->top != NULL)
	// 	second_stack->top->prev = tmp_top;
	// tmp_top->next = second_stack->top;
	// second_stack->top = tmp_top;
	// second_stack->top->prev = second_stack->bottom;
	// first_stack->size -= 1;
	// second_stack->size += 1;
	// if (first_stack->size == 1)
	// 	first_stack->bottom = first_stack->top;
	// else if (first_stack->size == 0)
	// 	first_stack->bottom = NULL;
	// if (second_stack->size == 1)
	// 	second_stack->bottom = second_stack->top;
	// print(a_stack, b_stack);
	// printf("-------push-------\n");
}

void	swap(t_stack *stk)
{
	t_node	*second;
	t_node	*prev;
	t_node	*next;

	if (stk->top == NULL || stk->top->next == NULL)
		return ;
	prev = stk->top->prev; // pre->bottom
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
	// print(a_stack, b_stack);
	// printf("-------swap-------\n");
}
