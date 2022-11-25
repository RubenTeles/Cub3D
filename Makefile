# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 19:55:47 by amaria-m          #+#    #+#              #
#    Updated: 2022/11/21 16:37:11 by amaria-m         ###   ########.fr        #
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
OTHE2 = \033[4;34m
R1 = \033[2;31m

CC			= 	gcc -g
CFLAGS		= 	-Wall -Wextra -Werror
RM			= 	/bin/rm -f
NAME		= 	cub3D

INCLUDES	= 	./hdr

SRCS		= 	$(shell find src/ -name '*.c')
OBJS		= 	$(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -I$(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -I$(INCLUDES) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "\
	$(OTHER)**********************************************************\
	************************\n\
	**$(ORANGE)                                 $(GREEN)ψ $(ORANGE)Cub\
	3D $(GREEN)ψ                                    $(ORANGE)$(OTHER)*\
	*\n\
	$(OTHER)**********************************************************\
	************************\n$(GREY2)$(OTHER)\
	**$(RED)$(GREY2)                     $(OTHER)**$(RED)\
	$(GREY2)            ____         ____  $(OTHER)**$(RED)\
	$(PURPLE)                      $(OTHER)**\n\
	**$(RED)$(GREY2)                     $(OTHER)**$(RED)\
	$(GREY2)  |      | |    | |     |      $(OTHER)**$(RED)\
	$(PURPLE)                      $(OTHER)**\n\
	**$(RED)$(GREY2)                     $(OTHER)**$(RED)\
	$(GREY2)  |      | |    | |     |___   $(OTHER)**$(RED)\
	$(PURPLE)                      $(OTHER)**\n\
	**$(RED)$(GREY2)      /\             $(OTHER)**$(RED)\
	$(GREY2)  |  /\  | |    | |     |      $(OTHER)**$(RED)\
	$(PURPLE)                      $(OTHER)**\n\
	**$(RED)$(GREY2)     /$(PURPLE)/|$(GREY2)|    ___     $(OTHER)\
	**$(RED)$(GREY2)  |_/  \_| |____| |____ |      $(OTHER)\
	**$(RED)$(PURPLE)                      $(OTHER)**\n\
	**$(RED)$(GREY2)    /$(PURPLE)/_|$(GREY2)|___/\_/|    $(OTHER)\
	**$(RED)       ____  ____  _______     $(GREY2)$(OTHER)\
	**$(RED)$(PURPLE)   ___  ______  ___   $(OTHER)**\n\
	**$(RED)$(GREY2)    | ___   ___ |    $(OTHER)\
	**$(RED)$(OTHER)$(RED)      |     |    |    |        $(GREY2)$(OTHER)\
	**$(RED)$(PURPLE)   |  \/      \/  |   $(OTHER)**\n\
	**$(RED)$(GREY2)    / ($(RED)Φ$(GREY2))   ($(RED)Φ$(GREY2)) \    $(OTHER)\
	**$(RED)      |__   |____|    |        $(GREY2)$(OTHER)\
	**$(RED)$(PURPLE)    \ ___     ___ /   $(OTHER)**\n\
	**$(RED)$(GREY2)   <   ̅      ̅    >   $(OTHER)\
	**$(RED)      |     |    |    |        $(GREY2)$(OTHER)\
	**$(RED)$(PURPLE)    / $(ORANG2)$(PURPLE)($(ORANG2)Θ$(PURPLE))$(RED)\
	$(PURPLE) __  $(ORANG2)$(PURPLE)($(ORANG2)Θ$(PURPLE))$(RED)\
	$(PURPLE) \   $(OTHER)**\n\
	**$(RED)$(GREY2)   << \      / >>    $(OTHER)\
	**$(RED)      |____ |    |    |        $(GREY2)$(OTHER)**$(RED)\
	$(PURPLE)   |   ̅  |$(OTHE2)$(PURPLE)oo$(RED)$(PURPLE)|  ̅   |   $(OTHER)\
	**\n\
	**$(RED)$(GREY2)     \ \_$(PURPLE)<>$(GREY2)_/ /      $(OTHER)$(PURPLE)\
	$(OTHER)**$(RED)$(PURPLE)      ___     ____     __      $(OTHER)**$(RED)\
	$(PURPLE)   |              |   $(OTHER)**\n\
	**$(RED)$(GREY2)      \_$(WHITE)\/\/$(GREY2)_/       $(OTHER)**$(RED)\
	$(PURPLE)     |   | O /    \ | |  \     $(OTHER)**$(RED)$(PURPLE)    \_\
	___________/    $(OTHER)**\n\
	**$(RED)$(GREY2)                     $(OTHER)\
	**$(RED)$(PURPLE)     |___| | | ___    \__      $(OTHER)\
	**$(RED)$(PURPLE)                      $(OTHER)**\n\
	**$(RED)$(GREY2)                     $(OTHER)**$(RED)\
	$(PURPLE)     |     | |    |      |     $(OTHER)**$(RED)\
	$(PURPLE)                      $(OTHER)**\n\
	**$(RED)$(GREY2)                     $(OTHER)**$(RED)\
	$(PURPLE)     |     | \____|   \__/     $(OTHER)\
	**$(RED)$(PURPLE)                      $(OTHER)**\n\
	**$(RED)$(GREY2)                     $(OTHER)**$(RED)\
	$(PURPLE)                               $(OTHER)**$(RED)\
	$(PURPLE)                      $(OTHER)**\n\
	$(ORANGE)$(OTHER)********************************************************\
	**************************\n\
	**$(ORANGE)     $(GREEN)ψ $(ORANGE)rteles $(GREEN)ψ      $(ORANGE)\
	$(OTHER)**$(ORANGE)           42 LISBON           $(OTHER)\
	**$(ORANGE)     $(GREEN)ψ $(ORANGE)amaria-m $(GREEN)ψ\
	$(ORANGE)     $(OTHER)**\n\
	************************************************************************\
	**********$(WHITE)"

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)REMOVED OBJECT FILES\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)REMOVED EXECUTABLE\033[0m"

re: fclean all

norm :
	@norminette -R CheckForbiddenSourceHeader $(SRCS)

mc:	all clean
	@clear

e:	all clean
	@clear && ./$(NAME) ex.cub

v:	all song clean
	@clear && valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) ex.cub

song:
	@paplay src/music/pMLWWiBvWX8_48.ogg

.PHONY: all clean fclean re norm mc e v song
