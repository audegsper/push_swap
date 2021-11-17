/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:46:15 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/14 19:13:53 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}
