/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:25:16 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/16 11:42:21 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_markup_stack_index(t_stack *stack, t_node *markup_head, t_bool stk_cat)
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
			if ((stk_cat == FT_STACK_GT && current->index > index)
			|| (stk_cat == FT_STACK && current->index == index + 1))
			{
				pairs++;
				current->keep_stack = TRUE;
				index = (stk_cat == FT_STACK ? index + 1 : current->index);
			}
			else
				current->keep_stack = FALSE;
			current = current->next;
		}
	}
	return (pairs);
}

void	opt_markup_stack(t_stack *stack, t_bool which_dir)
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
			current_pairs = ft_markup_stack_index(stack, current, which_dir);
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
		ft_markup_stack_index(stack, stack->markup_head, which_dir);
	}
}
