/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 03:45:43 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/17 04:22:24 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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



static t_bool	check_sa(t_stack *a_stack, t_bool which_dir)
{
	size_t	current_pairs;

	if (a_stack && a_stack->size >= 2)
	{
		swap(a_stack);
		current_pairs = ft_markup_stack_index(a_stack, a_stack->markup_head ,which_dir);
		swap(a_stack);
		ft_markup_stack_index(a_stack, a_stack->markup_head ,which_dir);
		if (current_pairs > a_stack->pairs)
			return (TRUE);
	}
	return (FALSE);
}



void	solve_a(t_stack *a_stk, t_stack *b_stk, t_bool which_dir, t_cmd_lst *cmd_lst)
{
	while(check_pb(a_stk))
	{
		if (check_sa(a_stk, which_dir))
		{
			swap(a_stk);
			add_command(cmd_lst, create_command("sa\n"));
			a_stk->pairs = ft_markup_stack_index(a_stk, a_stk->markup_head ,which_dir);
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
