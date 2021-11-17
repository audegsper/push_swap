/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 04:35:37 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/17 05:24:17 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_direction(size_t size,
					t_shift_info new_shift_info, t_shift_info *shift_info)
{
	if (!shift_info->is_set || size < shift_info->size)
	{
		shift_info->a_node = new_shift_info.a_node;
		shift_info->b_node = new_shift_info.b_node;
		shift_info->a_direction = new_shift_info.a_direction;
		shift_info->b_direction = new_shift_info.b_direction;
		shift_info->size = size;
		shift_info->is_set = TRUE;
	}
}

static void	estimate_direction(t_stack *stack, int index,
								size_t *r_size, size_t *rr_size)
{
	t_node	*current;

	if (stack && stack->top)
	{
		current = stack->top;
		while (current->index != index)
		{
			(*r_size)++;
			current = current->next;
		}
		current = stack->top;
		while (current->index != index)
		{
			(*rr_size)++;
			current = current->prev;
		}
	}
}

static t_node	*find_a_node(t_stack *a_stack, int b_index)
{
	t_node	*current;

	current = a_stack->markup_head;
	if (b_index < current->index)
	{
		while (b_index < current->prev->index
			&& current->index > current->prev->index)
			current = current->prev;
	}
	else
	{
		while (b_index > current-> index
			&& current->index < current->next->index)
			current = current->next;
		if (b_index > current->index && current->index > current->next->index)
			current = current->next;
	}
	return (current);
}

static void	optimal_direction(t_stack *a_stack, t_stack* b_stack,
								t_node *b_node, t_shift_info *shift_info)
{
	t_shift_info	new_shift_info;
	size_t			ra_size;
	size_t			rra_size;
	size_t			rb_size;
	size_t			rrb_size;

	ra_size = 0;
	rra_size = 0;
	rb_size = 0;
	rrb_size = 0;
	new_shift_info.a_node = find_a_node(a_stack, b_node->index);
	new_shift_info.b_node = b_node;
	estimate_direction(a_stack, new_shift_info.a_node->index, &ra_size, &rra_size);
	estimate_direction(b_stack, b_node->index, &rb_size, &rrb_size);
	new_shift_info.a_direction = R;
	new_shift_info.b_direction = R;
	set_direction(ft_max(ra_size, rb_size), new_shift_info, shift_info);
	new_shift_info.a_direction = RR;
	set_direction(rra_size + rb_size, new_shift_info, shift_info);
	new_shift_info.b_direction = RR;
	set_direction(ft_max(rra_size, rrb_size), new_shift_info, shift_info);
	new_shift_info.a_direction = R;
	set_direction(ra_size + rrb_size, new_shift_info, shift_info);
}

void	opt_direction(t_stack *a_stack, t_stack *b_stack, t_shift_info *shift_info)
{
	size_t	i;
	t_node	*current;

	if (b_stack)
	{
		i = 0;
		current = b_stack->top;
		while (i < b_stack->size)
		{
			optimal_direction(a_stack, b_stack, current, shift_info);
			i++;
			current = current->next;
		}
	}
}
