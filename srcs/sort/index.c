/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:46:15 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/20 03:19:16 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	mark_keep_stack(t_stack *stack, t_node *markup_head)
{
	ssize_t	index;
	size_t	pairs;
	t_node	*current;

	pairs = 0;
	if (stack && markup_head)
	{
		index = markup_head->index;
		markup_head->keep_stack = TRUE;
		current = markup_head->next;
		while (current != markup_head)
		{
			if (current->index == index + 1)
			{
				pairs++;
				current->keep_stack = TRUE;
				index++;
			}
			else
				current->keep_stack = FALSE;
			current = current->next;
		}
	}
	return (pairs);
}

static void	set_pivot(t_stack *stack)
{
	size_t	i;
	size_t	current_pairs;
	t_node	*current;

	if (stack)
	{
		i = 0;
		current = stack->top;
		while (i < stack->size)
		{
			current_pairs = mark_keep_stack(stack, current);
			if (current_pairs > stack->pairs)
			{
				stack->markup_head = current;
				stack->pairs = current_pairs;
			}
			else if (current_pairs == stack->pairs && \
				(!stack->markup_head || \
					current->value < stack->markup_head->value))
				stack->markup_head = current;
			i++;
			current = current->next;
		}
		mark_keep_stack(stack, stack->markup_head);
	}
}

static t_node	*get_next_min(t_stack *stack)
{
	size_t		i;
	t_bool		has_min;
	t_node		*min;
	t_node		*current;

	min = NULL;
	i = 0;
	has_min = FALSE;
	current = stack->top;
	while (i < stack->size)
	{
		if ((current->index == -1) \
		&& (!has_min || current->value < min->value))
		{
			has_min = TRUE;
			min = current;
		}
		i++;
		current = current->next;
	}
	return (min);
}

void	index_stack(t_stack *stack)
{
	size_t		index;
	t_node		*current;

	index = 0;
	current = get_next_min(stack);
	while (current)
	{
		current->index = index++;
		current = get_next_min(stack);
	}
	set_pivot(stack);
}
