# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles <rteles@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 19:55:47 by amaria-m          #+#    #+#              #
#    Updated: 2022/10/19 20:51:25 by rteles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ORANGE = \033[0;33m
RED = \033[0;31m
PURPLE = \033[1;35m
CYAN = \033[3;36m
ORANG2 = \033[2;33m
GREY1 = \033[1;30m
GREY2 = \033[2;37m
WHITE = \033[0;37m
GREEN = \033[2;32m
OTHER = \033[9;34m

CC			= 	gcc -g
CFLAGS		= 	-Wall -Wextra -Werror
RM			= 	/bin/rm -f
NAME		= 	cub3D

INCLUDES	= 	./hdr

SRCS		= 	$(shell find src/ -name '*.c')
OBJS		= 	$(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -Imlx_linux -I$(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -I$(INCLUDES) $(OBJS) -Imlx_linux -o $(NAME)
	@echo "\
	$(OTHER)***********************************\n\
	**$(ORANGE)           $(GREEN)ψ $(ORANGE)Cub3D $(GREEN)ψ           \
	$(ORANGE)$(OTHER)**\n\
	$(OTHER)***********************************\n$(GREY1)$(OTHER)\
	**$(RED)$(GREY1)            ____         ____  $(OTHER)**\n\
	**$(RED)$(GREY1)  |      | |    | |     |      $(OTHER)**\n\
	**$(RED)$(GREY1)  |      | |    | |     |___   $(OTHER)**\n\
	**$(RED)$(GREY1)  |  /\  | |    | |     |      $(OTHER)**\n\
	**$(RED)$(GREY1)  |_/  \_| |____| |____ |      $(OTHER)**\n\
	**$(RED)       ____  ____  _______     $(GREY1)$(OTHER)**\n\
	$(RED)$(OTHER)**$(RED)      |     |    |    |        $(OTHER)**\n\
	**$(RED)      |__   |____|    |        $(OTHER)**\n\
	**$(RED)      |     |    |    |        $(OTHER)**\n\
	**$(RED)      |____ |    |    |        $(OTHER)**\n$(PURPLE)$(OTHER)\
	**$(RED)$(PURPLE)      ___     ____     __      $(OTHER)**\n\
	**$(RED)$(PURPLE)     |   | * /    \ | |  \     $(OTHER)**\n\
	**$(RED)$(PURPLE)     |___| | | ___    \__      $(OTHER)**\n\
	**$(RED)$(PURPLE)     |     | |    |      |     $(OTHER)**\n\
	**$(RED)$(PURPLE)     |     | \____|   \__/     $(OTHER)**\n\
	**$(RED)$(PURPLE)                               $(OTHER)**\n\
	$(ORANGE)$(OTHER)***********************************\n\
	**$(ORANGE)  $(GREEN)ψ $(ORANGE)rteles $(GREEN)ψ     \
	ψ $(ORANGE)amaria-m $(GREEN)ψ$(ORANGE)  $(OTHER)**\n\
	***********************************$(WHITE)"

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)REMOVED OBJECT FILES\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)REMOVED EXECUTABLE\033[0m"

re: fclean all

norm :
	@norminette -R CheckForbiddenSourceHeader $(SRCS)

mc:
	@make && make clean && clear

e:
	@make re && make clean && clear && ./$(NAME) ex.cub

v:
	@make re && make clean && clear && valgrind ./$(NAME) ex.cub

.PHONY: all re clean fclean norm e v
