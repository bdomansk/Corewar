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

typedef struct	s_asm
{
	t_flags			*flags;
	unsigned int	magic;
	unsigned int	prog_size;
	char			champion_name[PROG_NAME_LENGTH + 1];
	char			champion_comment[COMMENT_LENGTH + 1];
	char			*error_reason;
	char			*file_name;
	char			*new_file_name;
	char			*line;
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

void			bonuses(t_asm *info);

#endif
