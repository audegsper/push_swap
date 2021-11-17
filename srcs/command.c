/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:59:16 by dohykim           #+#    #+#             */
/*   Updated: 2021/11/17 03:48:58 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	free_command(t_cmd_lst *lst)
{
	t_command *tmp;
	t_command *current;

	current = lst->head;
	while (current)
	{
		tmp = current;
		current = current -> next;
		free(tmp->name);
		free(tmp);
	}
	free(lst);
}

void	init_cmd_lst(t_cmd_lst *cmd_lst)
{
	cmd_lst->size = 0;
	cmd_lst->head = NULL;
}

char	*ft_strdup(const char *s1)
{
	int i;
	char*dest;

	i = 0;
	while (s1[i])
		i++;
	if (!(dest = malloc(sizeof(*s1) * (i + 1))))
		return (0);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	dest[i] = '\0';
	return (dest);
}


t_command	*create_command(char *str)
{
	t_command *cmd;

	if (!(cmd = (t_command *)malloc(sizeof(t_command))))
		return (NULL);
	cmd->name = NULL;
	cmd->next = NULL;
	if (!(cmd->name = ft_strdup(str)))
	{
		free(cmd);
		return (NULL);
	}
	return (cmd);
}

void	add_command(t_cmd_lst *lst, t_command *cmd)
{
	t_command *last;

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
	t_command *current;
	int i;
	char *str;

	current = lst->head;
	str = (char *)malloc(sizeof(char));
	while(current)
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
