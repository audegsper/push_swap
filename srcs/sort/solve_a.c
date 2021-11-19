/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 03:45:43 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/19 20:34:40 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	align_a(t_stack *a_stack, t_cmd_lst *cmd_lst)
{
	t_node	*current;
	size_t	ra_size;
	size_t	rra_size;

	if (a_stack && a_stack->top)
	{
		ra_size = 0;
		current = a_stack->top;
		while (current->index != 0 && ++ra_size)
			current = current->next;
		rra_size = 0;
		current = a_stack->top;
		while (current->index != 0 && ++rra_size)
			current = current->prev;
		if (ra_size < rra_size)
			while (ra_size-- > 0)
				try_rotate(a_stack, "ra\n", cmd_lst);
		else
			while (rra_size-- > 0)
				try_reverse_rotate(a_stack, "rra\n", cmd_lst);
	}
}

static t_bool	check_pb(t_stack *a_stack)
{
	size_t	i;
	t_node	*current;

	if (a_stack != NULL)
	{
		i = 0;
		current = a_stack->top;
		while (i < a_stack->size)
		{
			if (current->keep_stack == FALSE)
				return (TRUE);
			i++;
			current = current->next;
		}
	}
	return (FALSE);
}

static t_bool	check_sa(t_stack *a_stack)
{
	size_t	current_pairs;

	if (a_stack && a_stack->size >= 2)
	{
		swap(a_stack);
		current_pairs = ft_markup_stack_index(a_stack, a_stack->markup_head);
		swap(a_stack);
		ft_markup_stack_index(a_stack, a_stack->markup_head);
		if (current_pairs > a_stack->pairs)
			return (TRUE);
	}
	return (FALSE);
}

void	solve_a(t_stack *a_stk, t_stack *b_stk, t_cmd_lst *cmd_lst)
{
	while (check_pb(a_stk))
	{
		if (check_sa(a_stk))
		{
			swap(a_stk);
			add_command(cmd_lst, create_command("sa\n"));
			a_stk->pairs = ft_markup_stack_index(a_stk, a_stk->markup_head);
		}
		else if (a_stk->top->keep_stack == FALSE)
		{
			push(b_stk, pop(a_stk));
			add_command(cmd_lst, create_command("pb\n"));
		}
		else
		{
			a_stk->top = a_stk->top->next;
			add_command(cmd_lst, create_command("ra\n"));
		}
	}
}
