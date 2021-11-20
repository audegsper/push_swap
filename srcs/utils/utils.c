/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:00:37 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/20 19:10:13 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_max(size_t a, size_t b)
{
	size_t	rtn;

	if (a > b)
		rtn = a;
	else
		rtn = b;
	return (rtn);
}

int	ft_atoi(const char *str)
{
	int					sign;
	long long			num;

	sign = 1;
	num = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
		if (*str == '\0')
			check_error(NULL);
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			check_error(NULL);
		num *= 10;
		num += (*(str++) - '0');
	}
	num = num * sign;
	if (num > 2147483647)
		check_error(NULL);
	if (num < -2147483648)
		check_error(NULL);
	return (num);
}

t_bool	check_error(t_stack *stack)
{
	t_node	*new;
	t_node	*node;
	t_bool	err_num;

	err_num = TRUE;
	if (stack != NULL)
	{
		if (stack->size == 1)
			exit(0);
		node = stack->top;
		err_num = FALSE;
		new = node->prev;
		while (node != new)
		{
			if (new->value == node->value)
				err_num = TRUE;
			node = node->next;
		}
	}
	if (err_num == TRUE && write(2, "Error\n", 6))
		exit(1);
	else
		return (0);
}
