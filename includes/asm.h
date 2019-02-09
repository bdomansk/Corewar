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
# include "op.h"

# define FLAG_STRING	0
# define FLAG_VALUE		1

typedef struct	s_operations
{
	char	*name;
	int		opcode;
	int		number_args;
	int		type_args[3];
	int		dir_size;
	int		code_type;
}				t_operations;

static t_operations g_operations[17] = {
	{"live", 1, 1, {T_DIR, 0, 0}, 4, 0},
	{"ld", 2, 2, {T_DIR | T_IND, T_REG, 0}, 4, 1},
	{"st", 3, 2, {T_REG, T_IND | T_REG, 0}, 4, 1},
	{"add", 4, 3, {T_REG, T_REG, T_REG}, 4, 1},
	{"sub", 5, 3, {T_REG, T_REG, T_REG}, 4, 1},
	{"and", 6, 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 4, 1},
	{"or", 7, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 4, 1},
	{"xor", 8, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 4, 1},
	{"zjmp", 9, 1, {T_DIR, 0, 0}, 2, 0},
	{"ldi", 10, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 2, 1},
	{"sti", 11, 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 2, 1},
	{"fork", 12, 1, {T_DIR, 0, 0}, 2, 0},
	{"lld", 13, 2, {T_DIR | T_IND, T_REG, 0}, 4, 1},
	{"lldi", 14, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 2, 1},
	{"lfork", 15, 1, {T_DIR, 0, 0}, 2, 0},
	{"aff", 16, 1, {T_REG, 0, 0}, 4, 1},
	{NULL, 0, 0, {0, 0, 0}, 0, 0}
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

typedef struct	s_label
{
	char				*name;
	struct s_label		*next;
}				t_label;

typedef struct	s_arg
{
	char				*content;
	int					value;
	int					type;
	int					flag;
	int					size;
}				t_arg;

typedef struct	s_command
{
	char				*name;
	char				**args;
	int					opcode;
	t_label				*label;
	t_arg				arg[3];
	int					argument_type_code;
	int					size;
	int					size_before;
	struct s_command	*next;
}				t_command;

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
	int				new_fd;
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
int				is_contains_label(char *s, int i);
int				is_contains_command(char *s, int i);
int				find_opcode(char *s, int start);
void			add_labels(t_asm *info, t_command *new, int *i);

t_command		*new_command(t_asm *info);
void			parse_command(t_asm *info, t_command *cmd, int *i);
int				get_type(char *s);
void			analyze_arguments(t_command *cmd);

int				array_len(char **array);
int				character_count(char c, char *s);
void			trim_arguments(char **array);

void			check_end_of_file(t_asm *info);

void			operations_coding(t_asm *info);
void			analyze_labels(t_asm *info);
void			print_bytecode(t_asm *info);
unsigned int	reverse(unsigned int value, int size);

void			check_binary_file(t_asm *info);
void			read_champion_code(t_asm *info);
void			get_arg_by_type(t_asm *info, t_command *cmd, int i, int type);
void			create_file(t_asm *info);
void			print_champion_file(t_asm *info);

void			bonuses(t_asm *info);

#endif
