/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:13:17 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/17 03:45:34 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	align_a(t_stack *a_stack, t_cmd_lst *cmd_lst)
{
	t_node	*current;
	size_t	ra_size;
	size_t	rra_size;

	if (a_stack && a_stack->top)
	{
		ra_size = 0;
		current = a_stack->top;
		while (current->index != 0)
		{
			ra_size++;
			current = current->next;
		}
		rra_size = 0;
		current = a_stack->top;
		while (current->index != 0)
		{
			rra_size++;
			current = current->prev;
		}
		while (a_stack->top->index != 0 && (ra_size < rra_size))
			try_rotate(a_stack, "ra\n", cmd_lst);
		while (a_stack->top->index != 0 && (ra_size >= rra_size))
			try_reverse_rotate(a_stack, "rra\n", cmd_lst);
	}
}

void	ft_solve(t_stack *a_stack, t_bool which_dir, t_cmd_lst	*cmd_lst)
{
	t_stack		*b_stack;

	b_stack = (t_stack *)malloc(sizeof(t_stack));
	init_cmd_lst(cmd_lst);
	init_stack(b_stack);
	solve_a(a_stack, b_stack, which_dir, cmd_lst);
	solve_b(a_stack, b_stack, cmd_lst);
	align_a(a_stack, cmd_lst);
	free_stack(b_stack);
}
