/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:00:37 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/17 07:06:38 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_max(size_t a, size_t b)
{
	return (a > b ? a : b);
}

t_bool	check_error(t_node *node)
{
	t_node	*new;
	t_bool	err_num;

	err_num = TRUE;
	if (node != NULL)
	{
		err_num = FALSE;
		new = node->prev;
		while (node != new)
		{
			if (new->value == node->value)
				err_num = TRUE;
			node = node->next;
		}
	}
	if (err_num == TRUE)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	nbr;
	long	sign;
	size_t	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		str++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
			check_error(NULL);
		nbr = (nbr * 10) + (str[i] - '0');
		if (nbr > 2147483647 && sign == 1)
			check_error(NULL);
		if (nbr > 2147483648 && sign == -1)
			check_error(NULL);
		i++;
	}
	return (sign * nbr);
}

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->set_idx = NULL;
	stack->bottom = NULL;
	stack->markup_head = NULL;
	stack->pairs = 0;
	stack->size = 0;
}

t_node	*node_init(int value)
{
	t_node *new_node;
	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->index = -1;
	new_node->keep_stack = FALSE;
	return (new_node);
}


void	free_stack(t_stack *stack)
{
	t_node	*tmp;
	size_t	i;

	i = 0;
	while (i++ < stack->size)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	stack->size = 0;
	free(stack);
}

