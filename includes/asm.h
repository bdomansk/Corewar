/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:45:25 by bdomansk          #+#    #+#             */
/*   Updated: 2018/10/30 17:45:36 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h> // потом убрать
# include "op.h"

typedef struct	s_operations
{
	char	*name;
	int		opcode;
}				t_operations;

static t_operations g_operations[17] = {
{"live", 1},
{"ld", 2},
{"st", 3},
{"add", 4},
{"sub", 5},
{"and", 6},
{"or", 7},
{"xor", 8},
{"zjmp", 9},
{"ldi", 10},
{"sti", 11},
{"fork", 12},
{"lld", 13},
{"lldi", 14},
{"lfork", 15},
{"aff", 16},
{NULL, 0}
};

typedef struct	s_flags
{
	int	h;
	int l;
	int	c;
	int d;
	int	m;
	int	i;
	int	n;
	int exists;
}				t_flags;

typedef struct			s_label
{
	char				*name;
	struct s_label		*next;
}						t_label;

typedef struct			s_command
{
	char				*name;
	int					opcode;
	t_label 			*label;
	struct s_command	*next;
}						t_command;

typedef struct	s_asm
{
	t_flags			*flags;
	t_command		*command;
	unsigned int	magic;
	unsigned int	prog_size;
	char			champion_name[PROG_NAME_LENGTH + 1];
	char			champion_comment[COMMENT_LENGTH + 1];
	char			*error_reason;
	char			*file_name;
	char			*new_file_name;
	char			*line;
	char			*last_line;
	int				fd;
	int				num_line;
}				t_asm;



t_asm			*init_info(int argc, char **argv);

void			put_manual(t_asm *info);
void			error_reason(t_asm *info, char *reason);
void			error(t_asm *info);

void			check_file_name(t_asm *info);
void			check_name_and_comment(t_asm *info);
void			get_champion_name(t_asm *info, int *flag_name);
void			get_champion_comment(t_asm *info, int *flag_comment);

void			check_commands_and_labels(t_asm *info);
void			ignore_comment(char *s);
int				is_empty_line(char *s, int *i);
int 			is_contains_label(char *s, int i);
int 			is_contains_command(char *s, int i);
int				find_opcode(char *s, int start);
t_command		*new_command(t_asm *info);
void			add_labels(t_asm *info, t_command *new, int *i);

void			check_end_of_file(t_asm *info);

void			bonuses(t_asm *info);

#endif
