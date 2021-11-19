/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 04:35:37 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/19 21:07:14 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_shift_info(size_t size,
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

static void	node_to_top(t_stack *stack, t_node *node,
								size_t *r_size, size_t *rr_size)
{
	t_node	*current;
	int		index;

	index = node->index;
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

static t_node	*find_a_node(t_stack *a_stack, t_node *b_node)
{
	t_node	*current;
	int		b_index;

	current = a_stack->markup_head;
	b_index = b_node->index;
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

static void	check_direction(t_stack *a_stack, t_stack *b_stack, \
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
	new_shift_info.a_node = find_a_node(a_stack, b_node);
	new_shift_info.b_node = b_node;
	node_to_top(a_stack, new_shift_info.a_node, &ra_size, &rra_size);
	node_to_top(b_stack, b_node, &rb_size, &rrb_size);
	new_shift_info.a_direction = R;
	new_shift_info.b_direction = R;
	check_shift_info(ft_max(ra_size, rb_size), new_shift_info, shift_info);
	new_shift_info.a_direction = RR;
	check_shift_info(rra_size + rb_size, new_shift_info, shift_info);
	new_shift_info.b_direction = RR;
	check_shift_info(ft_max(rra_size, rrb_size), new_shift_info, shift_info);
	new_shift_info.a_direction = R;
	check_shift_info(ra_size + rrb_size, new_shift_info, shift_info);
}

void	find_min_cmd(t_stack *a_stk, t_stack *b_stk, t_shift_info *shift_info)
{
	size_t	i;
	t_node	*current;

	if (b_stk != NULL)
	{
		i = 0;
		current = b_stk->top;
		while (i < b_stk->size)
		{
			check_direction(a_stk, b_stk, current, shift_info);
			i++;
			current = current->next;
		}
	}
}
