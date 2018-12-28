/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands_and_labels.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:53:36 by bdomansk          #+#    #+#             */
/*   Updated: 2018/11/24 17:53:38 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ignore_comment(char *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i] && s[i] != COMMENT_CHAR && s[i] != SECOND_COMMENT_CHAR)
		i++;
	if (s[i])
		s[i] = '\0';
}

int			is_empty_line(char *s, int *i)
{
	while (s[*i] && (s[*i] == ' ' || s[*i] == '\t'))
		(*i)++;
	if (s[*i])
		return (0);
	return (1);
}

int			is_contains_command(char *s, int i)
{
	if (is_contains_label(s, i))
	{
		while (s[i] != LABEL_CHAR)
			i++;
		i++;
	}
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (find_opcode(s, i))
		return (1);
	return (0);
}

static void	add_command(t_asm *info, int i)
{
	t_command *new;

	new = new_command(info);
	if (is_contains_label(info->line, i))
		add_labels(info, new, &i);
}

void		temp_function(t_asm *info)
{
	t_command	*start;
	t_label		*begin;

	printf("\n________________________________________________\n");
	start = info->command;
	while (info->command)
	{
		begin = info->command->label;
		if (info->command->label)
		{
			printf("\n:::::::::::::::::::::::::::::\n");
			while (info->command->label)
			{
				printf("%s\n", info->command->label->name);
				info->command->label = info->command->label->next;
			}
			printf(":::::::::::::::::::::::::::::\n");
		}
		info->command->label = begin;
		info->command = info->command->next;
	}
	info->command = start;
	printf("\n________________________________________________\n");
}

void		check_commands_and_labels(t_asm *info)
{
	int	i;

	while (get_next_line(info->fd, &info->line))
	{
		i = 0;
		info->num_line++;
		ignore_comment(info->line);
		if (!is_empty_line(info->line, &i))
		{
			if (is_contains_label(info->line, i) ||
				is_contains_command(info->line, i))
				add_command(info, i);
			else
				error_reason(info, "Wrong line without label or command");
		}
		ft_strdel(&info->line);
	}
	ft_strdel(&info->line);
	temp_function(info); // Эту функцию потом нужно удалить
}
