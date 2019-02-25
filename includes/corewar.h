/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:32:46 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/12 10:32:57 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "../libft/libft.h"
# include "SDL.h"
# include "SDL_mixer.h"
# include <ncurses.h>
# include <fcntl.h>
# include "op_corewar.h"
# include <stdio.h> //потом убрать

# define MUS_PATH "music/starwars.mp3"

typedef struct	s_flags
{
	int	h;
	int l;
	int	c;
	int v;
	int	m;
	int	s;
	int	n;
	int	dump;
	int	dump_value;
}				t_flags;

typedef struct	s_bot
{
	int				id;
	unsigned int	prog_size;
	unsigned char	*exec_code;
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
}				t_bot;

typedef struct	s_map
{
	unsigned char	cell;
	int				color;
}				t_map;

typedef struct	s_carriage
{
	int					id;
	int					carry;
	int					alive;
	int					position;
	int					exec_cmd;
	int					cycles_left;
	t_bot				parent;
	unsigned int		register_id[REG_NUMBER + 1];
	struct s_carriage	*next;
}				t_carriage;

typedef struct	s_vm
{
	WINDOW			*w;
	WINDOW			*info;
	Mix_Music		*music;
	t_flags			*flags;
	t_bot			bot[4];
	t_map			map[MEM_SIZE];
	t_carriage		*carriage;
	int				music_init;
	int				x;
	int				y;
	int				argc;
	int				fd;
	int				delay;
	int				cycles;
	int				current_cycle;
	int				running;
	int				number_of_bots;
	int				num_of_carriages;
	int				detalization_level;
	int				cycle_check;
	int				cycle_to_die;
	int				number_of_lives;
	int				number_of_checks;
	int				available_id[5];
	char			**argv;
	char			*error_reason;
}				t_vm;

t_vm			*init_info(int argc, char **argv);
void			put_manual(t_vm *info);
void			error(t_vm *info);
void			error_reason(t_vm *info, char *reason);
void			bonuses(t_vm *info);

void			parse_arguments(t_vm *info);
int				is_natural(char *s);
void			check_bot(t_vm *info, int *i);
unsigned int	reverse(unsigned int value, int size);

void			define_bots_id(t_vm *info);
void			fill_map(t_vm *info);

void			new_carriage(t_vm *info, t_bot parent, int position);
void			free_carriage(t_vm *info, int id);

void			visualization_init(t_vm *vm);
void			close_visulization(t_vm *vm);
int				check_key(int ch, t_vm *vm);
void			draw_map(t_vm *vm);
void			draw_info_table(t_vm *vm);
void			sdl_mixer_init(t_vm *vm);
void			npause(t_vm *vm);

void			introducing_contestants(t_vm *vm);
void			print_map(t_vm *vm);

void			perform_carriages(t_vm *vm);
void			check_carriages(t_vm *vm);

#endif
