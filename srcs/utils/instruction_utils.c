/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 02:48:37 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/17 03:54:51 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	try_rr(t_stack *a, t_stack *b, char *name, t_cmd_lst *lst)
{
	rotate(a);
	rotate(b);
	if (name && lst)
		add_command(lst, create_command(name));
	return (1);
}

int	try_rrr(t_stack *a, t_stack *b, char *name, t_cmd_lst *lst)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (name && lst)
		add_command(lst, create_command(name));
	return (1);
}

int	try_rotate(t_stack *stk, char *name, t_cmd_lst *lst)
{
	rotate(stk);
	if (name && lst)
		add_command(lst, create_command(name));
	return (1);
}

int	try_reverse_rotate(t_stack *stk, char *name, t_cmd_lst *lst)
{
	reverse_rotate(stk);
	if (name && lst)
		add_command(lst, create_command(name));
	return (1);
}
