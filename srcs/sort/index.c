/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:46:15 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/18 06:54:01 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_markup_stack_index(t_stack *stack, t_node *markup_head)
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

void	opt_markup_stack(t_stack *stack)
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
			current_pairs = ft_markup_stack_index(stack, current);
			if (current_pairs > stack->pairs)
			{
				stack->markup_head = current;
				stack->pairs = current_pairs;
			}
			else if (current_pairs == stack->pairs &&
				(!stack->markup_head ||
					current->value < stack->markup_head->value))
				stack->markup_head = current;
			i++;
			current = current->next;
		}
		ft_markup_stack_index(stack, stack->markup_head);
	}
}

static t_node	*ft_get_next_min(t_stack *stack)
{
	size_t		i;
	t_bool		has_min;
	t_node		*min;
	t_node		*current;

	if(stack)
	{
		min = NULL;
		i = 0;
		has_min = FALSE;
		current = stack->top;
		while (i < stack->size)
		{
			if ((current->index == -1)
			&& (!has_min || current->value < min->value))
			{
				has_min = TRUE;
				min = current;
			}
			i++;
			current = current->next;
		}
	}
	return (min);
}

void	ft_index_stack(t_stack *stack)
{
	size_t		index;
	t_node		*current;

	index = 0;
	while ((current = ft_get_next_min(stack)))
		current->index = index++;
	opt_markup_stack(stack);
}
