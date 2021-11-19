/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 03:48:09 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/19 21:04:40 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_shift_info	*init_shift_info(void)
{
	t_shift_info	*shift_info;

	shift_info = (t_shift_info *)malloc(sizeof(t_shift_info));
	if (!(shift_info))
		return (NULL);
	shift_info->a_node = NULL;
	shift_info->b_node = NULL;
	shift_info->a_direction = R;
	shift_info->b_direction = R;
	shift_info->size = 0;
	shift_info->is_set = FALSE;
	return (shift_info);
}

static void	move_b(t_stack *a_stack, t_stack *b_stack,
					t_shift_info *shift_info, t_cmd_lst *cmd_lst)
{
	while (shift_info->a_node != a_stack->top
		|| shift_info->b_node != b_stack->top)
	{
		if (shift_info->a_direction == shift_info->b_direction \
				&& shift_info->a_node != a_stack->top \
				&& shift_info->b_node != b_stack->top)
			shift_info->is_set = ((shift_info->a_direction == R) && \
			try_rr(a_stack, b_stack, "rr\n", cmd_lst)) || \
			try_rrr(a_stack, b_stack, "rrr\n", cmd_lst);
		else if (shift_info->a_node != a_stack->top)
			shift_info->is_set = ((shift_info->a_direction == R) && \
			try_rotate(a_stack, "ra\n", cmd_lst)) || \
			try_reverse_rotate(a_stack, "rra\n", cmd_lst);
		else if (shift_info->b_node != b_stack->top)
			shift_info->is_set = ((shift_info->a_direction == R) && \
			try_rotate(b_stack, "rb\n", cmd_lst)) || \
			try_reverse_rotate(b_stack, "rrb\n", cmd_lst);
	}
}

void	solve_b(t_stack *a_stack, t_stack *b_stack, t_cmd_lst *cmd_lst)
{
	t_shift_info	*shift_info;

	shift_info = init_shift_info();
	while (b_stack->size)
	{
		shift_info->is_set = FALSE;
		find_min_cmd(a_stack, b_stack, shift_info);
		move_b(a_stack, b_stack, shift_info, cmd_lst);
		push(a_stack, pop(b_stack));
		add_command(cmd_lst, create_command("pa\n"));
	}
	free(shift_info);
}
