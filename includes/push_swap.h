/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:15:56 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/18 06:55:08 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node			t_node;
typedef struct s_stack			t_stack;
typedef struct s_command		t_command;
typedef struct s_cmd_lst		t_cmd_lst;
typedef struct s_shift_info		t_shift_info;
typedef int						t_bool;
# define FALSE 0
# define TRUE 1
# define R	4
# define RR 5

struct	s_node
{
	int		value;
	int		index;
	t_bool	keep_stack;
	t_node	*prev;
	t_node	*next;
};

struct	s_stack
{
	t_node	*set_idx;
	t_node	*top;
	t_node	*bottom;
	size_t	size;
	size_t	pairs;
	t_node	*markup_head;
};

struct			s_command
{
	char				*name;
	struct s_command	*next;
};

struct			s_cmd_lst
{
	size_t				size;
	t_command			*head;
};

struct	s_shift_info
{
	t_node	*a_node;
	t_node	*b_node;
	int		a_direction;
	int		b_direction;
	size_t	size;
	t_bool	is_set;
};



void	init_all(t_stack *stack, t_cmd_lst *cmd_lst);
void	set_arg(t_stack *stack, int arg_num);
int		ft_atoi(const char *str);
void	free_stack(t_stack *stack);
void	print(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);
void	swap(t_stack *stk);
void	rotate(t_stack *stk);
void	reverse_rotate(t_stack *stack);
void	ft_solve(t_stack *a_stack, t_cmd_lst	*cmd_lst);
void	ft_index_stack(t_stack *stack);
void	opt_markup_stack(t_stack *stack);
void	init_cmd_lst(t_cmd_lst *cmd_lst);
t_node	*node_init(int value);
void	print_command(t_cmd_lst *lst);
t_command	*create_command(char *str);
void	add_command(t_cmd_lst *lst, t_command *cmd);
void	free_command(t_cmd_lst *lst);
void	try_sa(t_stack *stack, char *name, t_cmd_lst *lst);
void	try_rr(t_stack *a, t_stack *b, char *name, t_cmd_lst *lst);
void	try_rrr(t_stack *a, t_stack *b, char *name, t_cmd_lst *lst);
void	try_rotate(t_stack *stk, char *name, t_cmd_lst *lst);
void	try_reverse_rotate(t_stack *stk, char *name, t_cmd_lst *lst);
size_t	ft_markup_stack_index(t_stack *stack, t_node *markup_head);
void	solve_a(t_stack *a_stk, t_stack *b_stk, t_cmd_lst *cmd_lst);
void	solve_b(t_stack *a_stack, t_stack *b_stack, t_cmd_lst *cmd_lst);
void	opt_direction(t_stack *a_stack, t_stack *b_stack, t_shift_info *t_shift_info);
size_t	ft_max(size_t a, size_t b);
t_bool	check_error(t_stack *stack);
void	align_a(t_stack *a_stack, t_cmd_lst *cmd_lst);
#endif
