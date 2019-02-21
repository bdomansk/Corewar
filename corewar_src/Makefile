# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 11:55:49 by bdomansk          #+#    #+#              #
#    Updated: 2018/04/23 11:55:51 by bdomansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../corewar
LIB = ../libft/libft.a
LIBDIR = ../libft
FLAGS = -Wall -Wextra -Werror 
COREWAR_SRC = main.c init_info.c put_manual.c error.c parse_arguments.c \
		bonuses.c is_natural.c check_bot.c reverse.c define_bots_id.c \
		fill_map.c new_carriage.c visualization_init.c draw_map.c
COREWAR_OBJ = $(COREWAR_SRC:.c=.o)
HEADER = -I ../includes
HEADER += -I ../frameworks/SDL2.framework/Headers/
HEADER += -I ../frameworks/SDL2_mixer.framework/Headers/ -F ../frameworks
FRAMEWORKS = -framework SDL2
FRAMEWORKS += -F  ../frameworks
FRAMEWORKS += -framework SDL2_mixer 
DEL = /bin/rm -f

.PHONY : all clean n fclean re

all : $(NAME)

$(NAME) : $(LIB) $(COREWAR_OBJ) 
	@echo "Compiling corewar"
	@gcc $(FLAGS) $(COREWAR_OBJ) -o $(NAME) -lncurses $(LIB) $(FRAMEWORKS) -rpath frameworks

$(COREWAR_OBJ): $(COREWAR_SRC)
	@echo "Corewar objects creating"
	@gcc $(FLAGS) -c $(COREWAR_SRC) $(HEADER) 

$(LIB) :
	@make -C $(LIBDIR)

clean:
	@$(DEL) $(COREWAR_OBJ)

n :
	@norminette $(COREWAR_SRC) 

fclean:
	@$(DEL) $(COREWAR_OBJ)
	@$(DEL) $(NAME)
	
re: fclean all