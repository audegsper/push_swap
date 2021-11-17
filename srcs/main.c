/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:15:03 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/18 05:03:31 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*a_node = stack_a->top;
	t_node	*b_node = stack_b->top;
	while (a_node != NULL || b_node != NULL)
	{
		if (a_node != NULL)
		{
			printf("a_node : %d\t", a_node->value);
			a_node = a_node->next;
		}
		else
		{
			printf("a_node : .\t");
			a_node = NULL;
		}
		if (b_node != NULL)
		{
			printf("b_node : %d\n", b_node->value);
			b_node = b_node->next;
		}
		else
		{
			printf("b_node : .\n");
			b_node = NULL;
		}
	}
	a_node = stack_a->top;
	b_node = stack_b->top;
	if (a_node != NULL)
	{
		printf("a_top : %d\t", stack_a->top->value);
		printf("a_bottom : %d\t",stack_a->bottom->value);
		printf("a_size : %ld\n", stack_a->size);
	}
	else
	{
		printf("a_top : .\t");
		printf("a_bottom : .\t");
		printf("a_size : .\n");
	}
	if (b_node != NULL)
	{
		printf("b_top : %d\t", stack_b->top->value);
		printf("b_bottom : %d\t", stack_b->bottom->value);
		printf("b_size : %ld\n", stack_b->size);
	}
	else
	{
		printf("b_top : .\t");
		printf("b_bottom : .\t");
		printf("b_size : .\n");
	}
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
	}
	else
	{
		new_node->prev = stack->set_idx;
		stack->set_idx->next = new_node;
		stack->bottom = new_node;
		stack->set_idx = new_node;
		stack->bottom->next = stack->top;
		stack->top->prev = stack->bottom;
		check_error(stack->top);
	}
	stack->size++;
}

static	void	ft_principal(t_stack *stack, t_stack *stack_gt)
{
	ft_index_stack(stack);
	ft_index_stack(stack_gt);
	opt_markup_stack(stack,FT_STACK);
	opt_markup_stack(stack_gt,FT_STACK_GT);
}

int	main(int argc, char** argv)
{
	t_stack		*a_top_down;
	t_stack		*a_down_top;
	t_cmd_lst	*cmd_top_down;
	t_cmd_lst	*cmd_down_top;
	int		i;

	if (argc >= 2)
	{
		cmd_top_down = (t_cmd_lst *)malloc(sizeof(t_cmd_lst));
		cmd_down_top = (t_cmd_lst *)malloc(sizeof(t_cmd_lst));
		a_top_down = (t_stack *)malloc(sizeof(t_stack));
		a_down_top = (t_stack *)malloc(sizeof(t_stack));
		init_cmd_lst(cmd_top_down);
		init_cmd_lst(cmd_down_top);
		init_stack(a_top_down);
		init_stack(a_down_top);
		i = 1;
		while (argv[i] != NULL)
		{
			argc = ft_atoi(argv[i++]);
			set_arg(a_top_down, argc);
			set_arg(a_down_top, argc);
		}
		ft_principal(a_top_down, a_down_top);
		ft_solve(a_top_down, FT_STACK, cmd_top_down);
		ft_solve(a_down_top, FT_STACK_GT, cmd_down_top);
		print_command(cmd_top_down->size < cmd_down_top->size ?
						cmd_top_down : cmd_down_top);
	}
	exit(0);
}

	// free_command(cmd_top_down);
	// free_command(cmd_down_top);
	// free_stack(a_top_down);
	// free_stack(a_down_top);

	// print(&stack_a, &stack_b);
	// printf("--------------\n");
	// push(&stack_a, &stack_b, &stack_a, &stack_b);
	// push(&stack_a, &stack_b, &stack_a, &stack_b);
	// push(&stack_b, &stack_a, &stack_a, &stack_b);
	// push(&stack_b, &stack_a, &stack_a, &stack_b);
	// swap(&stack_a, &stack_a, &stack_b);
	// push(&stack_a, &stack_b, &stack_a, &stack_b);
	// push(&stack_a, &stack_b, &stack_a, &stack_b);
	// swap(&stack_a, &stack_a, &stack_b);
	// push(&stack_b, &stack_a, &stack_a, &stack_b);
	// push(&stack_a, &stack_b, &stack_a, &stack_b);
	// rotate(&stack_a, &stack_a, &stack_b);
	// reverse_rotate(&stack_a, &stack_a, &stack_b);
	// rotate(&stack_b, &stack_a, &stack_b);
	// reverse_rotate(&stack_b, &stack_a, &stack_b);
