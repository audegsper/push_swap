/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:00:37 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/20 04:58:31 by dohykim          ###   ########.fr       */
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

int				ft_atoi(const char *str)
{
	int					sign;
	long long			num;

	sign = 1;
	num = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
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

// int	ft_atoi(const char *str)
// {
// 	long	nbr;
// 	long	sign;
// 	size_t	i;

// 	nbr = 0;
// 	sign = 1;
// 	i = 0;
// 	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
// 		str++;
// 	if (str[i] == '-')
// 		sign = -1;
// 	if ((str[i] == '-') || (str[i] == '+'))
// 		i++;
// 	while (str[i] != '\0')
// 	{
// 		if (!(*str >= '0' && *str <= '9'))
// 			check_error(NULL);
// 		nbr = (nbr * 10) + (str[i] - '0');
// 		if (nbr > 2147483647 && sign == 1)
// 			check_error(NULL);
// 		if (nbr > 2147483648 && sign == -1)
// 			check_error(NULL);
// 		i++;
// 	}
// 	return (sign * nbr);
// }

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

t_node	*node_init(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->index = -1;
	new_node->keep_stack = FALSE;
	return (new_node);
}

void	init_all(t_stack *stack, t_cmd_lst *cmd_lst)
{
	if (stack != NULL)
	{
		stack->top = NULL;
		stack->set_idx = NULL;
		stack->bottom = NULL;
		stack->markup_head = NULL;
		stack->pairs = 0;
		stack->size = 0;
	}
	if (cmd_lst != NULL)
	{
		cmd_lst->size = 0;
		cmd_lst->head = NULL;
	}
}
