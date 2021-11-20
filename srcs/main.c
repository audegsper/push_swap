/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:15:03 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/21 01:27:35 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack_a, t_cmd_lst *cmd_lst)
{
	t_stack	stack_b;

	index_stack(stack_a);
	init_all(&stack_b, NULL);
	solve_a(stack_a, &stack_b, cmd_lst);
	solve_b(stack_a, &stack_b, cmd_lst);
	align_a(stack_a, cmd_lst);
}

void	set_arg(t_stack *stack, int arg_num)
{
	t_node	*new_node;

	new_node = node_init(arg_num);
	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->set_idx = new_node;
		stack->bottom = new_node;
		stack->size++;
	}
	else
	{
		new_node->prev = stack->set_idx;
		stack->set_idx->next = new_node;
		stack->bottom = new_node;
		stack->set_idx = new_node;
		stack->bottom->next = stack->top;
		stack->top->prev = stack->bottom;
		stack->size++;
		check_error(stack);
	}
}

int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_cmd_lst	*cmd_lst;

	if (argc == 2)
		ft_atoi(argv[1]);
	if (argc > 2)
	{
		cmd_lst = (t_cmd_lst *)malloc(sizeof(t_cmd_lst));
		init_all(&stack_a, cmd_lst);
		argc = 1;
		while (argv[argc] != NULL)
			set_arg(&stack_a, ft_atoi(argv[argc++]));
		sort(&stack_a, cmd_lst);
		print_command(cmd_lst);
		// free_command(cmd_lst);
	}
	return (0);
}
