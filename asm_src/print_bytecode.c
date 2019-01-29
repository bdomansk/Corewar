/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bytecode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:58:56 by bdomansk          #+#    #+#             */
/*   Updated: 2019/01/29 12:58:58 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			create_file(t_asm *info)
{
	char *error;
	char *s;

	info->new_fd = open(info->new_file_name, O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (info->new_fd == -1)
	{
		s = "Can't create file with name : ";
		error = ft_strjoin(s, info->new_file_name);
		error_reason(info, error);
	}
}

static unsigned int	reverse(unsigned int value, int size)
{
	unsigned int	reversed;
	unsigned char	*n1;
	unsigned char	*n2;

	n1 = (unsigned char *)&value;
	n2 = (unsigned char *)&reversed;
	if (size == 1)
		return (value);
	if (size == 4)
	{
		n2[0] = n1[3];
		n2[1] = n1[2];
		n2[2] = n1[1];
		n2[3] = n1[0];
	}
	else
	{
		n2[0] = n1[1];
		n2[1] = n1[0];
	}
	return (reversed);
}

static void			print_info(t_asm *info)
{
	write(info->new_fd, &info->magic, 4);
	write(info->new_fd, info->champion_name, PROG_NAME_LENGTH);
	write(info->new_fd, "\0\0\0\0", 4);
	write(info->new_fd, &info->prog_size, 4);
	write(info->new_fd, info->champion_comment, COMMENT_LENGTH);
	write(info->new_fd, "\0\0\0\0", 4);
}

static void			print_cmd(t_command *cmd, int fd)
{
	int i;

	i = 0;
	write(fd, &cmd->opcode, 1);
	if (cmd->argument_type_code)
		write(fd, &cmd->argument_type_code, 1);
	while (i < g_operations[cmd->opcode - 1].number_args)
	{
		cmd->arg[i].value = reverse(cmd->arg[i].value, cmd->arg[i].size);
		write(fd, &cmd->arg[i].value, cmd->arg[i].size);
		i++;
	}
}

void				print_bytecode(t_asm *info)
{
	t_command *start;

	create_file(info);
	info->magic = reverse(info->magic, 4);
	info->prog_size = reverse(info->prog_size, 4);
	print_info(info);
	start = info->command;
	while (info->command)
	{
		if (info->command->name)
			print_cmd(info->command, info->new_fd);
		info->command = info->command->next;
	}
	info->command = start;
	close(info->new_fd);
}
