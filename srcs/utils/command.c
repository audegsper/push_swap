/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:59:16 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/18 06:33:07 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_command	*create_command(char *str)
{
	t_command	*cmd;

	cmd = (t_command *)malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd->name = str;
	cmd->next = NULL;
	return (cmd);
}

void	add_command(t_cmd_lst *lst, t_command *cmd)
{
	t_command	*last;

	if (lst && cmd)
	{
		if (!lst->head)
			lst->head = cmd;
		else
		{
			last = lst->head;
			while (last->next)
				last = last->next;
			last->next = cmd;
		}
		lst->size++;
	}
}

void	print_command(t_cmd_lst *lst)
{
	t_command	*current;
	int			i;
	char		*str;

	current = lst->head;
	str = (char *)malloc(sizeof(char));
	while (current)
	{
		i = 0;
		*str = current->name[i];
		while (*str != 0)
		{
			write(1, str, 1);
			i++;
			*str = current->name[i];
		}
		current = current->next;
	}
	free(str);
}
